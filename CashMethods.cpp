#include "CashMethods.h"

bool CashMethods::isAmountValid(const string &amount) {

    istringstream iss(amount);
    double value;
    iss >> value;
    if (iss.fail() || !iss.eof()) {
        return false;
    }
    if (value <= 0) {
        return false;
    }
    return true;
}
