/**
 * @file findbar.cpp
 * @author Somsubhra
 */

//Other includes
#include "findbar.h"

/**
 * @brief FindBar::FindBar The constructor of find bar
 */
FindBar::FindBar()
{
    this->setupFindBarComponents();
    this->makeFindBarConnections();
    this->setupFindBarUi();
}

/**
 * @brief FindBar::setupFindBarComponents Sets up the components of find bar
 */
void FindBar::setupFindBarComponents(){
    findLabel = new QLabel(tr("Find:"));
    findLine = new QLineEdit;
    this->setupFindBarActions();
}

/**
 * @brief FindBar::setupFindBarActions Sets up the actions of the find bar
 */
void FindBar::setupFindBarActions(){
    findForwardAction = new QAction(style()->standardIcon(QStyle::SP_ArrowDown), tr("Find forward"), this);
    findBackwardAction = new QAction(style()->standardIcon(QStyle::SP_ArrowUp), tr("Find backward"), this);
    hideFindBarAction = new QAction(style()->standardIcon(QStyle::SP_DockWidgetCloseButton), tr("Hide"), this);
}

/**
 * @brief FindBar::setupFindBarUi Sets up the UI of the find bar
 */
void FindBar::setupFindBarUi(){
    this->addAction(hideFindBarAction);
    this->addWidget(findLabel);
    this->addWidget(findLine);
    this->addAction(findForwardAction);
    this->addAction(findBackwardAction);
    this->setFixedWidth(300);
}

/**
 * @brief FindBar::makeFindBarConnections Makes the connections of the find bar
 */
void FindBar::makeFindBarConnections(){
    connect(hideFindBarAction, SIGNAL(triggered()), this, SLOT(hide()));
    connect(findLine, SIGNAL(textChanged(QString)), this, SLOT(emitFindTextChangedSignal()));
    connect(findForwardAction, SIGNAL(triggered()), this, SLOT(emitFindForwardClickedSignal()));
    connect(findBackwardAction, SIGNAL(triggered()), this, SLOT(emitFindBackwardClickedSignal()));
    connect(findLine, SIGNAL(returnPressed()), this, SLOT(emitFindForwardClickedSignal()));
}

/**
 * @brief FindBar::emitFindBackwardClickedSignal Emits the find backward signal
 */
void FindBar::emitFindBackwardClickedSignal(){
    emit findBackwardClicked(this->getFindText());
}

/**
 * @brief FindBar::emitFindForwardClickedSignal Emits the find forward signal
 */
void FindBar::emitFindForwardClickedSignal(){
    emit findForwardClicked(this->getFindText());
}

/**
 * @brief FindBar::emitFindTextChangedSignal Emits the text changed signal
 */
void FindBar::emitFindTextChangedSignal(){
    emit findTextChanged(this->getFindText());
}

/**
 * @brief FindBar::getFindText Gets the text in the find line
 * @return The text in the find line
 */
QString FindBar::getFindText(){
    return findLine->text();
}

/**
 * @brief FindBar::showBar Displays the find bar
 */
void FindBar::showBar(){
    this->show();
    findLine->setFocus();
}
