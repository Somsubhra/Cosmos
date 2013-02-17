/**
 * @file main.cpp
 * @author Somsubhra
 */

//Qt Includes
#include <QApplication>

//Other includes
#include "mainwindow.h"

/**
 * @brief main The main method of Cosmos
 * @param argc Number of Command line arguements
 * @param argv Command line arguements
 * @return The execution status of the app
 */
int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    MainWindow win;
    win.show();
    return app.exec();
}
