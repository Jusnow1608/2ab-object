#ifndef OPERATION_H
#define OPERATION_H

#include <string>

using namespace std;

class Transaction {
public:
    string date;
    double amount;

Transaction(const string& d, double a)
: date(d), amount(a) {}

};

#endif
