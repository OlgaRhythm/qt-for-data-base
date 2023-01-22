#ifndef BDMENU_H
#define BDMENU_H


#include "qstatusbar.h"
#include "qtablewidget.h"

class BDMenu
{
private:
    QStatusBar *statusBar;// – строка состояния
    QTableWidget *tableWidget;// – таблица базы данных
    QLineEdit *findLineEdit; //– поиск
    Vector<AirPLane> database;// – база данных
    QString filename;// – хранит путь у файлу

public:
    BDMenu();
};

#endif // BDMENU_H
