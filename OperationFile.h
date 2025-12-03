#ifndef OPERATIONFILE_H
#define OPERATIONFILE_H

#include "Type.h"
#include "File.h"
#include "Operation.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

class OperationFile: public File {
    Type fileType;

public:
    OperationFile(const string& fileName, Type type)
        : File(fileName), fileType(type) {}

    bool addOperationToFile(const Operation &operation);
    int getLastOperationId() const;
    Type getFileType() const;
    void loadOperationsFromFile(vector<Operation> &operations, int loggedInUserId);
};
#endif


