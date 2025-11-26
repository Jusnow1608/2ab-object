#include "AuxiliaryMethods.h"

string AuxiliaryMethods::readLine()
{
    string input = "";
    getline(cin,input);
    return input;
}

char AuxiliaryMethods::readChar()
{
    string input = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "It is not a single sign. Provide again." << endl;
    }
    return sign;
}
//    bool validateInput(string input);
