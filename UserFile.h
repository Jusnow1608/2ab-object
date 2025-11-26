#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
//#include "File.h"

using namespace std;

class UserFile
//: public File
{
    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    //Uzytkownik pobierzDaneUzytkownika(string dawaneJednegoUzytkownikaOddzielonePionowymiKreskami);
    string userFileName;

public:
    UserFile(const string xmlFileName = "users.xml"): userFileName (xmlFileName) { //: File (fileName)
    };
    void addUserToFile(const User &user);
    vector <User> getUsersFromFile();
    //bool changePasswordInFile (int id, const string &password);

    /*
    void saveAllUsersToFile(vector <Uzytkownik> & uzytkownicy);
    void loadUsersFromFile();
    string formatUserDataAsFileElement();
    User parseUserFromXml();
    */
};

#endif
