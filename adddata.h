#ifndef ADDDATA_H
#define ADDDATA_H

#include <QDialog>
#include "smartphone.h"

namespace Ui {
class AddData;
}

class AddData : public QDialog
{
    Q_OBJECT

public:
    explicit AddData(QWidget *parent = nullptr);
    ~AddData();

    Smartphone getData();

    void setDeveloper(QString arg);
    void setModel(QString arg);
    void setColor(QString arg);
    void setDisplay(QString arg);
    void setBattery(QString arg);
    void setYear(QString arg);

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddData *ui;
};

#endif // ADDDATA_H
