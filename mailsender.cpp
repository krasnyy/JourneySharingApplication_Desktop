#include "mailsender.h"

mailSender::mailSender(QObject *parent):QObject(parent)
{

    connect(&manager,&QNetworkAccessManager::authenticationRequired,this,&mailSender::authenticationRequired);
    connect(&manager,&QNetworkAccessManager::encrypted,this,&mailSender::encrypted);
    connect(&manager,&QNetworkAccessManager::finished,this,&mailSender::finished);
    connect(&manager,&QNetworkAccessManager::networkAccessibleChanged,this,&mailSender::networkAccessibleChanged);
    connect(&manager,&QNetworkAccessManager::preSharedKeyAuthenticationRequired,this,&mailSender::preSharedKeyAuthenticationRequired);
    connect(&manager,&QNetworkAccessManager::proxyAuthenticationRequired,this,&mailSender::proxyAuthenticationRequired);
    connect(&manager,&QNetworkAccessManager::sslErrors,this,&mailSender::sslErrors);

}

void mailSender::get(QString location)
{
    QNetworkReply *reply=manager.get(QNetworkRequest(QUrl(location)));
    connect(reply,&QNetworkReply::readyRead,this,&mailSender::readyRead);
}

void mailSender::post(QString location,QByteArray data)
{
    QNetworkRequest request=QNetworkRequest(QUrl(location));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"text/plain");
    QNetworkReply *reply=manager.post(request,data);
    connect(reply,&QNetworkReply::readyRead,this,&mailSender::readyRead);
}

void mailSender::readyRead()
{
    qInfo()<<"ReadyRead";
    QNetworkReply *reply=qobject_cast<QNetworkReply*>(sender());
    if(reply){
        qInfo() << reply->readAll();
    }
}

void mailSender::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo()<<"authenticationRequired";
}

void mailSender::encrypted(QNetworkReply *reply)
{
    Q_UNUSED(reply);
   qInfo()<<"encrypted";
}

void mailSender::finished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo()<<"finished";
}

void mailSender::networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible)
{
    Q_UNUSED(accessible);
}

void mailSender::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
}

void mailSender::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
     Q_UNUSED(proxy);
     Q_UNUSED(authenticator);
}

void mailSender::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply);
    Q_UNUSED(errors);
}
