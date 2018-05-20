#ifndef FILE_DATABASE_H
#define FILE_DATABASE_H

#include "database.h"

#include <QTextStream>
#include <QFile>

class FileDatabase : public Database {
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
