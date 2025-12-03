#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "OperationFile.h"
#include "Operation.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"
#include "CashMethods.h"
#include "Type.h"


using namespace std;

class BudgetManager {
    OperationFile incomeFile;
    OperationFile expenseFile;
    int LOGGED_IN_USER_ID;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation getNewOperationDetails(const Type &type);
    void displayOperations(const vector<Operation> &operations, const string &title);
    double calculateOperationsSum(const vector<Operation> &operations);
    void sortOperationsByDate(vector<Operation> &operations);
    void displayBalance(int startDate, int endDate);
    void processOperation(vector<Operation> &operations, OperationFile &file, const Operation &operation, const string &successMsg, const string &errorMsg);
    double displayBalanceForType(int startDate, int endDate, const Type &type);
    const vector<Operation>& getOperationsByType(const Type &type) const;
    vector<Operation> filterOperationsByDate(const vector<Operation> &operations, int startDate, int endDate);

public:
    BudgetManager(const string &incomeFileName,const string &expenseFileName, int loggedInUserId)
        : incomeFile(incomeFileName, Type::INCOME), expenseFile(expenseFileName, Type::EXPENSE),LOGGED_IN_USER_ID(loggedInUserId) {
        incomeFile.loadOperationsFromFile(incomes, LOGGED_IN_USER_ID);
        expenseFile.loadOperationsFromFile(expenses, LOGGED_IN_USER_ID);
    }

    void addOperation(const Type &type);
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
};
#endif
