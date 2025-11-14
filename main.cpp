#include <iostream>
#include "Markup.h"
#include "Transaction.h"
#include "TransactionManager.h"
#include "DateHelper.h"


using namespace std;

int odczytDanychZPlikuXML_main() {
    CMarkup xml;
    if (!xml.Load("transactions.xml")) {
        cerr << "Nie udalo sie wczytac pliku XML\n";
        return 1;
    }

    xml.FindElem("transactions");
    xml.IntoElem();

    while (xml.FindElem("transaction")) {
        xml.IntoElem();

        xml.FindElem("date");
        string date = xml.GetData();

        xml.FindElem("amount");
        string amount = xml.GetData();

        cout << "Data: " << date << ", Kwota: " << amount << '\n';

        xml.OutOfElem();
    }

    return 0;
}
int dodawanieTransakcjiDoPlikuXML_main() {
    Transaction t1("2025-11-09", 250.00);
    TransactionManager manager("transactions.xml");

    manager.addTransaction(t1);

    manager.saveTransactionToFile(t1,"transactions1.xml");

    cout << "Zapisano transakcje do pliku XML.\n";
    return 0;
}


int dodanieTransakcjiZPoziomuMenadzera_main() {
    TransactionManager manager("transactions1.xml");

    manager.loadTransactionsFromFile();
    manager.displayAllTransactions();

    Transaction newT("2025-11-10", 99.99);
    manager.addTransaction(newT);

    cout << "Dodano nowa transakcje.\n";

    return 0;
}

int wyswietlanieTransakcjiPoDacie_main() {
    TransactionManager manager("transactions.xml");

    manager.loadTransactionsFromFile();

    cout << "Wszystkie transakcje:\n";
    manager.displayAllTransactions();

    cout << "\nTransakcje z 2025-11-08:\n";
    manager.displayTransactionsByDate("2025-11-08");

    return 0;
}


int wyswietlTransakcjePoKwocieIWarunku_main() {
    TransactionManager manager("transactions.xml");

    manager.loadTransactionsFromFile();

    cout << "\nTransakcje powyzej 100 zl:\n";
    manager.displayTransactionsByAmount(100.0, "greater");

    cout << "\nTransakcje rowne 67.89 zl:\n";
    manager.displayTransactionsByAmount(67.89, "equal");

    cout << "\nTransakcje ponizej 50 zl:\n";
    manager.displayTransactionsByAmount(50.0, "less");

    return 0;
}

int main() //dataDzisiejszaDniWMiesiacuRokPrzestepny
{

    string data1 = formatDate(2015, 8, 4);
    cout<<"Formatowanie daty z liczb: "<<data1<<endl;

    bool przestepny = isLeapYear(2025);
    cout<<"Czy rok jest przestepny? "<<przestepny<<endl;

    int ileDni = getDaysInMonth(2025, 2);
    cout<< "Ile dni bylo w lutym 2025 "<<ileDni<<endl;

    string data2 = getPreviousMonthDate();
    cout<<"Jaka data byla miesiac temu? "<<data2<<endl;


    bool czyOK = isDateValid("2025-10-32");
    cout<<"Czy data 2025-10-32 jest poprawna? "<<czyOK<<endl;

    string today = getTodayDate();
    cout << "Dzisiejsza data: " << today << '\n';

    int dni = getDaysInCurrentMonth();
    cout << "Obecny miesiac ma " << dni << " dni\n";
    return 0;
}

int ObliczDatyPoprzedniegoMiesiacaISprawdzCzyPodanaDataMiesciSieWZakresieDat_main() {
    string testDate = "2025-10-15";

    cout << "Pierwszy dzien poprzedniego miesiaca: " << getFirstDayOfPreviousMonth() << '\n';
    cout << "Ostatni dzien poprzedniego miesiaca: " << getLastDayOfPreviousMonth() << '\n';

    if (isInPreviousMonth(testDate)) {
        cout << "Data " << testDate << " nalezy do poprzedniego miesiaca.\n";
    } else {
        cout << "Data " << testDate << " NIE nalezy do poprzedniego miesiaca.\n";
    }

    return 0;
}

int porownywanieDat_main() {
    string a = "2025-10-15";
    string b = "2025-11-01";

    if (isDateBefore(a, b)) {
        cout <<"Before "<< a << " jest wczesniejsza niz " << b << '\n';
    } else {
        cout << a << " nie jest wczesniejsza niz " << b << '\n';
    }

    if (isDateEarlier(a, b)) {
        cout <<"Earlier "<< a << " jest wczesniejsza niz " << b << '\n';
    } else {
        cout << a << " nie jest wczesniejsza niz " << b << '\n';
    }

    return 0;
}
