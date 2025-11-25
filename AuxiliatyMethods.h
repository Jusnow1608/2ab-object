#ifndef AUXILIATYMETHODS_H
#define AUXILIATYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>


#include "User.h"

using namespace std;

class AuxiliatyMethods
{
public:
    static string readLine();
    static char readChar();
    bool validateInput(string input);

    /*
    static string capitalizeFirstLetter(string input);
    static char convertCommaToDot();
    static int readInteger();
    static string readNumber(string tekst, int pozycjaZnaku);
    static int convertStringToInt(string number);
    static string convertIntToString(int number);
    */

};

#endif
