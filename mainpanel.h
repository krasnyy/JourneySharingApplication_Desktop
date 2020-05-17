#ifndef MAINPANEL_H
#define MAINPANEL_H

#include <QWidget>

namespace Ui {
class mainpanel;
}

class mainpanel : public QWidget
{
    Q_OBJECT

public:
    explicit mainpanel(QWidget *parent = nullptr);
    ~mainpanel();

private slots:
    void showTime();

private:
    Ui::mainpanel *ui;
};

#endif // MAINPANEL_H
