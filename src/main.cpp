#include <QApplication>

#include <QWidget>

#include "game.h"
#include "file_database.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FileDatabase *data = new FileDatabase(":/data.txt");

    MainWindow *window = new MainWindow();

    Game *game = new Game(data, window);

    game->start();

    window->show();

    return app.exec();
}
