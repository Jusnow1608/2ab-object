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
}

void BudgetMainApp::changeLoggedInUserPassword()
{
    userManager.changeLoggedInUserPassword();
}

void BudgetMainApp::logoutUser()
{
    userManager.logoutUser();
}

