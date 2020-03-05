#include "usermailwindow.h"
#include "ui_usermailwindow.h"
#include "mailsender.h"

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

void usermailwindow::on_pushButton_2_clicked()
{

    mailSender mail;


}
