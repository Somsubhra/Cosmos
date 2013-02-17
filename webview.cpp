/**
 * @file webview.cpp
 * @author Somsubhra
 */

//Other includes
#include "webview.h"

/**
 * @brief WebView::WebView Constructor of the webview
 */
WebView::WebView()
{
    setDefaultView();
    this->makeWebViewConnections();
}

/**
 * @brief WebView::setDefaultView Sets the home page of the webview
 */
void WebView::setDefaultView(){
    this->setHtml("<html><body><h1>Welcome to Cosmos</h1></body></html>");
}

/**
 * @brief WebView::loadUrl Loads the url on the webview
 * @param url The url to be loaded in the webview
 */
void WebView::loadUrl(const QUrl &url){
    this->load(url);
}

/**
 * @brief WebView::zoomIn Increases the zoom factor
 */
void WebView::zoomIn(){
    qreal zoom = this->zoomFactor() + 0.1;
    emit zoomed(zoom);
    this->setZoomFactor(zoom);
}

/**
 * @brief WebView::zoomOut Decreases the zoom factor
 */
void WebView::zoomOut(){
    qreal zoom = this->zoomFactor() - 0.1;
    emit zoomed(zoom);
    this->setZoomFactor(zoom);
}

/**
 * @brief WebView::findTextAll Highlights all the occurences of the text
 * @param findText The text to be found
 */
void WebView::findTextAll(QString findText){
    this->findText(findText, QWebPage::HighlightAllOccurrences);
}

/**
 * @brief WebView::findTextBackward Finds the text backwards
 * @param findText The text to be found
 */
void WebView::findTextBackward(QString findText){
    this->findText(findText, QWebPage::FindBackward);
}

/**
 * @brief WebView::findTextForward Finds the text forwards
 * @param findText The text to be found
 */
void WebView::findTextForward(QString findText){
    this->findText(findText);
}

/**
 * @brief WebView::handleSslErrors Handles the SSL Errors
 * @param reply The reply from the network
 * @param errors The SSL Errors generated
 */
void WebView::handleSslErrors(QNetworkReply *reply, const QList<QSslError> &errors){
    reply->ignoreSslErrors(errors);
}

/**
 * @brief WebView::makeWebViewConnections Make the connections of web view
 */
void WebView::makeWebViewConnections(){
    connect(page()->networkAccessManager(), SIGNAL(sslErrors(QNetworkReply*,QList<QSslError>)),
            this, SLOT(handleSslErrors(QNetworkReply*,QList<QSslError>)));
}
