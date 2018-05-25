/**
 * @file database.h
 *
 * This module provides the abstract interface of Database.
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <QList>
#include <QString>

#include "question.h"

/**
 * @class Database
 *
 * @brief This class encapsulates and manages a collection of more Question instances.
 *
 * It is an abstract interface because we may need alternative input methods. 
 * (eg. different files formats / network source).
 *
 * The Database is also able to keep track of which entries have been used.
 *
 * @note We use the term "entry" because it's more suitable for a Database-like structure
 * which may be generalized at some point in the future. For now, an entry is just a Question.
 */

class Database {
    protected:
        /**
         * @brief The internal representation of the Question collection.
         */
        QList<Question> data;

        /**
         * @brief List containing the indexes of the used entries.
         */
        QList<int> entriesUsed;

        /**
         * @brief Reads the database from a source, source defined by the derived class.
         * (e.g. The source of FileDatabase is a text file).
         *
         * The derived class must implement this method as different source types need
         * different read() implementations.
         *
         * This method is intended to be used inside the constructor of the derived class. 
         *
         * This method is also intended to pe private in the derived classes because the
         * Database interface focuses on managing the data (not reading / writing it).
         */
        virtual void read() = 0;

    public:
        /*
         * @brief Default constructor.
         */
        Database();

        /*
         * @brief Default virtual constructor.
         */
        virtual ~Database();

#ifdef DEBUG
        /**
         * @brief Writes database to standard file. (.txt)
         *
         * @param output -> The name of the file to write the Database to.
         *
         * @note This is a debugging function. It's used only if DEBUG it's defined.
         */
        void write(const QString& output);
#endif

        /**
         * @brief Returns a Question from the Database.
         *
         * @param questionIndex -> The index of the Question to be returned.
         *
         * @exception OutOfBounds -> If @p questionIndex is not in the range <b>[0, size())</b>.
         */
        Question getQuestion(int questionIndex) const;

        /**
         * @brief Marks an entry as used.
         *
         * @param entryIndex -> The index of the entry to be returned.
         *
         * @exception OutOfBounds -> If @p entryIndex is not in the range <b>[0, size())</b>.
         */
        void markEntryUsed(int entryIndex);


        /**
         * @brief Checks if an entry is used.
         *
         * @param entryIndex -> The index of the entry to be checked if it's used.
         *
         * @exception OutOfBounds -> If @p entryIndex is not in the range <b>[0, size())</b>.
         */
        bool isEntryUsed(int entryIndex) const;

        /**
         * @brief Returns Database's size.
         */
        int size() const;
};

#endif
