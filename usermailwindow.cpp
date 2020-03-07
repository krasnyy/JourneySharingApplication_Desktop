#include "usermailwindow.h"
#include "ui_usermailwindow.h"
#include "loginwindow.h"


usermailwindow::usermailwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usermailwindow)
{
    ui->setupUi(this);

}

usermailwindow::~usermailwindow()
{
    delete ui;
}

QString tokenRead(const QString &Filename)
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


void usermailwindow::on_pushButton_2_clicked()
{
    t_itle=ui->mailtitle->text();
    m_essage=ui->mailmessage->toPlainText();
    qInfo() << t_itle << " : " << m_essage;
    //data.append("{\"message\"").append(":").append("\""+emailAddress+"\"").append(",").append("\"password\"").append(":").append("\""+password+"\"}");
    qInfo() << "Posting to server...";
    QNetworkRequest request = QNetworkRequest(QUrl("https://journey-sharing-application.herokuapp.com/email/admin/sendAll"));
    std::unique_ptr<Loginwindow>lg;
    QByteArray data;
    QString readtoken=tokenRead("C:/Users/Monster/Desktop/token.txt");
    QString tokenn="Bearer "+readtoken;
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setRawHeader("Authorization",tokenn.toUtf8());
    data.append("{\"message\"").append(":").append("\""+m_essage+"\"").append(",").append("\"title\"").append(":").append("\""+t_itle+"\"}");
    QNetworkReply* reply = manager.post(request,data);
    connect(reply,&QNetworkReply::readyRead,this,&usermailwindow::readyRead);


}




void usermailwindow::readyRead()
{
    qInfo() << "ReadyRead";
    //QByteArray buffer;
    /*QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if(reply)
           qInfo() << reply->readAll();
       QJsonDocument jsonDoc(QJsonDocument::fromJson(buffer).object());
       QString token=jsonDoc["token"].toString();
       if(token.isEmpty()!=0){
           qInfo()<<"Hatali";
           ui->label_4->setText("Email veya parola yanlış.Lütfen tekrar deneyin");
       }
       qInfo() << token;*/




}


void usermailwindow::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo() << "authenticationRequired";
}

void usermailwindow::encrypted(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "encrypted";
}

void usermailwindow::finished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "finished";
}

void usermailwindow::networkAccessibleChanged(QNetworkAccessManager::NetworkAccessibility accessible)
{
    Q_UNUSED(accessible);
    qInfo() << "networkAccessibleChanged";
}

void usermailwindow::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo() << "preSharedKeyAuthenticationRequired";
}

void usermailwindow::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
    Q_UNUSED(proxy);
    Q_UNUSED(authenticator);
    qInfo() << "proxyAuthenticationRequired";
}

void usermailwindow::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply);
    Q_UNUSED(errors);
    qInfo() << "sslErrors";
}




