#ifndef FILE_DATABASE_H
#define FILE_DATABASE_H

#include "database.h"

#include <QTextStream>

class FileDatabase : public Database {
    private:
        void addEntry(const QString& question, int correctAnswerIndex, const QList<QString>& answers);

        void readEntry(QTextStream& stream);

    public:
        FileDatabase(const QString& fileName);

        void read();
};

#endif
