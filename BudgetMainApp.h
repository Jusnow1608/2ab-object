#ifndef BUDGETMAINAPP_H
#define BUDGETMAINAPP_H

#include <string>

#include "UserManager.h"
//#include "BudgetManager.h"

using namespace std;

class BudgetMainApp {
    UserManager userManager;
    //BudgetManager *budgetManager;
    //const string INCOME_FILE_NAME;
    //const string EXPENSE_FILE_NAME;


public:
    BudgetMainApp (const string &userFileName): userManager (userFileName) {};

    /*
    BudgetMainApp(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami):
        uzytkownikMenadzer (nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI(nazwaTymczasowegoPlikuZAdresatami) {
        adresatMenadzer = NULL;
    }
    ~KsiazkaAdresowa() {
        delete adresatMenadzer;
        adresatMenadzer = NULL;
    }
    */
    void registerUser();
    void displayAllUsers();
    void loginUser();
    /*
    void changeLoggedInUserPassword();
    void displayAllIncomes();
    void displayAllExpenses();
    void logoutUser();
    bool isLoggedIn();
    char getMainMenuSelection();
    char getUserMenuSelection();
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
    */
};

#endif
