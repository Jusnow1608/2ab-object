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

