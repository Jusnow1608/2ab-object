#include <iostream>
#include "Markup.h"
#include "BudgetMainApp.h"

int main() {
    BudgetMainApp budgetMainApp("users.xml");
    budgetMainApp.displayAllUsers();
    budgetMainApp.registerUser();
    budgetMainApp.displayAllUsers();
    budgetMainApp.registerUser();
    budgetMainApp.displayAllUsers();


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

