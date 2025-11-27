#include "OperationFile.h"
#include "Operation.h"
#include "Markup.h"

#include <iostream>


bool OperationFile::addOperationToFile(const Operation &operation) {
    CMarkup xml;

    if (!xml.Load(getFileName())) {
        // Plik nie istnieje — tworzymy nowy dokument z jednym elementem g³ównym
        xml.AddElem("incomes");
        xml.IntoElem();
    } else {
        // Plik istnieje — znajdŸ element g³ówny
        if (xml.FindElem("incomes")) {
            xml.IntoElem();
        } else {
            // Jeœli nie znaleziono <incomes>, nie dodawaj drugiego — zg³oœ b³¹d
            cerr << "B³¹d: plik istnieje, ale nie zawiera elementu <incomes>\n";
            return false;
        }
    }

    // Dodaj now¹ operacjê
    xml.AddElem("income");
    xml.IntoElem();
    xml.AddElem("id", operation.id);
    xml.AddElem("userId", operation.userId);
    xml.AddElem("date", operation.date);
    xml.AddElem("item", operation.item);
    xml.AddElem("amount", operation.amount);
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
