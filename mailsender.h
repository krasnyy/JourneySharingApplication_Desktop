#ifndef MAILSENDER_H
#define MAILSENDER_H

#include <QObject>
#include<QDebug>
#include<QNetworkProxy>
#include<QAuthenticator>
#include<QNetworkRequest>
#include<QNetworkAccessManager>
#include<QNetworkReply>


class mailSender :public QObject
{
    Q_OBJECT


public:
    explicit mailSender(QObject *parent =nullptr);
signals:

public slots:
    void get(QString location);
    void post(QString location,QByteArray data);
private slots:
    void readyRead();
    void authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
    void encrypted(QNetworkReply *reply);
    void finished(QNetworkReply *reply);
    void networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible);
    void preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator);
    void proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);

private:
    QNetworkAccessManager manager;

};

#endif // MAILSENDER_H
