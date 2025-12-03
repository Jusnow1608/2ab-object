#include "BudgetManager.h"

void BudgetManager::addOperation(const Type &type) {
    system("cls");
    cout << "                    >>> ADD "<<typeToString(type) <<" <<<    " << endl;
    cout << "-------------------------------------------------------------" << endl;

    Operation operation = getNewOperationDetails(type);

    if (type == Type::INCOME)
        processOperation(incomes, incomeFile, operation, "New income has been added.", "Error. Failed to add new income.");
    else
        processOperation(expenses, expenseFile, operation, "New expense has been added.", "Error. Failed to add new expense.");
}

void BudgetManager::processOperation(vector<Operation> &operations, OperationFile &file, const Operation &operation, const string &successMsg, const string &errorMsg) {
    operations.push_back(operation);
    if (file.addOperationToFile(operation)) {
        cout <<endl<< successMsg << endl;
        displayOperationData(operation);
    } else {
        cout <<endl<< errorMsg << endl;
    }
    system("pause");
}


Operation BudgetManager::getNewOperationDetails(const Type &type) {
    Operation operation;
    if (type == Type::INCOME)
        operation.id = incomeFile.getLastOperationId()+1;
    else
        operation.id = expenseFile.getLastOperationId()+1;
    operation.userId = LOGGED_IN_USER_ID;
    cout<<"Does this operation apply to today? (y/n): ";
    string choice = AuxiliaryMethods::readLine();

    if (choice == "y"|| choice =="Y")

        operation.date = DateMethods::getCurrentDate();
    else {
        string dateString = readValidDate("Please provide date (YYYY-MM-DD): ");

        operation.date = DateMethods::formatStringDateToInt(dateString);
    }

    operation.item = readNewValue("Please provide operation description: ");
    string amount;
    do {
        amount = readNewValue("Please provide amount (use dot or comma): ");
        for (char &comma: amount) {
            if (comma == ',') comma = '.';
        }
        if (!CashMethods::isAmountValid(amount)) {
            cout << "Invalid amount. " << endl;
            amount.clear();
        }
    } while (amount.empty());

    operation.amount = stod(amount);

    return operation;
}


string BudgetManager::readNewValue(const string &message) {
    string value;
    do {
        cout << message;
        value = AuxiliaryMethods::readLine();
        if(value.empty())
            cout << "Value cannot be empty. " << endl;
    } while (value.empty());
    return value;
}


void BudgetManager::displayOperationData(const Operation & operation) {
    cout <<endl<< left << setw(22) << "Date"
         << left << setw(13) << "Item"
         << right << setw(15) << "Amount" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << left << setw(22) << DateMethods::intDateToString(operation.date)
         << left << setw(13) << operation.item
         << right << setw(15) << fixed << setprecision(2) << operation.amount << endl;
    cout << "-------------------------------------------------------------" << endl << endl;
}


void BudgetManager::displayOperations(const vector<Operation> &operations, const string &title) {
    if (!operations.empty()) {
        cout << "                     >>> " << title << " <<<                 " << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << left << setw(12) << "Date"
             << setw(25) << "Item"
             << right << setw(10) << "Amount" << endl;
        cout << "-------------------------------------------------------------" << endl;

        for (size_t i = 0; i< operations.size(); i++) {
            cout << left << setw(12) << DateMethods::intDateToString(operations[i].date)
                 << setw(25) << operations[i].item
                 << right << setw(10) << fixed << setprecision(2) << operations[i].amount << endl;
        }

        cout << "-------------------------------------------------------------" << endl << endl;
    } else {
        cout << endl << "There is no " << title << " yet." << endl << endl;
    }

}


void BudgetManager::displayAllOperations() {
    system("cls");
    displayOperations(incomes, "INCOMES");
    displayOperations(expenses, "EXPENSES");
    system("pause");
}


string BudgetManager::typeToString(const Type &type) {
    if (type == Type::INCOME)
        return "INCOME";
    return "EXPENSE";
}


double BudgetManager::calculateOperationsSum(const vector<Operation> &operations) {
    double sum = 0.0;
    for (size_t i = 0; i < operations.size(); i++) {
        sum += operations[i].amount;
    }
    return sum;
}


