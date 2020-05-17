include "userslist.h"
#include "ui_userslist.h"
#include <QNetworkAccessManager>
#include<QNetworkReply>
#include<QNetworkRequest>
#include <QJsonValue>
#include <QJsonValueRef>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include<QFile>


QString tokenReadl(const QString &Filename)
{
    QFile mFile(Filename);
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {

        qInfo() << "could not open file for reading";
        return "";
    }
    QTextStream in(&mFile);
    QString t_oken=in.readAll();
    qDebug() << t_oken;
    mFile.flush();
    mFile.close();
    return t_oken;
}

usersList::usersList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usersList)
{
    ui->setupUi(this);

    connect(&manager,&QNetworkAccessManager::authenticationRequired,this,&usersList::authenticationRequired);
    connect(&manager,&QNetworkAccessManager::encrypted,this,&usersList::encrypted);
    connect(&manager,&QNetworkAccessManager::networkAccessibleChanged,this,&usersList::networkAccessibleChanged);
    connect(&manager,&QNetworkAccessManager::preSharedKeyAuthenticationRequired,this,&usersList::preSharedKeyAuthenticationRequired);
    connect(&manager,&QNetworkAccessManager::proxyAuthenticationRequired,this,&usersList::proxyAuthenticationRequired);
    connect(&manager,&QNetworkAccessManager::sslErrors,this,&usersList::sslErrors);

    qInfo() << "Getting from server...";
    /*const QString readtoken=tokenRead("C:/Users/Monster/Desktop/token.txt");
    QNetworkReply* reply = manager.get(QNetworkRequest(QUrl("https://journey-sharing-application.herokuapp.com/user/admin/all")));
    connect(reply,&QNetworkReply::readyRead,this,&usersList::readyRead);*/




    QNetworkRequest request = QNetworkRequest(QUrl("https://journey-sharing-application.herokuapp.com/user/admin/all"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    const QString readtoken=tokenReadl("C:/Users/Monster/Desktop/token.txt");
    const QString tokenn="Bearer "+readtoken;
    request.setRawHeader("Authorization",tokenn.toUtf8());
    QNetworkReply* reply = manager.get(request);
    connect(reply,&QNetworkReply::readyRead,this,&usersList::readyRead);


}


usersList::~usersList()
{
    delete ui;
}


/*
public class User {
    private UUID id;
    private String name;
    private String surname;
    private String emailAddress;
    private String password;
    private String profilePicture;
    private Date birthday;
    private Date joinDate;
    private Boolean gender;
    private String biography;
    private String additions;
    private SocialMedia socialMediaFk;
    private DiscountType discountTypeFk;
    private Role roleFk;
    private Boolean isActive;
}*/

void usersList::readyRead()
{
    qInfo() << "ReadyRead";
    QByteArray buffer;
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if(reply)
           buffer=reply->readAll();

       //QJsonDocument jsonDoc(QJsonDocument::fromJson(buffer).object());
       //QString token=jsonDoc["token"].toString();
       //QStringList table;
       //table[0]=jsonDoc["Name"].toString();




      /* QJsonObject jsonReply = jsonDoc.object();
       QJsonObject response = jsonReply["token"].toObject();
       QJsonArray  data     = jsonReply["data"].toArray();
       qInfo() << response.value("token");
       qDebug() << data;*/


}


void usersList::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo() << "authenticationRequired";
}

void usersList::encrypted(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "encrypted";
}

void usersList::finished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "finished";
}

void usersList::networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible)
{
    Q_UNUSED(accessible);
    qInfo() << "networkAccessibleChanged";
}

void usersList::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo() << "preSharedKeyAuthenticationRequired";
}

void usersList::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
    Q_UNUSED(proxy);
    Q_UNUSED(authenticator);
    qInfo() << "proxyAuthenticationRequired";
}

void usersList::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply);
    Q_UNUSED(errors);
    qInfo() << "sslErrors";
}








