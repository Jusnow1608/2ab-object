#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include <string>

#include "UserManager.h"
#include "BudgetManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetMainApp {
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

public:
    BudgetMainApp (const string &userFileName, const string &incomeFileName, const string &expenseFileName):
        userManager (userFileName),INCOME_FILE_NAME (incomeFileName), EXPENSE_FILE_NAME (expenseFileName)  {
        budgetManager = NULL;
    };

    ~BudgetMainApp() {
        delete budgetManager;
        budgetManager = NULL;
    }

    void registerUser();
    void loginUser();
    void changeLoggedInUserPassword();
    void logoutUser();
    void addIncome();
    bool isUserLoggedIn();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
    char getMainMenuSelection();
    char getUserMenuSelection();
};
#endif
