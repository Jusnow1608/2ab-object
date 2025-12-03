#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

#include "AuxiliaryMethods.h"

using namespace std;

class DateMethods {
    static bool isLeapYear(int year);

public:

    static string formatIntDateToString(int year, int month, int day);
    static int formatStringDateToInt(const string& stringDate);
    static string intDateToString(int date);

    static string tmToString(const tm& date);
    static int tmToInt(const tm& date);

    static tm getNow();
    static int getCurrentDate();

    static int getDaysInMonth(int year, int month);
    static int getDaysInCurrentMonth();

    static string getPreviousMonthFirstDay();
    static string getPreviousMonthLastDay();
    static string getCurrentMonthLastDay();
    static string getCurrentMonthFirstDay();

    static bool isInPreviousMonth(const string& date);
    static bool isDateBefore(const string& d1, const string& d2);
    static bool isDateValid(const string& date);
    static bool isDateInRange(const string& date);
    static string readValidDate(const string &message);

};

#endif
