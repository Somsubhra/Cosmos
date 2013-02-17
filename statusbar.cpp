/**
 * @file statusbar.cpp
 * @author Somsubhra
 */

//Other includes
#include "statusbar.h"

/**
 * @brief StatusBar::StatusBar Constructor for the Status bar
 */
StatusBar::StatusBar()
{
    this->setupStatusBarComponents();
    this->setupStatusBarUi();
}

/**
 * @brief StatusBar::setupStatusBarComponents Sets up the various status bar components
 */
void StatusBar::setupStatusBarComponents(){
    progressBar = new QProgressBar(this);
    statusLabel = new QLabel(this);
    zoomLabel = new QLabel(this);
}
/**
 * @brief StatusBar::setupStatusBarUi Sets up the UI of the status bar
 */
void StatusBar::setupStatusBarUi(){
    statusLabel->setText("Status:Idle");
    zoomLabel->setText("Zoom: 100%");

    this->addWidget(progressBar);
    this->addWidget(statusLabel,1);
    this->addWidget(zoomLabel);
}

/**
 * @brief StatusBar::setProgress Sets the progress of the page loaded
 * @param value The value of the page loaded in a scale of 1 to 100
 */
void StatusBar::setProgress(int value){
    progressBar->setValue(value);
    if(value < 100){
        statusLabel->setText("Status:Loading...");
    }
    if(value == 100){
        statusLabel->setText("Status:Loaded");
    }
}

/**
 * @brief StatusBar::setZoomLabel Sets the zoom label
 * @param zoomFactor The current zoom factor of the weview
 */
void StatusBar::setZoomLabel(qreal zoomFactor){
    QString zoom;
    zoom.setNum(zoomFactor*100);
    zoomLabel->setText("Zoom: "+zoom+"%");
}
