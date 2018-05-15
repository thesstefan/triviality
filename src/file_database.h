#ifndef FILE_DATABASE_H
#define FILE_DATABASE_H

#include "database.h"

class FileDatabase : public Database {
    public:
        FileDatabase(const QString& fileName);

        void read();
};

#endif
