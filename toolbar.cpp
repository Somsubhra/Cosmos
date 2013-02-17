/**
 * @file toolbar.cpp
 * @author Somsubhra
 */

#include "toolbar.h"

/**
 * @brief ToolBar::ToolBar Constructor of the toolbar
 */
ToolBar::ToolBar()
{
    this->setupToolBarActions();
    this->makeToolBarConnections();
    this->setupToolBarUi();
}

/**
 * @brief ToolBar::setupToolBarActions Sets up the toolbar actions
 */
void ToolBar::setupToolBarActions(){
    zoomInAction = new QAction(style()->standardIcon(QStyle::SP_ArrowUp), tr("Zoom In"), this);
    zoomInAction->setShortcut(tr("Ctrl++"));
    zoomOutAction = new QAction(style()->standardIcon(QStyle::SP_ArrowDown), tr("Zoom out"), this);
    zoomOutAction->setShortcut(tr("Ctrl+-"));
    findAction = new QAction(style()->standardIcon(QStyle::SP_MessageBoxInformation), tr("Find"), this);
    findAction->setShortcut(tr("Ctrl+F"));
    fullScreenAction = new QAction(style()->standardIcon(QStyle::SP_ComputerIcon), tr("Full Screen"), this);
    fullScreenAction->setShortcut(tr("F9"));
    fullScreenAction->setCheckable(true);
}

/**
 * @brief ToolBar::setupToolBarConnections Makes the toolbar connections
 */
void ToolBar::makeToolBarConnections(){
    connect(zoomInAction, SIGNAL(triggered()), this, SLOT(emitZoomInClickedSignal()));
    connect(zoomOutAction, SIGNAL(triggered()), this, SLOT(emitZoomOutClickedSignal()));
    connect(findAction, SIGNAL(triggered()), this, SLOT(emitFindClickedSignal()));
    connect(fullScreenAction, SIGNAL(toggled(bool)), this, SLOT(emitFullScreenClickedSignal(bool)));
}

/**
 * @brief ToolBar::setupToolBarUi Sets up the UI of the toolbar
 */
void ToolBar::setupToolBarUi(){
    this->addAction(findAction);
    this->addAction(fullScreenAction);
    this->addAction(zoomInAction);
    this->addAction(zoomOutAction);
}

/**
 * @brief ToolBar::emitZoomInClickedSignal Emits zoom in signal
 */
void ToolBar::emitZoomInClickedSignal(){
    emit zoomInClicked();
}

/**
 * @brief ToolBar::emitZoomOutClickedSignal Emits zoom out signal
 */
void ToolBar::emitZoomOutClickedSignal(){
    emit zoomOutClicked();
}

/**
 * @brief ToolBar::emitFindClickedSignal Emits the find text signal
 */
void ToolBar::emitFindClickedSignal(){
    emit findClicked();
}

/**
 * @brief ToolBar::emitFullScreenClickedSignal Emits full screen clicked signal
 * @param fullscrn Whether the window is full screen or not
 */
void ToolBar::emitFullScreenClickedSignal(bool fullscrn){
    emit fullScreenClicked(fullscrn);
}
