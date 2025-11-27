#ifndef OPERATION_H
#define OPERATION_H

#include "Type.h"

#include <string>

using namespace std;

struct Operation {
    int id;
    int userId;
    int date;
    string item;
    float amount;
    Type type = Type::INCOME;

    Operation(): id(0) {}

    Operation(int id_, int userId_, const int& date_, const string& item_, float amount_)
        : id(id_), userId(userId_), date(date_), item(item_), amount(amount_) {}

};

#endif
