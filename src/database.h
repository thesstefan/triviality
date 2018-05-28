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
 * The Database is also able to keep track of which entries have been used.
 *
 * @note Derived classes are inteded to be used for different input sources. (eg. NetworkDatabase, FileDatabase)
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
         * @brief Reads the Database.
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
         * @brief Writes the Database to text file.
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
         * @param questionId -> The id of the Question to be returned.
         *
         * @exception OutOfBounds -> If @p questionId is not in the range <b>[0, size())</b>.
         */
        Question getQuestion(int questionId) const;

        /**
         * @brief Marks an Question as used. (Used in Game to avoid using the same Question multiple times)
         *
         * @param questionId -> The id of the Question to be returned.
         *
         * @exception OutOfBounds -> If @p questionId is not in the range <b>[0, size())</b>.
         */
        void markQuestionUsed(int questionId);


        /**
         * @brief Checks if a Question is used. (If it was previously marked by markQuestionUsed)
         *
         * @param questionId -> The id of the Question to be checked if it's used.
         *
         * @exception OutOfBounds -> If @p questionId is not in the range <b>[0, size())</b>.
         */
        bool isQuestionUsed(int questionId) const;

        /**
         * @brief Resets the used entries tracker.
         *
         * Every Question will be "marked" as not used.
         */
        void resetUsageTracker();

        /**
         * @brief Returns Database's size.
         */
        int size() const;
};

#endif
