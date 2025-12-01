#include "CashMethods.h"

bool CashMethods::isAmountValid(const string &amount) {
    // próba konwersji na double
    istringstream iss(amount);
    double value;
    iss >> value;
    // sprawdzamy czy ca³oœæ zostala poprawnie sparsowana
    if (iss.fail() || !iss.eof()) {
        return false;
    }
    // dodatkowe warunki biznesowe (np. kwota > 0)
    if (value <= 0) {
        return false;
    }

    return true;
}
