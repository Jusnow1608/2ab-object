#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

class OperationFile
{
 public:
     OperationFile(string fileName);

     bool addOperationToFile();
     void loadOperationsFromFile();
};

/*
void addTransaction(const Transaction& transaction);
    void saveTransactionToFile(const Transaction& transaction, const string& filename);
    void displayAllTransactions() const;
    void displayTransactionsByDate(const string& datePrefix) const;
    void displayTransactionsByAmount(double threshold, const string& condition) const

+ getTransactionsForLoggedInUser(): vector <Operation>
+ getLastTransactionId(): integer

- formatTransactionDataAsFileElement(): string
- parseTransactionFromXml(): Income
- saveTransactionToFile(): void
*/
