/**
 * @file statusbar.h
 * @author Somsubhra
 */

#ifndef STATUSBAR_H
#define STATUSBAR_H

//Qt includes
#include <QObject>
#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QHBoxLayout>
#include <QStatusBar>

/**
 * @brief The StatusBar class Defines the status bar of the browser
 */
class StatusBar : public QStatusBar
{
    Q_OBJECT
public:
    StatusBar();

private:
    void setupStatusBarUi();
    void setupStatusBarComponents();
    QProgressBar *progressBar;
    QLabel *statusLabel;
    QLabel *zoomLabel;

public slots:
    void setProgress(int value);
    void setZoomLabel(qreal zoomFactor);
};

#endif // STATUSBAR_H
