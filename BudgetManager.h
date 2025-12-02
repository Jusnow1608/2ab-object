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
    int LOGGED_IN_USER_ID;
    OperationFile incomeFile;
    OperationFile expenseFile;
    vector <Operation> incomes;
    vector <Operation> expenses;

    Operation getNewOperationDetails(const Type &type);
    string readNewValue(const string &message);
    void displayOperations(const vector<Operation> &operations, const string &title);
    void displayOperationData(const Operation & operation);
    string typeToString(const Type &type);
    double calculateOperationsSum(const vector<Operation> &operations);
    void sortOperationsByDate(vector<Operation> &operations);
    void displayBalance(int startDate, int endDate);
    void displayOperation(const Operation & operation);
    void processOperation(vector<Operation> &operations, OperationFile &file, const Operation &operation, const string &successMsg, const string &errorMsg);
    double calculateBalance(int startDate, int endDate);
    double calculateBalanceForType(int startDate, int endDate, const Type &type);
    double displayBalanceForType(int startDate, int endDate, const Type &type);

string readValidDate(const string &message);
const vector<Operation>& getOperationsByType(const Type &type) const;
vector<Operation> filterOperationsByDate(const vector<Operation> &operations, int startDate, int endDate);
public:
    BudgetManager(const string &incomeFileName,const string &expenseFileName, int loggedInUserId)
        : incomeFile(incomeFileName, Type::INCOME), expenseFile(expenseFileName, Type::EXPENSE),LOGGED_IN_USER_ID(loggedInUserId) {
        incomeFile.loadOperationsFromFile(incomes);
        expenseFile.loadOperationsFromFile(expenses);

    }

    void addOperation(const Type &type);
    void displayAllOperations();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();
};
#endif
