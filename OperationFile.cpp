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
