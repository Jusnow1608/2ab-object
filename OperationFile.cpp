#include "OperationFile.h"
#include "Operation.h"
#include "Markup.h"


bool OperationFile::addOperationToFile(const Operation &operation) {
    CMarkup xml;

    if (!xml.Load(getFileName())) {
        if (fileType == Type::INCOME)
            xml.AddElem("incomes");
        else
            xml.AddElem("expenses");
    }
    if (fileType == Type::INCOME) {
        xml.FindElem("incomes");
        xml.IntoElem();
        xml.AddElem("income");

    } else {
        xml.FindElem("expenses");
        xml.IntoElem();
        xml.AddElem("expense");
    }

    xml.IntoElem();
    xml.AddElem("id", operation.id);
    xml.AddElem("userId", operation.userId);
    xml.AddElem("date", operation.date);
    xml.AddElem("item", operation.item);

    ostringstream oss;
    oss << fixed << setprecision(2) << static_cast<double>(operation.amount);
    xml.AddElem("amount", oss.str());

    xml.OutOfElem();
    xml.OutOfElem();

    return xml.Save(getFileName());
}


int OperationFile::getLastOperationId() const {
    CMarkup xml;
    int lastOperationId = 0;

    if (!xml.Load(getFileName()))
        return lastOperationId;
    if (fileType == Type::INCOME) {
        if (!xml.FindElem("incomes"))
            return lastOperationId;

        xml.IntoElem();
        while (xml.FindElem("income")) {
            xml.IntoElem();
            if (xml.FindElem("id")) {
                lastOperationId = stoi(xml.GetData());
            }
            xml.OutOfElem();
        }
    }
    else {
        if (!xml.FindElem("expenses"))
            return lastOperationId;

        xml.IntoElem();
        while (xml.FindElem("expense")) {
            xml.IntoElem();
            if (xml.FindElem("id")) {
                lastOperationId = stoi(xml.GetData());
            }
            xml.OutOfElem();
        }
    }
    return lastOperationId;
}

Type OperationFile::getFileType() const {
    return fileType;
}

void OperationFile::loadOperationsFromFile(vector<Operation> &operations) {
    operations.clear();
    CMarkup xml;

    if (!xml.Load(getFileName())) {
        cerr << "Error: cannot open file: " << getFileName() << endl;
        return;
    }

    string root, element;
    if (fileType == Type::INCOME) {
        root = "incomes";
        element = "income";
    } else {
        root = "expenses";
        element = "expense";
    }

    if (!xml.FindElem(root)) {
        cerr << "Error: missing root element " << root << endl;
        return;
    }
    xml.IntoElem();

    while (xml.FindElem(element)) {
        xml.IntoElem();

        Operation op;
        if (xml.FindElem("id")) op.id = stoi(xml.GetData());
        if (xml.FindElem("userId")) op.userId = stoi(xml.GetData());
        if (xml.FindElem("date")) op.date = stoi(xml.GetData());
        if (xml.FindElem("item")) op.item = xml.GetData();
        if (xml.FindElem("amount")) op.amount = stod(xml.GetData());

        operations.push_back(op);

        xml.OutOfElem();
    }
}



