#include "UserManager.h"

void UserManager::registerUser() {
    cout << "             >>> REGISTRATION <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    User user = getNewUserDetails();

    users.push_back(user);
    userFile.addUserToFile(user);

    cout << endl << "Account has been created successfully" << endl << endl;
    system("pause");
}

User UserManager::getNewUserDetails() {
    User user;
    string login, password, name, surname;
    user.userId = generateNewUserId();

    do {
        cout << "Please provide login: ";
        login = AuxiliaryMethods::readLine();
        user.login = login;
        if (login.empty())
            cout << "Login cannot be empty." << endl;
    } while (doesLoginExist(user.login) || login.empty());

    do {
        cout << "Please provide password: ";
        password = AuxiliaryMethods::readLine();
        user.password = password;
        if (password.empty())
            cout << "Password cannot be empty." << endl;
    } while(password.empty());

    do {
        cout << "Please provide name: ";
        name = AuxiliaryMethods::readLine();
        user.name = name;
        if (name.empty())
            cout << "Name cannot be empty." << endl;
    } while(name.empty());

    do {
        cout << "Please provide surname: ";
        surname = AuxiliaryMethods::readLine();
        user.surname = surname;
        if (surname.empty())
            cout << "Surname cannot be empty." << endl;
    } while(surname.empty());

    return user;
}

int UserManager::generateNewUserId() const {
    if (users.empty() == true)
        return 1;
    else
        return users.back().userId + 1;
}

bool UserManager::doesLoginExist(const string &login) const {
    for (size_t i=0; i<users.size(); i++) {
        if (users[i].login == login) {
            cout << "User with provided login already exists." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::displayAllUsers() const {
    for (size_t i=0; i<users.size(); i++) {
        cout << "Id:       "<<users[i].userId << endl;
        cout << "Login:    "<<users[i].login << endl;
        cout << "Password: "<<users[i].password << endl;
        cout << "Name:     "<<users[i].name << endl;
        cout << "Surname:  "<<users[i].surname << endl;
        cout << endl;
    }
    system ("pause");
}

void UserManager::loginUser()
{
    cout << "             >>> LOGIN <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    string login = "", password = "";
    cout << "Please provide login: ";
    login = AuxiliaryMethods::readLine();
    for (size_t i=0; i<users.size(); i++)
    {
        if (users[i].login == login)
        {
            for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--)
            {
                cout << "Please provide password. Trials left: " << attemptsNumber << ": ";
                password = AuxiliaryMethods::readLine();

                if(users[i].password == password)
                {
                    loggedInUserId = users[i].userId;
                    cout << endl << "You have logged in." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "You entered an incorrect password 3 times." << endl;
            system("pause");
            return;
        }
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");
}
//void findUserByLogin(const string &login, vector <Users>::iterator &itr);
//void findUserById (vector <Users>::iterator &itr)
//void logoutUser();
//void changeLoggedInUserPassword();
bool isUserLoggedIn();
//int getLoggedInUserId();
//void showAllUsers();
//void logoutUser();
