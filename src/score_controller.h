/**
 * @file score_controller.h
 *
 * @brief This module provides an interface for ScoreController which stands as a 
 * controller between ScoreWidget and Quiz.
 */

#ifndef SCORE_CONTROLLER_H
#define SCORE_CONTROLLER_H

#include <QObject>

#include "score_widget.h"
#include "main_window.h"

#include "exceptions.h"

/**
 * @class ScoreController
 *
 * @brief This class is used to manage the relation between ScoreWidget and Quiz.
 *
 * It connects the buttons of ScoreWidget to the coresponding slots of Quiz.
 *
 * It also can show the ScoreWidget on the MainWindow.
 */
class ScoreController : public QObject {
    Q_OBJECT

    private:
        /** @brief The ScoreWidget to be managed. **/
        ScoreWidget *widget;

    public:
        /**
         * @brief Constructs the ScoreController.
         *
         * The ScoreController also constructs the ScoreWidget, using @p score.
         *
         * @param score -> The score to be displayed on ScoreWidget.
         *
         * @param parent -> The QObject parent of ScoreController.
         */
        ScoreController(int score, QObject *parent = 0);

        /**
         * @brief Sets ScoreWidget as the central widget on MainWindow.
         *
         * @param window -> The MainWindow to be used.
         */
        void focus(MainWindow *window);

        /**
         * @brief Removes ScoreWidget from MainWindow and gets the ownership back.
         *
         * @exception WidgetMismatch -> When the QWidget returned by MainWindow::takeCentralWidget() is 
         * not the one managed by ScoreController.
         */
        void stopFocus(MainWindow *window);

        /**
         * @brief Connects the 2 PushButtons of ScoreWidget to 2 slots.
         *
         * @param receiver -> The owner of the @b slots.
         *
         * @param backSlot -> The @b slot to be connected to the back PushButton.
         *
         * @param closeSlot -> The @b slot to be connected to the close PushButton.
         */
        void connectButtons(QObject *receiver, const char *backSlot, const char *closeSlot);
};

#endif
