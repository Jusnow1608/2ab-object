#include "BudgetManager.h"

void BudgetManager::addOperation(const Type &type) {
    system("cls");
    cout << "                    >>> ADD "<<AuxiliaryMethods::typeToString(type) <<" <<<    " << endl;
    cout << "-------------------------------------------------------------" << endl;

    Operation operation = getNewOperationDetails(type);

    if (type == Type::INCOME)
        processOperation(incomes, incomeFile, operation, "New income has been successfully added.\n", "Error. Failed to add new income.\n");
    else
        processOperation(expenses, expenseFile, operation, "New expense has been successfully added.\n", "Error. Failed to add new expense.\n");
}

void BudgetManager::processOperation(vector<Operation> &operations, OperationFile &file, const Operation &operation, const string &successMsg, const string &errorMsg) {
    operations.push_back(operation);
    if (file.addOperationToFile(operation)) {
        cout <<endl<< successMsg << endl;
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
        string dateString = DateMethods::readValidDate("Please provide date (YYYY-MM-DD): ");

        operation.date = DateMethods::formatStringDateToInt(dateString);
    }

    operation.item = AuxiliaryMethods::readNewValue("Please provide operation description: ");
    string amount;
    do {
        amount = AuxiliaryMethods::readNewValue("Please provide amount (use dot or comma): ");
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


void BudgetManager::displayOperations(const vector<Operation> &operations, const string &title) {
    if (!operations.empty()) {
        cout << "                       >>> " << title << " <<<                       " << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << left << setw(22) << "Date"
             << setw(13) << "Item"
             << right << setw(15) << "Amount" << endl;
        cout << "-------------------------------------------------------------" << endl;

        for (size_t i = 0; i< operations.size(); i++) {
            cout << left << setw(22) << DateMethods::intDateToString(operations[i].date)
                 << setw(13) << operations[i].item
                 << right << setw(15) << fixed << setprecision(2) << operations[i].amount << endl;
        }
        cout << "-------------------------------------------------------------" << endl << endl;
    } else {
        cout << endl << "There is no " << title << " yet." << endl << endl;
    }

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

    displayOperations(filteredOperations, AuxiliaryMethods::typeToString(type));

    return calculateOperationsSum(filteredOperations);
}


void BudgetManager::displayBalance(int startDate, int endDate) {
    double sumIncomes = displayBalanceForType(startDate, endDate, Type::INCOME);
    double sumExpenses = displayBalanceForType(startDate, endDate, Type::EXPENSE);
    double balance = sumIncomes - sumExpenses;

    cout << "                       >>> BALANCE <<<                       " << endl;
    cout << "-------------------------------------------------------------"  << endl;
    cout << "TOTAL INCOME:  " << sumIncomes << endl;
    cout << "TOTAL EXPENSE: " << sumExpenses << endl;
    cout << "TOTAL BALANCE: " << balance << endl;
    system("pause");
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
    cout << "             >>> BALANCE FOR SELECTED PERIOD <<<             " << endl;
    cout << "-------------------------------------------------------------"  <<endl<< endl;
    string startDateString = DateMethods::readValidDate("Please provide start date (YYYY-MM-DD): ");
    string endDateString   = DateMethods::readValidDate("Please provide end date (YYYY-MM-DD): ");
    cout << endl;
    int startDate = DateMethods::formatStringDateToInt(startDateString);
    int endDate = DateMethods::formatStringDateToInt(endDateString);

    displayBalance(startDate, endDate);
}


