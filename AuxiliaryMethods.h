#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <string>
#include <iostream>

#include "Type.h"

using namespace std;

class AuxiliaryMethods
{
public:
    static string readLine();

    static char readChar();
    static bool validateInput(string &input);
    static string readNewValue(const string &message);
    static string typeToString(const Type &type);

};

#endif
