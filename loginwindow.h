#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QAuthenticator>
#include <QNetworkProxy>


namespace Ui {
class Loginwindow;
}

class Loginwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Loginwindow(QWidget *parent = nullptr);
    ~Loginwindow();
    QString t_oken;

private slots:
    void on_pushButton_clicked();
    void readyRead();
    void authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
    void encrypted(QNetworkReply *reply);
    void finished(QNetworkReply *reply);
    void networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible);
    void preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator);
    void proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);


private:
    Ui::Loginwindow *ui;
    QNetworkAccessManager manager;

    QString emailAddress;
    QString password;



};

#endif // LOGINWINDOW_H
