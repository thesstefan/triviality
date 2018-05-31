#include <QApplication>

#include <QWidget>

#include "quiz.h"
#include "file_database.h"

#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FileDatabase database(":/data.txt");

    Quiz quiz(&database);

    QObject::connect(&quiz, SIGNAL(kill()), &app, SLOT(quit()));

    quiz.run();

    int ret = app.exec();

    std::cout << "SUCCESS" << std::endl;

    return ret;
}
