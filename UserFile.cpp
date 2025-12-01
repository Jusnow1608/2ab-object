#include "UserFile.h"
#include "Markup.h"
#include <iostream>


void UserFile::addUserToFile(const User &user) {
    CMarkup xml;

    if (!xml.Load(getFileName())) {
        xml.AddElem("users");
    }

    xml.FindElem("users");
    xml.IntoElem();

    xml.AddElem("user");
    xml.IntoElem();
    xml.AddElem("id", user.userId);
    xml.AddElem("login", user.login);
    xml.AddElem("password", user.password);
    xml.AddElem("name", user.name);
    xml.AddElem("surname", user.surname);
    xml.OutOfElem();

    xml.Save(getFileName());
}

vector <User> UserFile::getUsersFromFile() {

    vector <User> users;

    CMarkup xml;

    if (!xml.Load(getFileName())) {
        cerr << "Opening file XML failed\n";
        return users;
    }

    xml.FindElem("users");
    xml.IntoElem();

    while (xml.FindElem("user")) {
        xml.IntoElem();

        xml.FindElem("id");
        int userId = stoi(xml.GetData());

        xml.FindElem("login");
        string login = xml.GetData();

        xml.FindElem("password");
        string password = xml.GetData();

        xml.FindElem("name");
        string name = xml.GetData();

        xml.FindElem("surname");
        string surname = xml.GetData();

        users.emplace_back(userId, login, password, name, surname);

        xml.OutOfElem();
    }
    return users;
}

bool UserFile::changePasswordInFile(int userId, const string& newPassword) {
    CMarkup xml;

    if (!xml.Load(getFileName())) {
        cerr << "Opening file XML failed\n";
        return false;
    }

    if (xml.FindElem("users")) {
        xml.IntoElem();

        while (xml.FindElem("user")) {
            xml.IntoElem();

            if (xml.FindElem("id")) {
                int currentId = stoi(xml.GetData());

                if (currentId == userId) {
                    if (xml.FindElem("password")) {
                        xml.SetData(newPassword);
                        xml.OutOfElem();
                        xml.Save(getFileName());
                        return true;
                    }
                }
            }
            xml.OutOfElem();
        }
    }
    return false;
}

