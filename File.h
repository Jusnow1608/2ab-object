#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>

using namespace std;

class File {

    const string FILE_NAME;
    int lastId;
//XMLDocument xmlDoc;

public:
    File(string fileName): FILE_NAME (fileName) {
    };

    string getFileName();

};

#endif
