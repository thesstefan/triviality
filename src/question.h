/**
 * @file question.h
 *
 * This module provides the interface of Question.
 */

#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QList>

#include "macros.h"

/**
 * @class Question
 *
 * @brief This class encapsulates and manages the data of a classic multiple-answer question.
 *
 * It contains the question's text and texts of @ref ANSWERS_NUMBER answers, of whom only one is correct.
 *
 * It also allows access to the data, providing getter functions.
 */
class Question {
    private:
        /**
         * @brief The text of the question.
         */
        QString question;

        /**
         * @brief The answers to the question.
         *
         * There are ANSWERS_NUMBER answers.
         */
        QString answer[ANSWERS_NUMBER];

        /**
         * @brief The index of the correct answer to the question.
         */
        int correctAnswerIndex;

    public:
        /**
         * @brief Default constructor.
         *
         * The question text and the answers are initialized to "EMPTY".
         *
         * The correct answer is the first one.
         */
        Question();

        /**
         * @param question -> The text of the question.
         *
         * @param answers -> List of answers.
         *
         * @param correctAnswerIndex -> Index of the correct answer (from the list).
         *
         * @exception OutOfBounds -> If @p correctAnswerIndex is not in the range <b>[0, @ref ANSWERS_NUMBER)</b>.
         *
         * @exception OutOfBounds -> If @p answers.size() is not equal to @ref ANSWERS_NUMBER.
         */
        Question(const QString& question, int correctAnswerIndex, const QList<QString>& answers);

        /**
         * @brief Returns the question's text.
         */
        QString getQuestion() const;

        /**
         * @brief Returns an answer.
         *
         * @param answerIndex -> The index of the answer to be returned.
         */
        QString getAnswer(int answerIndex) const;

        /**
         * @brief Returns the correct answer.
         */
        QString getCorrectAnswer() const;

        /**
         * @brief Returns if an answer is correct or not.
         *
         * @param answerIndex -> The index of the answer to be checked if it's correct.
         */
        bool isCorrectAnswer(int answerIndex) const;
};

#endif
