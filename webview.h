/**
 * @file webview.h
 * @author Somsubhra
 */

#ifndef WEBVIEW_H
#define WEBVIEW_H

//Qt includes
#include <QtWebKit/QWebView>
#include <QObject>
#include <QUrl>
#include <QtNetwork/QNetworkReply>
#include <QDialog>

/**
 * @brief The WebView class Defines the webview component of the browser
 */
class WebView : public QWebView
{
    Q_OBJECT

public:
    WebView();

private:
    void setDefaultView();
    void makeWebViewConnections();

public slots:
    void loadUrl(const QUrl &url);
    void zoomIn();
    void zoomOut();
    void findTextAll(QString findText);
    void findTextForward(QString findText);
    void findTextBackward(QString findText);

private slots:
    void handleSslErrors(QNetworkReply *reply, const QList<QSslError> &errors);

signals:
    void zoomed(qreal zoomFactor);
};

#endif // WEBVIEW_H
