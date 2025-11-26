#include "BudgetManager.h"
#include "Markup.h"
#include <iostream>


void TransactionManager::addTransaction(const Transaction& transaction) {
    CMarkup xml;

    if (!xml.Load(fileName)) {
        xml.AddElem("transactions");
    }

    xml.FindElem("transactions");
    xml.IntoElem();

    xml.AddElem("transaction");
    xml.IntoElem();
    xml.AddElem("date", transaction.date);
    xml.AddElem("amount", to_string(transaction.amount));
    xml.OutOfElem();

    xml.Save(fileName);
    transactions.push_back(transaction);
}

void TransactionManager::saveTransactionToFile(const Transaction& transaction, const string& filename) {
    CMarkup xml;

    if (!xml.Load(filename)) {
        xml.AddElem("transactions");
    }

    xml.FindElem("transactions");
    xml.IntoElem();

    xml.AddElem("transaction");
    xml.IntoElem();
    xml.AddElem("date", transaction.date);
    xml.AddElem("amount", to_string(transaction.amount));
    xml.OutOfElem();

    xml.Save(filename);
}


void TransactionManager::loadTransactionsFromFile() {
    transactions.clear();
    CMarkup xml;

    if (!xml.Load(fileName)) {
        cerr << "Nie uda³o siê wczytaæ pliku XML\n";
        return;
    }

    xml.FindElem("transactions");
    xml.IntoElem();

    while (xml.FindElem("transaction")) {
        xml.IntoElem();

        xml.FindElem("date");
        string date = xml.GetData();

        xml.FindElem("amount");
        double amount = stod(xml.GetData());

        transactions.emplace_back(date, amount);

        xml.OutOfElem();
    }
}

void TransactionManager::displayAllTransactions() const {
    for (const auto& t : transactions) {
        cout << "Data: " << t.date << ", Kwota: " << t.amount << '\n';
    }
}

void TransactionManager::displayTransactionsByDate(const string& datePrefix) const {
    bool found = false;
    for (const auto& t : transactions) {
        if (t.date.rfind(datePrefix, 0) == 0) { // zaczyna siê od datePrefix
            cout << "Data: " << t.date << ", Kwota: " << t.amount << '\n';
            found = true;
        }
    }
    if (!found) {
        cout << "Brak transakcji dla daty: " << datePrefix << '\n';
    }
}

void TransactionManager::displayTransactionsByAmount(double threshold, const string& condition) const {
    bool found = false;

    for (const auto& t : transactions) {
        bool match = false;

        if (condition == "greater") {
            match = t.amount > threshold;
        } else if (condition == "less") {
            match = t.amount < threshold;
        } else if (condition == "equal") {
            match = t.amount == threshold;
        }

        if (match) {
            cout << "Data: " << t.date << ", Kwota: " << t.amount << '\n';
            found = true;
        }
    }

    if (!found) {
        cout << "Brak transakcji spelniajacych warunek kwoty: " << condition << " " << threshold << '\n';
    }
}
