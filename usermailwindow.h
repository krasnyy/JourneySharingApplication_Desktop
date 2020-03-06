#ifndef USERMAILWINDOW_H
#define USERMAILWINDOW_H

#include <QDialog>
#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QAuthenticator>
#include <QNetworkProxy>
#include<string>

namespace Ui {
class usermailwindow;
}

class usermailwindow : public QDialog
{
    Q_OBJECT

public:
    explicit usermailwindow(QWidget *parent = nullptr);
    ~usermailwindow();

private slots:
    void on_pushButton_2_clicked();
    void readyRead();
    void authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
    void encrypted(QNetworkReply *reply);
    void finished(QNetworkReply *reply);
    void networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible);
    void preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator);
    void proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);

private:
    QString t_itle;
    QString m_essage;
    Ui::usermailwindow *ui;
    QNetworkAccessManager manager;
};

#endif // USERMAILWINDOW_H
