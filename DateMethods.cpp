#include "DateMethods.h"

tm DateMethods::getNow() {
    time_t now = time(nullptr);
    tm currentDate = *localtime(&now);
    return currentDate;
}

string DateMethods::formatIntDateToString(int year, int month, int day) {
    stringstream ss;
    ss << year << "-";
    if (month < 10) ss << "0";
    ss << month << "-";
    if (day < 10) ss << "0";
    ss << day;
    return ss.str();
}

int DateMethods::formatStringDateToInt(const string& date) {
    // Sprawdzenie dlugosci i separatorów
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        throw invalid_argument("Invalid date format. Expected YYYY-MM-DD.");
    }

    string year = date.substr(0, 4);
    string month = date.substr(5, 2);
    string day = date.substr(8, 2);

    string intDate = year + month + day;
    // Konwersja na int
    return stoi(intDate);
}
string DateMethods::tmToString(const tm& date) {
    int year = date.tm_year + 1900;
    int month = date.tm_mon + 1;
    int day = date.tm_mday;
    return formatIntDateToString(year, month, day);
}

int DateMethods::tmToInt(const tm& date) {
    string stringDate = tmToString(date);
    int intDate = formatStringDateToInt(stringDate);
    return intDate;
}

bool DateMethods::isLeapYear(int year) {
    bool leapYear = false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        leapYear = true;
    return leapYear;
}

int DateMethods::getCurrentDate() {
    tm now = getNow();
    int todayIntDate = tmToInt(now);
    return todayIntDate;
}


int DateMethods::getDaysInMonth(int year, int month) {
    int daysInMonth;

    if (month == 2) {
        bool leapYear = isLeapYear(year);
        if (leapYear == true) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else {
        daysInMonth = 31;
    }
    return daysInMonth;
}

int DateMethods::getDaysInCurrentMonth() {
    tm now = getNow();
    int year = now.tm_year + 1900;
    int month = now.tm_mon + 1;
    int daysInCurrentMonth = getDaysInMonth(year, month);
    return daysInCurrentMonth;
}


string DateMethods::getPreviousMonthDate() {
    tm date = getNow();
    date.tm_mon -= 1;
    mktime(&date);
    string dt = tmToString(date);
    return dt;
}


string DateMethods::getPreviousMonthFirstDay() {
    tm date = getNow();
    date.tm_mon -= 1;
    date.tm_mday = 1;
    mktime(&date);
    string dt = tmToString(date);
    return dt;
}

string DateMethods::getPreviousMonthLastDay() {
    tm date = getNow();
    date.tm_mday = 1;
    mktime(&date);
    date.tm_mday = 0; // dzień 0 = ostatni dzień poprzedniego miesiąca
    mktime(&date);
    string dt = tmToString(date);
    return dt;
}


string DateMethods::getCurrentMonthLastDay() {
    tm date = getNow();
    date.tm_mon += 1;
    date.tm_mday = 0;
    mktime(&date);
    string dt = tmToString(date);
    return dt;
}


bool DateMethods::isInPreviousMonth(const string &date) {
    string pierwszyDzien = getPreviousMonthFirstDay();  // np. "2025-10-01"
    string ostatniDzien = getPreviousMonthLastDay();    // np. "2025-10-31"

    if (date >= pierwszyDzien && date <= ostatniDzien)
        return true;
    else
        return false;
}

bool isDateEarlier(string dataPierwsza, string dataDruga) {
    if (dataPierwsza < dataDruga)
        return true;
    else
        return false;
}

bool DateMethods::isDateBefore(const string& d1, const string& d2) {
    int intDate1 = formatStringDateToInt(d1);
    int intDate2 = formatStringDateToInt(d2);
    bool result = (intDate1 < intDate2);
    return result;
}


bool DateMethods::isDateValid(const string &date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    if (year < 2000 || year > 9999) return false;
    if (month < 1 || month > 12) return false;

    int daysInMonth = getDaysInMonth(year, month);
    if (day < 1 || day > daysInMonth) return false;

    return true;
}

bool DateMethods::isDateInRange(const string &date) {
    int dateInt = formatStringDateToInt(date);
    int minDateInt = 20000101;
    int maxDateInt = formatStringDateToInt(getCurrentMonthLastDay());
    bool result = (dateInt >= minDateInt && dateInt <= maxDateInt);
    return result;
}


