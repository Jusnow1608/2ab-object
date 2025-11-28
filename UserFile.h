#ifndef USERFILE_H
#define USERFILE_H

#include <vector>

#include "User.h"
#include "File.h"

using namespace std;

class UserFile: public File {

public:
    UserFile(const string &fileName): File (fileName) {
    };

    void addUserToFile(const User &user);
    vector <User> getUsersFromFile();
    bool changePasswordInFile (int userId, const string &password);
};

#endif
