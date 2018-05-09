#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QList>

#include "Question.h"

class Database {
    private:
        QList<Question> data;

        QString fileName;

        int entries;

        QList<int> entriesUsed;

    public:
        Database(const QString& fileName);

        int read();

        int write(const QString& fileName);

        Question getQuestion(int index) const;

        bool isEntryUsed(int entryIndex) const;

        void markEntryUsed(int entryIndex);

        int size() const;
};

#endif
