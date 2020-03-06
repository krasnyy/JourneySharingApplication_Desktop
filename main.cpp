#include "mainwindow.h"
#include "loginwindow.h"
#include "usermailwindow.h"
#include <QApplication>
#include"mailsender.h"
#include<QByteArray>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    usermailwindow ww;
    ww.show();
   /* mailSender mail;

   // mail.get("http://postman-echo.com/get?fool-bar1&foo2=bar2");




    QByteArray data;
    data.append("param1-hello");
    data.append("&");
    data.append("param2-foo");

    mail.post("http://postman-echo.com/post",data);*/



    return a.exec();
}
