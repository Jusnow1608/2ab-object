#include "DateHelper.h"

string formatDate(int year, int month, int day) {
    stringstream ss;
    ss << year << "-";
    if (month < 10) ss << "0";
    ss << month << "-";
    if (day < 10) ss << "0";
    ss << day;
    string str = ss.str();
    return str;
}

bool isLeapYear(int year) {
    bool przestepny = false;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        przestepny = true;
    return przestepny;
}

string getTodayDate() {
    time_t teraz = time(0);
    tm data = *localtime(&teraz);

    int rok = data.tm_year + 1900;
    int miesiac = data.tm_mon + 1;
    int dzien = data.tm_mday;

    string dataDzisiejsza = formatDate(rok, miesiac, dzien);
    return dataDzisiejsza;
}

int getDaysInMonth(int rok, int miesiac) {
    int dniWMiesiacu;

    if (miesiac == 2) {
        bool przestepny = isLeapYear(rok);
        if (przestepny == true) {
            dniWMiesiacu = 29;
        } else {
            dniWMiesiacu = 28;
        }
    } else if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) {
        dniWMiesiacu = 30;
    } else {
        dniWMiesiacu = 31;
    }
    return dniWMiesiacu;
}

int getDaysInCurrentMonth() {
    time_t teraz = time(0);
    tm data = *localtime(&teraz);

    int rok = data.tm_year + 1900;
    int miesiac = data.tm_mon + 1;

    int dniWMiesiacu = getDaysInMonth(rok, miesiac);

    return dniWMiesiacu;
}


string getPreviousMonthDate() {
    time_t teraz = time(0);
    tm data = *localtime(&teraz);

    data.tm_mon = data.tm_mon - 1;    // cofamy miesiąc o 1
    mktime(&data);

    int rok = data.tm_year + 1900;
    int miesiac = data.tm_mon + 1;
    int dzien = data.tm_mday;

    string dt;
    dt = formatDate(rok, miesiac, dzien);
    return dt;
}

string getFirstDayOfPreviousMonth() {
    time_t teraz = time(0);
    tm data = *localtime(&teraz);

    data.tm_mon = data.tm_mon - 1;
    data.tm_mday = 1;
    mktime(&data);

    int rok = data.tm_year + 1900;
    int miesiac = data.tm_mon + 1;
    int dzien = data.tm_mday;

    string dt;
    dt = formatDate(rok, miesiac, dzien);
    return dt;
}

string getLastDayOfPreviousMonth() {
    time_t teraz = time(0);
    tm data = *localtime(&teraz);

    data.tm_mday = 1;
    mktime(&data);

    data.tm_mday = data.tm_mday - 1;
    mktime(&data);

    int rok = data.tm_year + 1900;
    int miesiac = data.tm_mon + 1;
    int dzien = data.tm_mday;

    string dt = formatDate(rok, miesiac, dzien);
    return dt;
}

bool isInPreviousMonth(string data) {
    string pierwszyDzien = getFirstDayOfPreviousMonth();  // np. "2025-10-01"
    string ostatniDzien = getLastDayOfPreviousMonth();    // np. "2025-10-31"

    if (data >= pierwszyDzien && data <= ostatniDzien)
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

bool isDateBefore(string d1, string d2) {
    int y1, m1, d_1;
    int y2, m2, d_2;

    char dash; // do wczytania znaków '-' między liczbami

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


bool isDateValid(string data) {
    if (data.length() != 10)
        return false;
    if (data[4] != '-' || data[7] != '-')
        return false;

    int rok = stoi(data.substr(0, 4));
    int miesiac = stoi(data.substr(5, 2));
    int dzien = stoi(data.substr(8, 2));

    if (rok < 2000 || rok > 9999)
        return false;

    if (miesiac < 1 || miesiac > 12)
        return false;

    int dniWMiesiacu = getDaysInMonth(rok, miesiac);

    if (dzien < 1 || dzien > dniWMiesiacu)
        return false;

    return true;
}


