/**
 * @file mainwindow.cpp
 * @author Somsubhra
 */


//Other includes
#include "mainwindow.h"

/**
 * @brief MainWindow::MainWindow Constructor of the MainWindow
 */
MainWindow::MainWindow()
{
    this->setupComponents();
    this->setupUi();
    this->makeConnections();
}

/**
 * @brief MainWindow::setupComponents Sets up the main window components
 */
void MainWindow::setupComponents(){
    webView = new WebView;
    urlBar = new UrlBar;
    statusBar = new StatusBar;
    toolBar = new ToolBar;
    findBar = new FindBar;
}

/**
 * @brief MainWindow::setupUi Sets up the UI of the main window
 */
void MainWindow::setupUi(){
    mainWidget = new QWidget;
    mainLayout = new QVBoxLayout;
    this->addToolBar(Qt::TopToolBarArea, urlBar);
    mainLayout->addWidget(webView); //Can be removed
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);
    this->addToolBar(Qt::LeftToolBarArea, toolBar);
    this->addToolBar(Qt::BottomToolBarArea, findBar);
    findBar->hide();
    this->setStatusBar(statusBar);
}

/**
 * @brief MainWindow::makeConnections Makes the connections for the main window
 */
void MainWindow::makeConnections(){
    connect(urlBar, SIGNAL(loadClicked(QUrl)), webView, SLOT(loadUrl(QUrl)));
    connect(urlBar, SIGNAL(reloadClicked()), webView, SLOT(reload()));
    connect(urlBar, SIGNAL(stopClicked()), webView, SLOT(stop()));
    connect(urlBar, SIGNAL(backClicked()), webView, SLOT(back()));
    connect(urlBar, SIGNAL(forwardClicked()), webView, SLOT(forward()));
    connect(toolBar, SIGNAL(zoomInClicked()), webView, SLOT(zoomIn()));
    connect(toolBar, SIGNAL(zoomOutClicked()), webView, SLOT(zoomOut()));
    connect(toolBar, SIGNAL(findClicked()), findBar, SLOT(showBar()));
    connect(toolBar, SIGNAL(fullScreenClicked(bool)), this, SLOT(setFullScreen(bool)));
    connect(findBar, SIGNAL(findTextChanged(QString)), webView, SLOT(findTextAll(QString)));
    connect(findBar, SIGNAL(findForwardClicked(QString)), webView, SLOT(findTextForward(QString)));
    connect(findBar, SIGNAL(findBackwardClicked(QString)), webView, SLOT(findTextBackward(QString)));
    connect(webView, SIGNAL(urlChanged(QUrl)), urlBar, SLOT(setUrl(QUrl)));
    connect(webView, SIGNAL(loadProgress(int)), statusBar, SLOT(setProgress(int)));
    connect(webView, SIGNAL(zoomed(qreal)), statusBar, SLOT(setZoomLabel(qreal)));
    connect(webView, SIGNAL(titleChanged(QString)), this, SLOT(setTitle(QString)));
}

/**
 * @brief MainWindow::setTitle Sets the window title
 * @param title The title to be set
 */
void MainWindow::setTitle(QString title){
    this->setWindowTitle("Cosmos-"+title);
}

/**
 * @brief MainWindow::setFullScreen Toggles window between full screen and normal
 * @param fullscrn Whether window is fullscreen or not
 */
void MainWindow::setFullScreen(bool fullscrn){
    if(fullscrn){
        this->setWindowState(Qt::WindowFullScreen);
    }
    else{
        this->setWindowState(Qt::WindowMaximized);
    }
}
