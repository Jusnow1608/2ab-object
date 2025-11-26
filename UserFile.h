#ifndef USERFILE_H
#define USERFILE_H

#include <vector>

#include "User.h"
#include "File.h"

using namespace std;

class UserFile: public File
{
    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    //Uzytkownik pobierzDaneUzytkownika(string dawaneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    UserFile(const string &fileName): File (fileName) {
    };
    void addUserToFile(const User &user);
    vector <User> getUsersFromFile();

    //bool changePasswordInFile (int id, const string &password);

    /*
    void saveAllUsersToFile(vector <Uzytkownik> & uzytkownicy);
    string formatUserDataAsFileElement();
    User parseUserFromXml();
    */
};

#endif
