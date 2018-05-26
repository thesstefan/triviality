#include <QTextStream>
#include <QFile>

#include "database.h"
#include "exceptions.h"

#include "question.h"

template class Database<Question>;

template <typename Entry>
Database<Entry>::Database() {}

template <typename Entry>
Database<Entry>::~Database() {}

template <typename Entry>
Entry Database<Entry>::getEntry(int entryId) const {
    if (entryId > this->size() || entryId < 0)
        throw OutOfBounds("Database::getEntry() -> entryId is out of bounds.");

    return this->data.at(entryId);
}

template <typename Entry>
void Database<Entry>::markEntryUsed(int entryId) {
    if (entryId > this->size() || entryId < 0)
        throw OutOfBounds("Database::markEntryUsed() -> entryId is out of bounds.");

    this->entriesUsed.append(entryId);
}

template <typename Entry>
bool Database<Entry>::isEntryUsed(int entryId) const {
    if (entryId > this->size() || entryId < 0)
        throw OutOfBounds("Database::markEntryUsed() -> entryId is out of bounds.");

    return this->entriesUsed.contains(entryId);
}

template <typename Entry>
int Database<Entry>::size() const {
    return this->data.size();
}

#ifdef DEBUG
template <typename Entry>
void Database<Entry>::write(const QString& outputFile) {
    QFile file(outputFile);

    if (file.open(QIODevice::WriteOnly) == false) {
        QString errorMsg = "Could not open output file : " + file.errorString();

        throw OpenFail(errorMsg.toStdString());
    }

    QTextStream out(&file);

    out << "Database Size : " << this->size() << " Questions" << endl << endl;

    for (int entryId = 0; entryId < this->size(); entryId++)
        this->data.at(entryId).write(&out);
}
#endif
