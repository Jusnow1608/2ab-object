#include <iostream>
#include "Markup.h"
#include "BudgetMainApp.h"

int main() {
    BudgetMainApp budgetMainApp("users.xml", "Incomes.xml");
    budgetMainApp.displayAllUsers();
    //budgetMainApp.registerUser();
    budgetMainApp.loginUser();
    budgetMainApp.addIncome();
    budgetMainApp.addIncome();
    //budgetMainApp.changeLoggedInUserPassword();
    //budgetMainApp.displayAllUsers();
    //budgetMainApp.logoutUser();




    return 0;
}
//Tests
#include "UserManager.h"
int UserManager_main() {
    UserManager userManager ("users.xml");
    //cout<<userManager.generateNewUserId()<<endl;
    //userManager.getNewUserDetails();
    //userManager.displayAllUsers();

    return 0;
}
#include "DateMethods.h"
int _main() //dataDzisiejszaDniWMiesiacuRokPrzestepny
{

    /*string data1 = formatIntDateToString(2015, 8, 4);
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
*/
    string data = DateMethods::formatIntDateToString(2015, 8, 4);
    cout<<DateMethods::formatStringDateToInt (data);
    return 0;
}

/*int ObliczDatyPoprzedniegoMiesiacaISprawdzCzyPodanaDataMiesciSieWZakresieDat_main() {
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
*/
