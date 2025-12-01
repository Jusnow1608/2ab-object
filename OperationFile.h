#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include "Type.h"
#include "File.h"
#include "Operation.h"

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class OperationFile: public File {
    string incomeFileName;
    string expenseFileName;

public:
    OperationFile(const string& incomeFileName)
        : File(incomeFileName) {}

    bool addOperationToFile(const Operation &operation);
    int getLastOperationId() const;
    void loadOperationsFromFile();
};

#endif
/*
    void saveTransactionToFile(const Transaction& transaction, const string& filename);
    void displayAllTransactions() const;
    void displayTransactionsByDate(const string& datePrefix) const;
    void displayTransactionsByAmount(double threshold, const string& condition) const

+ getTransactionsForLoggedInUser(): vector <Operation>

*/

