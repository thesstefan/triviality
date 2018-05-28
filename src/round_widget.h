/**
 * @file round_widget.h
 *
 * @brief This module provides a visual interface for a Round.
 */

#ifndef ROUNDWIDGET_H
#define ROUNDWIDGET_H

#include <QWidget>
#include <QLabel>

#include "push_button.h"

/**
 * @class RoundWidget
 *
 * @brief This class is derrived from QWidget and stands as a visual interface for Round.
 *
 * It contains ANSWERS_NUMBER PushButton s, and one Question label, under the form of a QLabel.
 *
 * It's members data is like the ones of Question, the buttons and the label having the same text
 * as the Question members.
 *
 * The class is able to receive input. When a button is pressed, Round appreciates if it's correct or not.
 *
 * The pressed button is colored accordingly (PushButton::CORRECT or PushButton::WRONG).
 */
class RoundWidget : public QWidget {
    Q_OBJECT

    private:
        /**
         * @brief QLabel containing the Question text.
         */
        QLabel *questionLabel;

        /**
         * @brief ANSWERS_NUMBER buttons, having the text of a Question's ANSWERS_NUMBER answers.
         */
        PushButton *answerButton[ANSWERS_NUMBER];

    public:
        /**
         * @brief Constructs the RoundWidget.
         *
         * @param parent -> The QWidget parent.
         */
        RoundWidget(QWidget *parent = 0);

        /**
         * @brief Updates the text of the QLabel.
         *
         * @param text -> The new text.
         */
        void updateLabel(const QString& text);

        /**
         * @brief Updates the text of a PushButton.
         *
         * @param text -> The new text.
         *
         * @param index -> The index of the PushButton to be updated.
         */
        void updateButton(const QString& text, int index);
    
        /**
         * @brief Disables all the PushButton s.
         */
        void disableButtons();

        /**
         * @brief Connects all the ANSWERS_NUMBER PushButton s to a @b slot.
         *
         * @param receiver The owner of the @b slot.
         *
         * @param slot The @b slot to connect with.
         */
        void connectButtons(QObject *receiver, const char* slot);
};

#endif
