#include "AuxiliaryMethods.h"

string AuxiliaryMethods::readLine() {
    string input = "";
    getline(cin,input);
    return input;
}

char AuxiliaryMethods::readChar() {
    string input = "";
    char sign  = '\0';

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "It is not a single sign. Please try again: ";
    }
    return sign;
}

string AuxiliaryMethods::readNewValue(const string &message) {
    string value;
    do {
        cout << message;
        value = readLine();
        if(value.empty())
            cout << "Value cannot be empty. " << endl;
    } while (value.empty());
    return value;
}


string AuxiliaryMethods::typeToString(const Type &type) {
    if (type == Type::INCOME)
        return "INCOME";
    return "EXPENSE";
}

