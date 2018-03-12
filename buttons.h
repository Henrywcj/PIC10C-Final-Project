#ifndef BUTTONS_H
#define BUTTONS_H

#include <QWidget>
#include<QApplication>
#include <QPushButton>
#include <QBoxLayout>
namespace Ui {
class Buttons;
}

class Buttons : public QWidget
{
    Q_OBJECT

public:
    explicit Buttons(QWidget *parent = 0);
    ~Buttons();
public slots:
    void addLevels();
private:
    QPushButton* start;
    QPushButton* help;
    QPushButton* exit;
    Ui::Buttons *ui;
};

#endif // BUTTONS_H
