#include <QApplication>

#include "Game.h"
#include "Database.h"
#include "Question.h"
#include "Round.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Database database(":/data.txt");

    database.read();

    Question question = database.getQuestion(0);

    RoundWidget *widget = new RoundWidget();

    widget->show();

    Game *game = new Game(&database, widget);

    game->startNewRound();

    return app.exec();
}
