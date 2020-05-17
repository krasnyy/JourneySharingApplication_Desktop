#include "mainpanel.h"
#include "ui_mainpanel.h"
#include<QTimer>
#include<QDateTime>


mainpanel::mainpanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainpanel)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}
void mainpanel::showTime(){
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    QDateTime dateTime=QDateTime::currentDateTime();

    QString date_text=time.toString("dd.MM.yyyy");
    ui->Digital_clock->setText(time_text);
}
mainpanel::~mainpanel()
{
    delete ui;
}
