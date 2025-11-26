#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <vector>
#include <string>
#include "Operation.h"

using namespace std;

class BudgetManager {
private:
    int LOGGED_IN_USER_ID;
    vector <Expense> expenses;
    vector <Income> incomes;
    OperationFile expenseFile;
    OperationFile incomeFile;
    string fileName;

    Operation getNewOperationDetails(const Type &type);
    //void displayBalance(int startDate, int endDate);
    //double calculateBalance(int startDate, int endDate, const Type &type);

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId)
        : fileName(xmlFileName) {}

        void addIncome();

    /*PlikZAdresatami(string nazwaPliku, string nazwaTymczasowegoPlikuZAdresatami):
        PlikTekstowy (nazwaPliku), NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI (nazwaTymczasowegoPlikuZAdresatami), idOstatniegoAdresata(pobierzZPlikuIdOstatniegoAdresata())
        {
        }*/

    /*void  addExpense() ;
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
    };

    /*
    --
    - expenseFileName: string
    - incomeFileName: string
    + displayAllOperations(): void
    + displayOperationsByDate(): void
    + displayOperationsByAmount(): void

    - displayOperationData(): void
    - sumOperations(): void
    - sortByDateAscending(): void
    */
#endif
