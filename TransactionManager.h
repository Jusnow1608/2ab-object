#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <vector>
#include <string>
#include "Transaction.h"

using namespace std;

class TransactionManager {
private:
    vector<Transaction> transactions;
    string fileName;

public:
    TransactionManager(const string& xmlFileName)
        : fileName(xmlFileName) {}

    void addTransaction(const Transaction& transaction);
    void saveTransactionToFile(const Transaction& transaction, const string& filename);
    void loadTransactionsFromFile();
    void displayAllTransactions() const;
    void displayTransactionsByDate(const string& datePrefix) const;
    void displayTransactionsByAmount(double threshold, const string& condition) const;

};

#endif
