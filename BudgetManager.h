#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <vector>
#include <string>

#include "OperationFile.h"
#include "Operation.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"


using namespace std;

class BudgetManager {
    int LOGGED_IN_USER_ID;
    OperationFile operationFile;
    vector <Operation> incomes;
    //vector <Operation> expenses;

    Operation getNewOperationDetails();
    string readNewValue(const string &message);
    void displayOperationData(Operation & operation);
    //void displayBalance(int startDate, int endDate);
    //double calculateBalance(int startDate, int endDate, const Type &type);

public:
    BudgetManager(const string &incomesFile, int loggedInUserId)
        : operationFile(incomesFile), LOGGED_IN_USER_ID(loggedInUserId) {}

    void addIncome();
};

/*PlikZAdresatami(string nazwaPliku, string nazwaTymczasowegoPlikuZAdresatami):
    PlikTekstowy (nazwaPliku), NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI (nazwaTymczasowegoPlikuZAdresatami), idOstatniegoAdresata(pobierzZPlikuIdOstatniegoAdresata())
    {
    }*/

/*void  addExpense() ;
void displayCurrentMonthBalance();
void displayPreviousMonthBalance();
void displaySelectedPeriodBalance();
};
- expenseFileName: string
- incomeFileName: string
+ displayAllOperations(): void
+ displayOperationsByDate(): void
+ displayOperationsByAmount(): void


- sumOperations(): void
- sortByDateAscending(): void
*/
#endif
