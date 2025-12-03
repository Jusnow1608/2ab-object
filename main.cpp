#include <iostream>
#include "Markup.h"
#include "BudgetMainApp.h"

int main() {
    BudgetMainApp budgetMainApp("users.xml", "incomes.xml", "expenses.xml");

    char choice;

    while (true) {
        if (budgetMainApp.isUserLoggedIn() == false) {
            choice = budgetMainApp.getMainMenuSelection();

            switch (choice) {
            case '1':
                budgetMainApp.registerUser();
                break;
            case '2':
                budgetMainApp.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = budgetMainApp.getUserMenuSelection();

            switch (choice) {
            case '1':
                budgetMainApp.addIncome();
                break;
            case '2':
                budgetMainApp.addExpense();
                break;
            case '3':
                budgetMainApp.displayCurrentMonthBalance();
                break;
            case '4':
                budgetMainApp.displayPreviousMonthBalance();
                break;
            case '5':
                budgetMainApp.displaySelectedPeriodBalance();
                break;
            case '6':
                budgetMainApp.changeLoggedInUserPassword();
                break;
            case '7':
                budgetMainApp.logoutUser();
                break;
            }
        }
    }
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

#include "BudgetManager.h"
int BudgetManager_main() {
    BudgetManager budgetManager ("incomes.xml","expenses.xml", 1);
    //cout<<userManager.generateNewUserId()<<endl;
    //userManager.getNewUserDetails();
    //userManager.displayAllUsers();

    return 0;
}
#include "DateMethods.h"
int _main() { //dataDzisiejszaDniWMiesiacuRokPrzestepny

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

    string today = getCurrentDate();
    cout << "Dzisiejsza data: " << today << '\n';

    int dni = getDaysInCurrentMonth();
    cout << "Obecny miesiac ma " << dni << " dni\n";
    */
    string data = DateMethods::formatIntDateToString(2015, 8, 4);
    cout<<DateMethods::formatStringDateToInt (data);
    return 0;
}
