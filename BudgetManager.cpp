#include "BudgetManager.h"

#include <iostream>

void BudgetManager::addOperation(const Type &type) {
    system("cls");
    cout << " >>> ADD "<<typeToString(type) <<"<<<" << endl << endl;
    cout << "-----------------------------------------------" << endl;
    Operation operation = getNewOperationDetails(type);

    if (type == Type::INCOME) {
        incomes.push_back(operation);
        if(incomeFile.addOperationToFile(operation)) {
            cout << "New income has been added." << endl;
            displayOperationData(operation);
        } else
            cout << "Error. Failed to add new income." << endl;
        system("pause");
    }

    else {
        expenses.push_back(operation);
        if(expenseFile.addOperationToFile(operation)) {
            cout << "New expense has been added." << endl;
            displayOperationData(operation);
        } else
            cout << "Error. Failed to add new expense." << endl;
        system("pause");
    }
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
        string dateString;
        do {
            dateString =  readNewValue("Please provide date (YYYY-MM-DD): ");
            if(!DateMethods::isDateValid(dateString)) {
                cout<<"Invalid date format. " << endl;
                dateString.clear();
                continue;
            }
            if (!DateMethods::isDateInRange(dateString)) {
                string currentMonthLastDay = DateMethods::getCurrentMonthLastDay();
                cout <<"Date must be between 2000-01-01 and " + currentMonthLastDay + ".";
                dateString.clear();
                continue;
            }
        } while (dateString.empty());

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
    cout <<endl << "Id:        " << operation.id << endl;
    cout << "UserId:    " << operation.userId << endl;
    cout << "Date:      " << operation.date<< endl;
    cout << "Item:      " << operation.item << endl;
    cout << "Amount:    " << operation.amount << endl;

}

void BudgetManager::displayOperation(const Operation & operation) {
    cout <<endl << "Date:      " << operation.date<< ", Amount:    " << operation.amount << endl;
}

void BudgetManager::displayOperations(const vector<Operation> &operations, const string &title) {
    if (!operations.empty()) {
        cout << "             >>> " << title << " <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (size_t i=0; i<operations.size(); i++) {
            displayOperationData(operations[i]);
        }
        cout << endl;
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

void BudgetManager::displayBalance(int startDate, int endDate) {
    system("cls");
    sortOperationsByDate(incomes);
    sortOperationsByDate(expenses);

    vector <Operation> filteredIncomes;
    vector <Operation> filteredExpenses;

    for (size_t i = 0; i<incomes.size(); i++) {
        if (incomes[i].date>=startDate && incomes[i].date<=endDate) {
            filteredIncomes.push_back(incomes[i]);
        }
    }
    for (size_t i = 0; i<expenses.size(); i++) {
        if (expenses[i].date>=startDate && expenses[i].date<=endDate) {
            filteredExpenses.push_back(expenses[i]);
        }
    }

    displayOperations(filteredIncomes, "INCOMES");
    displayOperations(filteredExpenses, "EXPENSES");

    double sumIncomes = calculateOperationsSum(filteredIncomes);
    double sumExpenses = calculateOperationsSum(filteredExpenses);
    double balance = sumIncomes-sumExpenses;
    cout << "-----------------------------------------------" << endl;
    cout << "Total incomes:  " << sumIncomes << endl;
    cout << "Total expenses: " << sumExpenses << endl;

    if (balance >= 0)
        cout << "You saved:      " << balance << endl;
    else
        cout << "You are in debt: " << balance << endl;

    system("pause");

}

void BudgetManager::displayCurrentMonthBalance() {
    int startDate = DateMethods::formatStringDateToInt(DateMethods::getCurrentMonthFirstDay());
    int endDate   = DateMethods::formatStringDateToInt(DateMethods::getCurrentMonthLastDay());
    displayBalance(startDate, endDate);

}
void BudgetManager::displayPreviousMonthBalance() {
    int startDate = DateMethods::formatStringDateToInt(DateMethods::getPreviousMonthFirstDay());
    int endDate   = DateMethods::formatStringDateToInt(DateMethods::getPreviousMonthLastDay());
    displayBalance(startDate, endDate);
}


void BudgetManager::displaySelectedPeriodBalance() {
    string startDateString, endDateString;
    do {
        startDateString =  readNewValue("Please provide  start date (YYYY-MM-DD): ");
        if(!DateMethods::isDateValid(startDateString)) {
            cout<<"Invalid date format. " << endl;
            startDateString.clear();
            continue;
        }
        if (!DateMethods::isDateInRange(startDateString)) {
            string currentMonthLastDay = DateMethods::getCurrentMonthLastDay();
            cout <<"Date must be between 2000-01-01 and " + currentMonthLastDay + ".";
            startDateString.clear();
            continue;
        }
    } while (startDateString.empty());

    do {
        endDateString =  readNewValue("Please provide  end date (YYYY-MM-DD): ");
        if(!DateMethods::isDateValid(endDateString)) {
            cout<<"Invalid date format. " << endl;
            endDateString.clear();
            continue;
        }
        if (!DateMethods::isDateInRange(endDateString)) {
            string currentMonthLastDay = DateMethods::getCurrentMonthLastDay();
            cout <<"Date must be between 2000-01-01 and " + currentMonthLastDay + ".";
            endDateString.clear();
            continue;
        }
    } while (endDateString.empty());

    int startDate = DateMethods::formatStringDateToInt(startDateString);
    int endDate = DateMethods::formatStringDateToInt(endDateString);
    displayBalance(startDate, endDate);
}


