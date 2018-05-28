/**
 * @file main_window.h
 *
 * This module provides the interface of a customized version of QMainWindow.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "MenuWidget.h"

/**
 * @class MainWindow
 *
 * @brief This class stands as a customized version of QMainWindow used in App.
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        /**
         * @brief Constructs the MainWindow.
         *
         * @param parent -> The QWidget parent.
         */
        MainWindow(QWidget *parent = 0);
};

#endif
