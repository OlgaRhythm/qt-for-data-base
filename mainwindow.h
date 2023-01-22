#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "list.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_aboutAct_triggered();

    void on_openItemAct_triggered();

    void on_saveItemAct_triggered();

    void on_addItemAct_triggered();

    void on_createItemAct_triggered();

    void on_exitAct_triggered();

    void on_saveAsItemAct_triggered();

    void on_mergeAct_triggered();

    void on_deleteItemAct_triggered();

    void on_editItemAct_triggered();

    void on_findItemAct_triggered();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    QString filepath = "";
    List dataBase;
};
#endif // MAINWINDOW_H
