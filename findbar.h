#ifndef FINDBAR_H
/**
 * @file findbar.h
 * @author Somsubhra
 */

#define FINDBAR_H

//Qt includes
#include <QObject>
#include <QToolBar>
#include <QLineEdit>
#include <QAction>
#include <QStyle>
#include <QLabel>
#include <QString>

/**
 * @brief The FindBar class Defines the find bar
 */
class FindBar : public QToolBar
{
    Q_OBJECT
public:
    FindBar();
    QString getFindText();

private:
    void setupFindBarUi();
    void setupFindBarComponents();
    void setupFindBarActions();
    void makeFindBarConnections();
    QLabel *findLabel;
    QLineEdit *findLine;
    QAction *findForwardAction;
    QAction *findBackwardAction;
    QAction *hideFindBarAction;

private slots:
    void emitFindForwardClickedSignal();
    void emitFindBackwardClickedSignal();
    void emitFindTextChangedSignal();

public slots:
    void showBar();

signals:
    void findForwardClicked(QString);
    void findBackwardClicked(QString);
    void findTextChanged(QString);
};

#endif // FINDBAR_H
