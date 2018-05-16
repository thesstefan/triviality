#include <QDebug>
#include <iostream>

#include "exceptions.h"
#include "file_database.h"

int main(int argc, char *argv[]) {
    FileDatabase *database;
    
    try {
        database = new FileDatabase(":/data.txt");
    } catch (const Exception& exception) {
        std::cout << exception.what() << std::endl;
    }

    database->write("output.txt");

    delete database;

    return 0;
}
