/**
 * @file file_database.cpp
 *
 * This module provides the inteface of FileDatabase, derived of Database.
 */

#ifndef FILE_DATABASE_H
#define FILE_DATABASE_H

#include "database.h"

#include <QTextStream>
#include <QFile>

/**
 * @class FileDatabase
 *
 * @brief This class is derived from Database, having the same uses, except
 * it's able to read the data from a text file.
 *
 * @note A Question able to be read by FileDatabase in a text format looks like this :
 *
 * @code
 *
 * ...
 *
 * Which country is known as "Land of the Rising Sun" ? (Question text)
 * 1                                                    (Index of the correct answer, starting from 0)
 * Romania                                              (Answer 0)
 * Japan                                                (Answer 1)
 * Italy                                                (Answer 2)
 * ...                                                  ...
 * Germany                                              (Answer ANSWERS_NUMBER - 1)
 * *newline*
 *
 * ...
 *
 * @endcode
 *
 * @note A FileDatabase can read a file containing more instances of Question, formatted as shown.
 *
 */
class FileDatabase : public Database {
    private:
        /** 
         * @brief The QTextStream used to read from.
         */
        QTextStream *stream;

        /**
         * @brief The QFile used to read from.
         */
        QFile *file;

        /**
         * @brief Reads a Question from the file. 
         *
         * @note A stream is used => Multiple read() calls do not read the same Question.
         *
         * @exception ReadFail -> If the file is corrupted / not formatted properly.
         */
        void read();

        /**
         * @brief Reads all the Question instances from the file.
         *
         * @exception ReadFail -> If the file is corrupted / not formatted properly.
         */
        void readAll();

    public:
        /**
         * @brief Constructs the FileDatabase and populates it by reading and parsing a text file.
         *
         * @param fileName -> The text file to read from.
         *
         * @exception OpenFail -> The file does not exist / can't be opened.
         */
        FileDatabase(const QString& fileName);

        /**
         * @brief Default destructor
         */
        ~FileDatabase();
};

#endif
