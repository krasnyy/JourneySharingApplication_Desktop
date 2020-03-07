#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include <QJsonValue>
#include <QJsonValueRef>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include<QFile>


Loginwindow::Loginwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Loginwindow)
{
    ui->setupUi(this);



}


void tokenWrite(const QString &Filename,const QString &token)
{
    QFile mFile(Filename);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {

        qInfo() << "could not open file for writting";
        return;
    }
    QTextStream out(&mFile);
    out << token;
    mFile.flush();
    mFile.close();
}



Loginwindow::~Loginwindow()
{
    delete ui;
}

void Loginwindow::on_pushButton_clicked()
{
    ui->label_4->setText("");
    emailAddress=ui->lineEdit->text();
    password=ui->lineEdit_2->text();
    qInfo() << emailAddress << " : " << password;
    //data.append("{\"emailAddress\"").append(":").append("\""+emailAddress+"\"").append(",").append("\"password\"").append(":").append("\""+password+"\"}");
    qInfo() << "Posting to server...";
    QNetworkRequest request = QNetworkRequest(QUrl("https://journey-sharing-application.herokuapp.com/token/panel"));
    QByteArray data;
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    data.append("{\"emailAddress\"").append(":").append("\""+emailAddress+"\"").append(",").append("\"password\"").append(":").append("\""+password+"\"}");
    QNetworkReply* reply = manager.post(request,data);
    connect(reply,&QNetworkReply::readyRead,this,&Loginwindow::readyRead);

}



void Loginwindow::readyRead()
{
    qInfo() << "ReadyRead";
    QByteArray buffer;
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if(reply)
           buffer=reply->readAll();
       QJsonDocument jsonDoc(QJsonDocument::fromJson(buffer).object());
       QString token=jsonDoc["token"].toString();
       if(token.isEmpty()!=0){
           qInfo()<<"Hatali";
           ui->label_4->setText("Email veya parola yanlış.Lütfen tekrar deneyin");
       }
        qInfo() << token;
        t_oken=token;
        const QString filename("C:/Users/Monster/Desktop/token.txt");
        tokenWrite(filename,token);


      /* QJsonObject jsonReply = jsonDoc.object();
       QJsonObject response = jsonReply["token"].toObject();
       QJsonArray  data     = jsonReply["data"].toArray();
       qInfo() << response.value("token");
       qDebug() << data;*/


}


void Loginwindow::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo() << "authenticationRequired";
}

void Loginwindow::encrypted(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "encrypted";
}

void Loginwindow::finished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "finished";
}

void Loginwindow::networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible)
{
    Q_UNUSED(accessible);
    qInfo() << "networkAccessibleChanged";
}

void Loginwindow::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo() << "preSharedKeyAuthenticationRequired";
}

void Loginwindow::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
    Q_UNUSED(proxy);
    Q_UNUSED(authenticator);
    qInfo() << "proxyAuthenticationRequired";
}

void Loginwindow::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply);
    Q_UNUSED(errors);
    qInfo() << "sslErrors";
}



