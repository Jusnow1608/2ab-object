#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <vector>
#include <iostream>
#include <algorithm>

#include "User.h"
#include "UserFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector <User> users;
    UserFile userFile;

    bool doesLoginExist(const string &login) const;
    User getNewUserDetails();
    int generateNewUserId() const;
    User& findUserById(int userId);

public:
    UserManager(const string &userFileName): userFile(userFileName) {
        loggedInUserId = 0;
        users = userFile.getUsersFromFile();
    };

    void registerUser();
    void loginUser();
    void changeLoggedInUserPassword();
    void logoutUser();
    bool isUserLoggedIn();
    int getLoggedInUserId();
};

#endif
