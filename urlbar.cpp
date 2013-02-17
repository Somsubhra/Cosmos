/**
 * @file urlbar.cpp
 * @author Somsubhra
 */

//Other includes
#include "urlbar.h"

/**
 * @brief UrlBar::UrlBar Constructor for the urlbar
 */
UrlBar::UrlBar()
{
    this->setupUrlBarComponents();
    this->makeUrlBarConnections();
    this->setupUrlBarUi();   
}

/**
 * @brief UrlBar::setupUrlBarComponents Sets up the url bar components
 */
void UrlBar::setupUrlBarComponents(){
    urlLine = new QLineEdit(this);
    this->setupUrlBarActions();
}

/**
 * @brief UrlBar::setupUrlBarUi Sets up the UI for the urlbar
 */
void UrlBar::setupUrlBarUi(){

    urlLine->setPlaceholderText("Enter URL here");
    this->addAction(backAction);
    this->addAction(forwardAction);
    this->addAction(reloadAction);
    this->addAction(stopAction);
    this->addWidget(urlLine);
    this->addAction(loadAction);
}

/**
 * @brief UrlBar::getUrl Gets the url in the Urlbar
 * @return The url in the url bar
 */
QUrl UrlBar::getUrl(){
    QString url = urlLine->text();
    if(!url.startsWith("http://")){
        url = "http://"+url;
    }
    QUrl link(url);
    this->setUrl(link);
    return link;
}

/**
 * @brief UrlBar::setUrl Sets the URL in the urlbar
 * @param url The url to be set in the urlbar
 */
void UrlBar::setUrl(const QUrl &url){
    urlLine->setText(url.toString());
}

/**
 * @brief UrlBar::setupUrlBarActions Sets up the actions of the urlbar
 */
void UrlBar::setupUrlBarActions(){
    loadAction = new QAction(style()->standardIcon(QStyle::SP_ArrowRight),tr("Go"), this);
    reloadAction = new QAction(style()->standardIcon(QStyle::SP_BrowserReload), tr("Reload"), this);
    stopAction = new QAction(style()->standardIcon(QStyle::SP_BrowserStop), tr("Stop"), this);
    forwardAction = new QAction(style()->standardIcon(QStyle::SP_ArrowForward), tr("Forward"), this);
    backAction = new QAction(style()->standardIcon(QStyle::SP_ArrowBack), tr("Back"), this);
}

/**
 * @brief UrlBar::makeUrlBarConnections akes the connections for the Url bar
 */
void UrlBar::makeUrlBarConnections(){
    connect(loadAction, SIGNAL(triggered()), this, SLOT(emitLoadClickedSignal()));
    connect(reloadAction, SIGNAL(triggered()), this, SLOT(emitReloadClickedSignal()));
    connect(stopAction, SIGNAL(triggered()), this, SLOT(emitStopClickedSignal()));
    connect(backAction, SIGNAL(triggered()), this, SLOT(emitBackClickedSignal()));
    connect(forwardAction, SIGNAL(triggered()), this, SLOT(emitForwardClickedSignal()));
    connect(urlLine, SIGNAL(returnPressed()), this, SLOT(emitLoadClickedSignal()));
}

/**
 * @brief UrlBar::emitLoadClickedSignal Emits signal when load is clicked
 */
void UrlBar::emitLoadClickedSignal(){
    emit loadClicked(this->getUrl());
}

/**
 * @brief UrlBar::emitReloadClickedSignal Emits signal when reload is clicked
 */
void UrlBar::emitReloadClickedSignal(){
    emit reloadClicked();
}

/**
 * @brief UrlBar::emitStopClickedSignal Emits signal when stop is clicked
 */
void UrlBar::emitStopClickedSignal(){
    emit stopClicked();
}

/**
 * @brief UrlBar::emitBackClickedSignal Emits signal when back is clicked
 */
void UrlBar::emitBackClickedSignal(){
    emit backClicked();
}

/**
 * @brief UrlBar::emitForwardClickedSignal Emits signal when forward is clicked
 */
void UrlBar::emitForwardClickedSignal(){
    emit forwardClicked();
}
