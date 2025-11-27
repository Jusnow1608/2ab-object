#include "DateMethods.h"


string DateMethods::formatIntDateToString(int year, int month, int day) {
    stringstream ss;
    ss << year << "-";
    if (month < 10) ss << "0";
    ss << month << "-";
    if (day < 10) ss << "0";
    ss << day;
    string stringDate = ss.str();
    return stringDate;
}

int DateMethods::formatStringDateToInt(const string& stringDate) {
    // Sprawdzenie d³ugoœci i separatorów
    if (stringDate.size() != 10 || stringDate[4] != '-' || stringDate[7] != '-') {
        throw invalid_argument("Invalid date format. Expected YYYY-MM-DD.");
    }

    // Wyci¹gniêcie fragmentów
    string year = stringDate.substr(0, 4);
    string month = stringDate.substr(5, 2);
    string day = stringDate.substr(8, 2);

    // Po³¹czenie w jeden string
    string intDate = year + month + day;

    // Konwersja na int
    return stoi(intDate);
}


bool DateMethods::isLeapYear(int year) {
    bool leapYear = false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        leapYear = true;
    return leapYear;
}

int DateMethods::getTodayDate() {
    time_t now = time(0);
    tm date = *localtime(&now);

    int year = date.tm_year + 1900;
    int month = date.tm_mon + 1;
    int day = date.tm_mday;

    string todayStringDate = formatIntDateToString(year, month, day);
    int todayIntDate = formatStringDateToInt (todayStringDate);
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
    time_t now = time(0);
    tm date = *localtime(&now);

    int year = date.tm_year + 1900;
    int month = date.tm_mon + 1;

    int daysInCurrentMonth = getDaysInMonth(year, month);

    return daysInCurrentMonth;
}


string DateMethods::getPreviousMonthDate() {
    time_t teraz = time(0);
    tm data = *localtime(&teraz);

    data.tm_mon = data.tm_mon - 1;    // cofamy miesi¹c o 1
    mktime(&data);

    int rok = data.tm_year + 1900;
    int miesiac = data.tm_mon + 1;
    int dzien = data.tm_mday;

    string dt;
    dt = formatIntDateToString(rok, miesiac, dzien);
    return dt;
}

string DateMethods::getPreviousMonthFirstDay() {
    time_t teraz = time(0);
    tm data = *localtime(&teraz);

    data.tm_mon = data.tm_mon - 1;
    data.tm_mday = 1;
    mktime(&data);

    int rok = data.tm_year + 1900;
    int miesiac = data.tm_mon + 1;
    int dzien = data.tm_mday;

    string dt;
    dt = formatIntDateToString(rok, miesiac, dzien);
    return dt;
}

string DateMethods::getPreviousMonthLastDay() {
    time_t teraz = time(0);
    tm data = *localtime(&teraz);

    data.tm_mday = 1;
    mktime(&data);

    data.tm_mday = data.tm_mday - 1;
    mktime(&data);

    int rok = data.tm_year + 1900;
    int miesiac = data.tm_mon + 1;
    int dzien = data.tm_mday;

    string dt = formatIntDateToString(rok, miesiac, dzien);
    return dt;
}

bool DateMethods::isInPreviousMonth(const string date) {
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

bool DateMethods::isDateBefore(string d1, string d2) {
    int y1, m1, d_1;
    int y2, m2, d_2;

    char dash; // do wczytania znaków '-' miêdzy liczbami

    stringstream ss1(d1);
    ss1 >> y1 >> dash >> m1 >> dash >> d_1;

    stringstream ss2(d2);
    ss2 >> y2 >> dash >> m2 >> dash >> d_2;

    tm a = {}, b = {};
    a.tm_year = y1 - 1900;
    a.tm_mon = m1 - 1;
    a.tm_mday = d_1;

    b.tm_year = y2 - 1900;
    b.tm_mon = m2 - 1;
    b.tm_mday = d_2;

    time_t t1 = mktime(&a);
    time_t t2 = mktime(&b);
    if (t1 < t2)
        return true;
    else
        return false;
}


bool DateMethods::isDateValid(const string &date) {
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));

    if (year < 2000 || year > 9999)
        return false;

    if (month < 1 || month > 12)
        return false;

    int daysInMonth = getDaysInMonth(year, month);

    if (day < 1 || day > daysInMonth)
        return false;

    return true;
}


