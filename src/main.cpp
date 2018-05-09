#include <QApplication>

#include <iostream>

#include "Game.h"
#include "Database.h"
#include "Question.h"
#include "Round.h"
#include "MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Database database(":/data.txt");

    MainWindow *window = new MainWindow();

    Game *game = new Game(&database, window);

    game->start();

    return app.exec();
}
