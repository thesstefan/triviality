#include "quiz.h"

Quiz::Quiz(Database *data) {
    this->data = data;

    this->window = new MainWindow();

    this->stack = new QStackedWidget(this->window);

    this->init(this->stack, data);

    this->stack->setCurrentIndex(MENU_INDEX);

    this->window->setCentralWidget(this->stack);
}

void Quiz::init(QStackedWidget *stack, Database *data) {
    this->menuController = new MenuController(this);

    this->menuController->connectButtons(this, SLOT(startGame()), SLOT(closeApp()));

    this->menuController->addWidgetToStack(stack);

    this->gameController = new GameController(data, this);

    QObject::connect(this->gameController, SIGNAL(gameEnded(int)), this, SLOT(showScore(int)));

    this->gameController->addWidgetToStack(stack);

    this->scoreController = new ScoreController(0, this);

    this->scoreController->connectButtons(this, SLOT(back()), SLOT(closeApp()));

    this->scoreController->addWidgetToStack(stack);
}

void Quiz::run() {
    this->window->show();
}

void Quiz::showScore(int score) {
    this->scoreController->updateScore(score);

    this->stack->setCurrentIndex(SCORE_INDEX);
}

void Quiz::back() {
    this->stack->setCurrentIndex(MENU_INDEX);
}

void Quiz::startGame() {
    this->data->resetUsageTracker();

    this->gameController->startGame();

    this->stack->setCurrentIndex(GAME_INDEX);
}

void Quiz::closeApp() {
    this->window->hide();

    emit kill();
}

Quiz::~Quiz() {
    this->window->deleteLater();
}
