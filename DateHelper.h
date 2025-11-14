#ifndef DATEHELPER_H
#define DATEHELPER_H

#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

using namespace std;

string formatDate(int year, int month, int day);
bool isLeapYear(int year);
string getTodayDate();
int getDaysInMonth(int rok, int miesiac);
int getDaysInCurrentMonth();
string getPreviousMonthDate();
bool isDateEarlier(const string d1, const string d2);
string getFirstDayOfPreviousMonth();
string getLastDayOfPreviousMonth();
bool isInPreviousMonth(const string date);
bool isDateBefore(const string d1, const string d2);
bool isDateValid(const string date);

#endif
