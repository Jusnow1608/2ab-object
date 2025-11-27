#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

class DateMethods {
    static bool isLeapYear(int year);

public:
    static bool isDateValid(const string &date);
    static string getCurrentDate();
    /*static string getPreviousMonthFirstDay();
    static string getPreviousMonthLastDay();
    static string getCurrentMonthFirstDay();

    static int formatStringDateToInt (string date);
    static string formatIntDateToString(int year, int month, int day);


    static int getDaysInMonth(int rok, int miesiac);
    static int getDaysInCurrentMonth();
    static string getPreviousMonthDate();
    static bool isDateEarlier(const string d1, const string d2);

    static bool isInPreviousMonth(const string date);
    static bool isDateBefore(const string d1, const string d2);
    */
};

#endif
