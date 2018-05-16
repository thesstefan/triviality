#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
#include <QString>

#include "Question.h"

class Database {
    protected:
        QList<Question> data;

        QList<int> entriesUsed;

        virtual void read() = 0;

    public:
        Database();

        virtual ~Database();

#ifdef DEBUG
        void write(const QString& output);
#endif

        Question getQuestion(int questionIndex) const;

        void markEntryUsed(int entryIndex);

        bool isEntryUsed(int entryIndex) const;

        int size() const;
};

#endif
