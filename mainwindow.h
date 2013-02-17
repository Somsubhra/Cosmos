/**
 * @file mainwindow.h
 * @author Somsubhra
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Qt includes
#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include <QObject>

//Other includes
#include "webview.h"
#include "urlbar.h"
#include "statusbar.h"
#include "toolbar.h"
#include "findbar.h"

/**
 * @brief The MainWindow class Defines the main window of the browser
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private:
    WebView *webView;
    UrlBar *urlBar;
    StatusBar *statusBar;
    ToolBar *toolBar;
    FindBar *findBar;
    QVBoxLayout *mainLayout;
    QWidget *mainWidget;
    void setupComponents();
    void setupUi();
    void makeConnections();

private slots:
    void setTitle(QString title);
    void setFullScreen(bool fullscrn);

};

#endif // MAINWINDOW_H
