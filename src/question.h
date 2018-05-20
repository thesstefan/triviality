/**
 * @file question.h
 *
 * This module provides the implementation of Question.
 */

#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <QList>

#include "macros.h"

/**
 * @class Question
 *
 * @brief A class implementation of a question-type structure.
 */
class Question {
    private:
        QString question;
        QString answer[ANSWERS_NUMBER];

        int correctAnswerIndex;

    public:
        /**
         * @brief Constructs the Question.
         *
         * @param question Question text.
         *
         * @param correctAnswerIndex Index of the correct answer.
         *
         * @param answers List of answers.
         */
        Question(const QString& question, int correctAnswerIndex, const QList<QString>& answers);

        /**
         * @brief Returns the question text.
         *
         * @return Question text
         */
        QString getQuestion() const;

        /**
         * @brief Returns an answer.
         *
         * @param answerIndex The index of the answer to be returned.
         *
         * @return The answer at @p answerIndex.
         */
        QString getAnswer(int answerIndex) const;

        /**
         * @brief Returns the correct answer.
         *
         * @return The correct answer.
         */
        QString getCorrectAnswer() const;

        /**
         * @brief Returns if an answer is correct.
         *
         * @param answerIndex The index of the answer to be checked if it's correct.
         *
         * @return @b true if the answer at @p answerIndex is correct, @b false otherwise.
         */
        bool isCorrectAnswer(int answerIndex) const;
};

#endif
