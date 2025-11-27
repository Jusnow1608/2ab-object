#include "BudgetManager.h"

#include <iostream>

void BudgetManager::addIncome() {
    Operation income;
    system("cls");
    cout << " >>> ADD INCOME <<<" << endl << endl;
    cout << "-----------------------------------------------" << endl;
    income = getNewOperationDetails();
    incomes.push_back(income);
    if(operationFile.addOperationToFile(income)) {
        cout << "New income has been added." << endl;
        displayOperationData(income);
    }

    else
        cout << "Error. Failed to add new income." << endl;
    system("pause");
}

Operation BudgetManager::getNewOperationDetails() {
    Operation operation;

    operation.id = operationFile.getLastOperationId()+1;
    operation.userId = LOGGED_IN_USER_ID;

    operation.date = readNewValue("Please provide date (YYYY-MM-DD): ");
    operation.item = readNewValue("Please provide item/description: ");
    string amountStr = readNewValue("Please provide amount: ");
    operation.amount = stod(amountStr);

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
