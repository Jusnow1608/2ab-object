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
    cout<<"Does this income apply to today? (y/n): ";
    string choice = AuxiliaryMethods::readLine();

    if (choice == "y"|| choice =="Y")

        operation.date = DateMethods::getTodayDate();
    else {
        string dateString;
        do {
            dateString =  readNewValue("Please provide date (YYYY-MM-DD): ");
            if(!DateMethods::isDateValid(dateString)) {
                cout<<"Invalid date format. Please try again." << endl;
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

        int dateInt = DateMethods::formatStringDateToInt(dateString);
        operation.date = dateInt;
    }

    operation.item = readNewValue("Please provide income description: ");
    string amountString = readNewValue("Please provide amount (use dot or comma): ");
    for (char &comma: amountString) {
        if (comma == ',') comma = '.';
    }
    operation.amount = stod(amountString);

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
