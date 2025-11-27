#include "BudgetMainApp.h"

void BudgetMainApp::registerUser()
{
    userManager.registerUser();
}

void BudgetMainApp::displayAllUsers()
{
    userManager.displayAllUsers();
}

void BudgetMainApp::loginUser()
{
    userManager.loginUser();
    if (userManager.isUserLoggedIn())
    {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, userManager.getLoggedInUserId());
    }
}

void BudgetMainApp::changeLoggedInUserPassword()
{
    userManager.changeLoggedInUserPassword();
}

void BudgetMainApp::logoutUser()
{
    userManager.logoutUser();
}

void BudgetMainApp::addIncome()
{
    budgetManager->addIncome();
}

