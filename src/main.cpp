#include <QApplication>

#include <QWidget>

#include "quiz.h"
#include "file_database.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FileDatabase *database = new FileDatabase(":/data.txt");

    Quiz *quiz = new Quiz(database);

    quiz->run();

    return app.exec();
}
