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
 * @brief This class encapsulates and manages a collection of more object instances.
 *
 * @tparam Entry -> the type of object the Database manages.
 *
 * @note @b Entry must have the following methods implemented :
 *      @li <b>write(QTextStream *stream)</b>, used by write(). (only if @b DEBUG is defined)
 *      @li <b>read(SourceType *source)</b>, where the @b SourceType is defined by the type of Database used.
 *
 * The Database is also able to keep track of which entries have been used.
 */
template <typename Entry>
class Database {
    protected:
        /**
         * @brief The internal representation of the entries collection.
         */
        QList<Entry> data;

        /**
         * @brief List containing the indexes of the used entries.
         */
        QList<int> entriesUsed;

        /**
         * @brief Reads the database from a source, source defined by the derived class.
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
         * @brief Default virtual destructor.
         */
        virtual ~Database();

#ifdef DEBUG
        /**
         * @brief Writes the Database to text file. (.txt)
         *
         * @param outputFile -> The name of the file to write the Database to.
         *
         * @note This is a debugging function. It's used only if @b DEBUG it's defined.
         */
        void write(const QString& outputFile);
#endif

        /**
         * @brief Returns an @b Entry from the Database.
         *
         * @param entryId -> The id of the @b Entry to be returned.
         *
         * @exception OutOfBounds -> If @p entryId is not in the range <b>[0, size())</b>.
         */
        Entry getEntry(int entryId) const;

        /**
         * @brief Marks an @b Entry as used.
         *
         * @param entryId -> The id of the @b Entry to be returned.
         *
         * @exception OutOfBounds -> If @p entryId is not in the range <b>[0, size())</b>.
         */
        void markEntryUsed(int entryId);


        /**
         * @brief Checks if an @b Entry is used.
         *
         * @param entryId -> The id of the @b Entry to be checked if it's used.
         *
         * @exception OutOfBounds -> If @p entryId is not in the range <b>[0, size())</b>.
         */
        bool isEntryUsed(int entryId) const;

        /**
         * @brief Returns the number of entries the Database contains.
         */
        int size() const;
};

#endif
