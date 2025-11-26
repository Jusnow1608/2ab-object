#ifndef FILE_H
#define FILE_H

#include <string>

using namespace std;

class File {

    const string FILE_NAME;
  //  int lastId;
//XMLDocument xmlDoc;

public:
    File(const string &fileName): FILE_NAME (fileName) {
    };

    string getFileName() const;

};

#endif
