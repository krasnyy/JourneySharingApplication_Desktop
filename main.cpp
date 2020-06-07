#include "loginwindow.h"
#include "usermailwindow.h"
#include <QApplication>
#include<QByteArray>
#include"logger.h"
#include<memory>
#include"mainpanel.h"


QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("acidalia");
    db.setDatabaseName("customdb");
    db.setUserName("mojito");
    db.setPassword("J0a1m8");
    bool ok = db.open();


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QPlainTextEdit *editor = new QPlainTextEdit(this);
    //QString fileName = "c:.txt";
    //Logger *logger = new Logger(this, fileName, editor);
    //logger->write("");
    Loginwindow loginWindow;
    loginWindow.show();
    QByteArray data;
        data.append("");
        data.append("&");
        data.append("param2-foo");

        mail.post("http://postman-echo.com/post",data);
   /* mailSender mail;
   */


   // mail.get("http://postman-echo.com/get?fool-bar1&foo2=bar2");

    //mainpanel *mp=new mainpanel();
    //mp->show();


   /* QByteArray data;
    data.append("param1-hello");
    data.append("&");
    data.append("param2-foo");

    mail.post("http://postman-echo.com/post",data);*/



    return a.exec();
}
