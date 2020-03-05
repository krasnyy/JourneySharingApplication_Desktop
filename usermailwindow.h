#ifndef USERMAILWINDOW_H
#define USERMAILWINDOW_H

#include <QDialog>

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

private:
    std::string t_itle;
    std::string m_essage;
    Ui::usermailwindow *ui;
};

#endif // USERMAILWINDOW_H
