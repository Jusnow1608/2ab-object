#include "BudgetMainApp.h"

void BudgetMainApp::registerUser() {
    userManager.registerUser();
}

void BudgetMainApp::displayAllUsers() {
    userManager.displayAllUsers();
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
    budgetManager->addIncome();
}

bool BudgetMainApp::isUserLoggedIn() {
    if (userManager.isUserLoggedIn())
        return true;
    else
        return false;
}

void BudgetMainApp::addExpense() {
    budgetManager->addExpense();
}

void BudgetMainApp::displayAllOperations()
{
  budgetManager->displayAllOperations();
}

