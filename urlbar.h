/**
 * @file urlbar.h
 * @author Somsubhra
 */

#ifndef URLBAR_H
#define URLBAR_H

//Qt includes
#include <QToolBar>
#include <QLineEdit>
#include <QAction>
#include <QHBoxLayout>
#include <QToolBar>
#include <QStyle>
#include <QString>
#include <QObject>
#include <QUrl>

/**
 * @brief The UrlBar class Defines the URL Bar of the browser
 */
class UrlBar : public QToolBar
{
    Q_OBJECT

public:
    UrlBar();
private:
    QLineEdit *urlLine;
    QAction *loadAction;
    QAction *reloadAction;
    QAction *stopAction;
    QAction *forwardAction;
    QAction *backAction;
    void setupUrlBarUi();
    void setupUrlBarActions();
    void setupUrlBarComponents();
    void makeUrlBarConnections();

public:
    QUrl getUrl();

public slots:
    void setUrl(const QUrl &url);

private slots:
    void emitLoadClickedSignal();
    void emitReloadClickedSignal();
    void emitStopClickedSignal();
    void emitForwardClickedSignal();
    void emitBackClickedSignal();

signals:
    void loadClicked(QUrl);
    void reloadClicked();
    void stopClicked();
    void forwardClicked();
    void backClicked();

};

#endif // URLBAR_H
