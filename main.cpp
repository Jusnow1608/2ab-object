#include <iostream>
#include "Markup.h"
#include "BudgetMainApp.h"

int main() {
    BudgetMainApp budgetMainApp("users.xml", "Incomes.xml");
    budgetMainApp.displayAllUsers();
    //budgetMainApp.registerUser();
    budgetMainApp.loginUser();
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

