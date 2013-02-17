/**
 * @file toolbar.h
 * @author Somsubhra
 */

#ifndef TOOLBAR_H
#define TOOLBAR_H

//Qt includes
#include <QAction>
#include <QToolBar>
#include <QStyle>
#include <QObject>
/**
 * @brief The ToolBar class Defines the toolbar of the browser
 */
class ToolBar : public QToolBar
{
    Q_OBJECT
public:
    ToolBar();

private:
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *findAction;
    QAction *fullScreenAction;
    void setupToolBarUi();
    void setupToolBarActions();
    void makeToolBarConnections();

private slots:
    void emitZoomInClickedSignal();
    void emitZoomOutClickedSignal();
    void emitFindClickedSignal();
    void emitFullScreenClickedSignal(bool fullscrn);

signals:
    void zoomInClicked();
    void zoomOutClicked();
    void findClicked();
    void fullScreenClicked(bool);
};

#endif // TOOLBAR_H
