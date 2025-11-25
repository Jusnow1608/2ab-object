#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include<windows.h>
#include <fstream>
#include <sstream>


#include "User.h"
#include "UserFile.h"
#include "AuxiliatyMethods.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;
    UserFile userFile;

    bool doesLoginExist(string login);
    User getNewUserDetails();
    int generateNewUserId();

//void findUserByLogin(const string &login, vector <Users>::iterator &itr);
//void findUserById (vector <Users>::iterator &itr)
//void showAllUsers();
//void logoutUser();

public:
    UserManager(string userFileName): userFile(userFileName) {
        loggedInUserId = 0;
        //users = userFile.getUsersFromFile();
    };

    void registerUser();
    void displayAllUsers();

    /*void loginUser();
    void changeLoggedInUserPassword();
    bool isUserLoggedIn();
    int getLoggedInUserId();
    void logoutUser();
        */
};

#endif