void BudgetManager::sortOperationsByDate(vector<Operation> &operations) {
    sort(operations.begin(), operations.end(),
    [](const Operation &a, const Operation &b) {
        return a.date < b.date; // najstarsze pierwsze
    });
}
double BudgetManager::displayBalanceForType(int startDate, int endDate, const Type &type) {
    const vector<Operation> &operations = getOperationsByType(type);

    vector<Operation> sortedOperations = operations;
    sortOperationsByDate(sortedOperations);
    vector<Operation> filteredOperations = filterOperationsByDate(sortedOperations, startDate, endDate);

    displayOperations(filteredOperations, typeToString(type));

    return calculateOperationsSum(filteredOperations);
}


void BudgetManager::displayBalance(int startDate, int endDate) {
    double sumIncomes = displayBalanceForType(startDate, endDate, Type::INCOME);
    double sumExpenses = displayBalanceForType(startDate, endDate, Type::EXPENSE);
    double balance = sumIncomes - sumExpenses;

    cout << "                     >>> BALANCE <<<                         " << endl;
    cout << "-------------------------------------------------------------"  << endl;
    cout << "Total INCOME:  " << sumIncomes << endl;
    cout << "Total EXPENSE: " << sumExpenses << endl;
    cout << "Total BALANCE: " << balance << endl;
    system("pause");
}

double BudgetManager::calculateBalanceForType(int startDate, int endDate, const Type &type) {
    const vector<Operation> &source = getOperationsByType(type);
    vector<Operation> filtered = filterOperationsByDate(source, startDate, endDate);
    return calculateOperationsSum(filtered);
}

double BudgetManager::calculateBalance(int startDate, int endDate) {
    double sumIncomes  = calculateBalanceForType(startDate, endDate, Type::INCOME);
    double sumExpenses = calculateBalanceForType(startDate, endDate, Type::EXPENSE);
    return sumIncomes - sumExpenses;
}


const vector<Operation>& BudgetManager::getOperationsByType(const Type &type) const {
    if (type == Type::INCOME)
        return incomes;
    else
        return expenses;
}


vector<Operation> BudgetManager::filterOperationsByDate(const vector<Operation> &operations, int startDate, int endDate) {
    vector<Operation> filteredOperations;
    for (size_t i = 0; i<operations.size(); i++) {
        if (operations[i].date >= startDate && operations[i].date <= endDate)
            filteredOperations.push_back(operations[i]);
    }
    return filteredOperations;
}

void BudgetManager::displayCurrentMonthBalance() {
    system("cls");
    cout << "                >>> CURRENT MONTH BALANCE <<<                " << endl;
    cout << "-------------------------------------------------------------"  << endl<<endl;
    int startDate = DateMethods::formatStringDateToInt(DateMethods::getCurrentMonthFirstDay());
    int endDate   = DateMethods::formatStringDateToInt(DateMethods::getCurrentMonthLastDay());

    displayBalance(startDate, endDate);
}
void BudgetManager::displayPreviousMonthBalance() {
    system("cls");
    cout << "                >>> PREVIOUS MONTH BALANCE <<<               " << endl;
    cout << "-------------------------------------------------------------"  << endl<<endl;
    int startDate = DateMethods::formatStringDateToInt(DateMethods::getPreviousMonthFirstDay());
    int endDate   = DateMethods::formatStringDateToInt(DateMethods::getPreviousMonthLastDay());

    displayBalance(startDate, endDate);
}


void BudgetManager::displaySelectedPeriodBalance() {
    system("cls");
    cout << "              >>> BALANCE IN SELECTED PERIOD <<<             " << endl;
    cout << "-------------------------------------------------------------"  << endl;
    string startDateString = readValidDate("Please provide start date (YYYY-MM-DD): ");
    string endDateString   = readValidDate("Please provide end date (YYYY-MM-DD): ");

    int startDate = DateMethods::formatStringDateToInt(startDateString);
    int endDate = DateMethods::formatStringDateToInt(endDateString);

    displayBalance(startDate, endDate);
}


string BudgetManager::readValidDate(const string &message) {
    string dateString;
    do {
        dateString = readNewValue(message);
        if (!DateMethods::isDateValid(dateString)) {
            cout << "Invalid date format." << endl;
            dateString.clear();
            continue;
        }
        if (!DateMethods::isDateInRange(dateString)) {
            string currentMonthLastDay = DateMethods::getCurrentMonthLastDay();
            cout << "Date must be between 2000-01-01 and " + currentMonthLastDay + "." << endl;
            dateString.clear();
            continue;
        }
    } while (dateString.empty());
    return dateString;
}

