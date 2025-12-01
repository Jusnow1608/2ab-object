#include "BudgetManager.h"

#include <iostream>

void BudgetManager::addIncome() {
    Operation income;
    system("cls");
    cout << " >>> ADD INCOME <<<" << endl << endl;
    cout << "-----------------------------------------------" << endl;
    income = getNewOperationDetails(Type::INCOME);
    incomes.push_back(income);
    if(incomeFile.addOperationToFile(income)) {
        cout << "New income has been added." << endl;
        displayOperationData(income);
    }

    else
        cout << "Error. Failed to add new income." << endl;
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

void BudgetManager::displayOperationData(Operation & operation) {
    cout <<endl << "Id:        " << operation.id << endl;
    cout << "UserId:    " << operation.userId << endl;
    cout << "Date:      " << operation.date<< endl;
    cout << "Item:      " << operation.item << endl;
    cout << "Amount:    " << operation.amount << endl;

}

void BudgetManager::displayAllOperations() {
    system("cls");
    if (!incomes.empty()) {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (size_t i=0; i<incomes.size(); i++) {
            displayOperationData(incomes[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There is no incomes yet." << endl << endl;
    }
    if (!expenses.empty()) {
        cout << "             >>> EXPENSES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (size_t i=0; i<expenses.size(); i++) {
            displayOperationData(expenses[i]);
        }
        cout << endl;
    } else {
        cout << endl << "There is no expenses yet." << endl << endl;
    }
    system("pause");
}


void BudgetManager::addExpense() {
    Operation expense;
    system("cls");
    cout << " >>> ADD EXPENSE <<<" << endl << endl;
    cout << "-----------------------------------------------" << endl;
    expense = getNewOperationDetails(Type::EXPENSE);
    expenses.push_back(expense);
    if(expenseFile.addOperationToFile(expense)) {
        cout << "New expense has been added." << endl;
    displayOperationData(expense);
    } else
        cout << "Error. Failed to add new expense." << endl;
    system("pause");
}

