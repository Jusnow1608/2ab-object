#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

using namespace std;

class DateMethods {
    static bool isLeapYear(int year);

public:
    // Konwersje dat
    static string formatIntDateToString(int year, int month, int day);
    static int formatStringDateToInt(const string& stringDate);

    // Pomocnicze konwersje tm
    static string tmToString(const tm& date);
    static int tmToInt(const tm& date);

    // Pobieranie aktualnej daty
    static tm getNow();
    static int getCurrentDate();

    // Obsluga miesiecy i lat
    static int getDaysInMonth(int year, int month);
    static int getDaysInCurrentMonth();

    // Daty zwiazane z miesiacami
    static string getPreviousMonthDate();
    static string getPreviousMonthFirstDay();
    static string getPreviousMonthLastDay();
    static string getCurrentMonthLastDay();
    static string getCurrentMonthFirstDay();

    // Walidacja i porównania
    static bool isInPreviousMonth(const string& date);
    static bool isDateBefore(const string& d1, const string& d2);
    static bool isDateValid(const string& date);
    static bool isDateInRange(const string& date);

};

#endif
