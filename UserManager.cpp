#include "UserManager.h"

void UserManager::registerUser()
{
    cout << "             >>> REGISTRATION <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    User user = getNewUserDetails();

    users.push_back(user);
    userFile.addUserToFile(user);

    cout << endl << "Account has been created successfully" << endl << endl;
    system("pause");
}

User UserManager::getNewUserDetails()
{
    User user;

    user.userId = generateNewUserId();

    string name;
    do
    {
        cout << "Please provide name: ";
        name = AuxiliaryMethods::readLine();
        user.name = name;
        if (name.empty())
            cout << "Name cannot be empty." << endl;
    }
    while(name.empty());

    string surname;
    do
    {
        cout << "Please provide surname: ";
        surname = AuxiliaryMethods::readLine();
        user.surname = surname;
        if (surname.empty())
            cout << "Surname cannot be empty." << endl;
    }
    while(surname.empty());

    string login;

    do
    {
        cout << "Please provide login: ";
        login = AuxiliaryMethods::readLine();
        user.login = login;
        if (login.empty())
            cout << "Login cannot be empty." << endl;
    }
    while (doesLoginExist(user.login) || login.empty());

    string password;
    do
    {
        cout << "Please provide password: ";
        password = AuxiliaryMethods::readLine();
        user.password = password;
        if (password.empty())
            cout << "Password cannot be empty." << endl;
    }
    while(password.empty());

    return user;
}

int UserManager::generateNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().userId + 1;
}

bool UserManager::doesLoginExist(string login)
{
    for (size_t i=0; i<users.size(); i++)
    {
        if (users[i].login == login)
        {
            cout << "User with provided login already exists." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::displayAllUsers()
{
    for (size_t i=0; i<users.size(); i++)
    {
        cout<<"Id:    "<<users[i].userId<<endl;
        cout<<"Login: "<<users[i].login<<endl;
        cout<<"Password: "<<users[i].password<<endl;
        cout<<"Name: "<<users[i].name<<endl;
        cout<<"Surname: "<<users[i].surname<<endl;
        cout<<endl;
    }
    system ("pause");
}

//void findUserByLogin(const string &login, vector <Users>::iterator &itr);
//void findUserById (vector <Users>::iterator &itr)
//void logoutUser();
//void loginUser();
//void changeLoggedInUserPassword();
//bool isUserLoggedIn();
//int getLoggedInUserId();
//void showAllUsers();
//void logoutUser();
