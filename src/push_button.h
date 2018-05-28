/**
 * @file push_button.h
 *
 * @brief This module provides a QPushButton with customized Style Sheet.
 */

#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>

#include <QColor>

/**
 * @class PushButton
 *
 * @brief This class stands as a QPushButton with a customized Style Sheet.
 */
class PushButton : public QPushButton {
    Q_OBJECT

    public:
        /**
         * @brief The default QColor of the button.
         *
         * @note This is the color of the PushButton after construction
         */
        const static QColor DEFAULT;

        /**
         * @brief The QColor of the button if the answer containing it it's correct. (Green)
         *
         * @note Checking if the answer is correct or not is handled by RoundController.
         */
        const static QColor CORRECT;

        /**
         * @brief The QColor of the button if the answer containing it it's wrong. (Red)
         *
         * @note Checking if the answer is correct or not is handled by RoundController.
         */
        const static QColor WRONG;

        /**
         * @brief Constructs the PushButton.
         *
         * @param parent -> The parent QWidget.
         */
        PushButton(QWidget *parent = 0);

        /**
         * @brief Colorizes the PushButton.
         *
         * @param color -> The QColor to be used.
         *
         * @note All this method does is to update the value of "background" in PushButton's style sheet.
         */
        void colorize(const QColor& color);
};

#endif
