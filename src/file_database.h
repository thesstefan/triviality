#ifndef FILE_DATABASE_H
#define FILE_DATABASE_H

#include "database.h"

#include <QTextStream>
#include <QFile>

template <typename Entry>
class FileDatabase : public Database<Entry> {
    private:
        QTextStream *stream;

        QFile *file;

        void read();

        void readAll();

    public:
        FileDatabase(const QString& fileName);

        ~FileDatabase();
};

#endif
