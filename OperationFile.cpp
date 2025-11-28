#include "OperationFile.h"
#include "Operation.h"
#include "Markup.h"


bool OperationFile::addOperationToFile(const Operation &operation) {
    CMarkup xml;

    if (!xml.Load(getFileName())) {
        xml.AddElem("incomes");
        xml.IntoElem();
    } else {
        if (xml.FindElem("incomes")) {
            xml.IntoElem();
        } else {
            cerr << "Blad: plik istnieje, ale nie zawiera elementu <incomes>\n";
            return false;
        }
    }

    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("id", operation.id);
    xml.AddElem("userId", operation.userId);
    xml.AddElem("date", operation.date);
    xml.AddElem("item", operation.item);

    ostringstream oss;
    oss << fixed << setprecision(2) << operation.amount;
    xml.AddElem("amount", oss.str());

    xml.OutOfElem();
    xml.OutOfElem();

    return xml.Save(getFileName());
}


int OperationFile::getLastOperationId() const {
    CMarkup xml;
    int lastOperationId = 0;

    if (!xml.Load(getFileName())) {
        return lastOperationId;
    }

    if (!xml.FindElem("incomes")) {
        return lastOperationId;
    }
    xml.IntoElem();

    while (xml.FindElem("income")) {
        xml.IntoElem();

        if (xml.FindElem("id")) {
            lastOperationId = stoi(xml.GetData());
        }

        xml.OutOfElem();
    }

    return lastOperationId;
}
