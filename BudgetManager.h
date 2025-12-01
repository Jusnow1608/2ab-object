#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <vector>
#include <string>

#include "OperationFile.h"
#include "Operation.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"
#include "CashMethods.h"
#include "Type.h"


using namespace std;

class BudgetManager {
    int LOGGED_IN_USER_ID;
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation getNewOperationDetails(const Type &type);
    string readNewValue(const string &message);
    void displayOperationData(Operation & operation);
    //void displayBalance(int startDate, int endDate);
    //double calculateBalance(int startDate, int endDate, const Type &type);

public:
    BudgetManager(const string &incomeFile,const string &expenseFile, int loggedInUserId)
        : incomeFile(incomeFile), expenseFile(expenseFile),LOGGED_IN_USER_ID(loggedInUserId) {}

    void addIncome();
    void addExpense();
    void displayAllOperations();
};


/*
void displayCurrentMonthBalance();
void displayPreviousMonthBalance();
void displaySelectedPeriodBalance();
};
- expenseFileName: string
- incomeFileName: string
+
+ displayOperationsByDate(): void
+ displayOperationsByAmount(): void


- sumOperations(): void
- sortByDateAscending(): void
*/
#endif
