#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

struct User {
    int userId;
    string login;
    string password;
    string name;
    string surname;

    User() : userId(0) {}

    User(int userId_, const string& login_, const string& password_,
         const string& name_, const string& surname_)
        : userId(userId_), login(login_), password(password_), name(name_), surname(surname_) {}
};

#endif
