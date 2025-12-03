#include "BudgetMainApp.h"

void BudgetMainApp::registerUser() {
    userManager.registerUser();
}

void BudgetMainApp::loginUser() {
    userManager.loginUser();
    if (isUserLoggedIn()) {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedInUserId());
    }
}

void BudgetMainApp::changeLoggedInUserPassword() {
    userManager.changeLoggedInUserPassword();
}

void BudgetMainApp::logoutUser() {
    userManager.logoutUser();
}

void BudgetMainApp::addIncome() {
    budgetManager->addOperation(Type::INCOME);
}

bool BudgetMainApp::isUserLoggedIn() {
    return userManager.isUserLoggedIn();
}

void BudgetMainApp::addExpense() {
    budgetManager->addOperation(Type::EXPENSE);
}

void BudgetMainApp::displayCurrentMonthBalance() {
    budgetManager->displayCurrentMonthBalance();
}

void BudgetMainApp::displayPreviousMonthBalance() {
    budgetManager->displayPreviousMonthBalance();
}

void BudgetMainApp::displaySelectedPeriodBalance() {
    budgetManager->displaySelectedPeriodBalance();
}

char BudgetMainApp::getMainMenuSelection() {
    char choice;

    system("cls");
    cout << "                      >>> MAIN MENU <<<                      " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "0. Exit" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

    while (choice != '1' && choice != '2' && choice != '0') {
        cout << "Invalid option. Please try again: ";
        choice = AuxiliaryMethods::readChar();
    }
    return choice;
}
char BudgetMainApp::getUserMenuSelection() {
    char choice;

    system("cls");
    cout << "                      >>> USER MENU <<<                      " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display current month balance" << endl;
    cout << "4. Display previous month balance" << endl;
    cout << "5. Display balance for selected period" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Logout" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::readChar();

   while (!(choice >= '0' && choice <= '7')) {
        cout << "Invalid option. Please try again: ";
        choice = AuxiliaryMethods::readChar();
    }
    return choice;
}



