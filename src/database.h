#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
#include <QString>

#include "question.h"

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

        void addQuestion(const QString& question, int correctAnswerIndex, const QList<QString>& answers);

        Question getQuestion(int questionIndex) const;

        void markEntryUsed(int entryIndex);

        bool isEntryUsed(int entryIndex) const;

        int size() const;
};

#endif
