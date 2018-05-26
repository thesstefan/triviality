#include <QTextStream>
#include <QFile>

#include "exceptions.h"
#include "file_database.h"

#include "question.h"

template class FileDatabase<Question>;

template <typename Entry>
FileDatabase<Entry>::FileDatabase(const QString& fileName) : Database<Entry>() {
    this->file = new QFile(fileName);

    if (!this->file->exists())
        throw OpenFail("Could not open file: the file does not exist");

    if (file->open(QIODevice::ReadOnly) == false) {
        QString errorMsg = "Could not open file: " + this->file->errorString();

        throw OpenFail(errorMsg.toStdString());
    }

    this->stream = new QTextStream(this->file);

    try {
        this->readAll();
    } catch (const Exception& exception) {
        throw;
    }
}

template <typename Entry>
FileDatabase<Entry>::~FileDatabase() {
    delete this->stream;

    this->file->close();

    delete this->file;
}

template <typename Entry>
void FileDatabase<Entry>::read() {
    Entry entry;

    entry.read(this->stream);

    this->data.append(entry);
}

template <typename Entry>
void FileDatabase<Entry>::readAll() {
    while (this->stream->atEnd() == false) {
        try {
            this->read();
        } catch (const EntryReadFail& exception) {
            throw ReadFail("Could not read file : Entry reading fail.");
        }
    }
}
