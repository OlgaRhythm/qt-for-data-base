#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include "list.h"
#include "smartphone.h"
#include "adddata.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("*" + filepath + " – Характеристики смартфонов");

    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Модель" << "Производитель" << "Цвет" << "Размер дисплея" << "Ёмкость батареи" << "Год выпуска");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->createItemAct->setToolTip("Сброс текущей таблицы");
    ui->exitAct->setToolTip("Выход из программы");
    ui->mergeAct->setToolTip("Добавить к текущей таблице уже существующую");
    ui->openItemAct->setToolTip("Открыть существующую базу данных");
    ui->saveItemAct->setToolTip("Записать базу данных на диск");
    ui->saveAsItemAct->setToolTip("Сохранить в другом файле");
    ui->addItemAct->setToolTip("Добавить запись в конец таблицы");
    ui->deleteItemAct->setToolTip("Удалить выделенную запись");
    ui->editItemAct->setToolTip("Редактировать запись");
    ui->findItemAct->setToolTip("Поиск по базе данных");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_aboutAct_triggered() //О программе
{
    QMessageBox::about(this, "Об авторе", "Курсовая работа по ООП\nВариант: 24\nТема: \"Класс, характеризующий смартфон\"\nИКПИ-14\nЯкубова Ольга");
}


void MainWindow::on_openItemAct_triggered() //Открыть
{
    if (ui->tableWidget->rowCount() > 0 || filepath != "") {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание");
        msgBox.setText("Вы уверены, что хотите выйти?\nВсе проделанные изменения не будут сохранены.");
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        if (msgBox.exec() == QMessageBox::Cancel) return;
    }

    filepath = QFileDialog::getOpenFileName(this, "Открытие файла", "D://OOP/kur_lab/Kur_lab/databases/", "TXT files (*.txt);;All files (*.*);;");
    QFileInfo file(filepath);

    if (file.exists() && file.isFile()) {
        if (ui->tableWidget->rowCount() > 0 || filepath != "") {
            ui->tableWidget->setRowCount(0);
            dataBase.clean();
        }

        QFile file(filepath);

        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                Smartphone item;
                QString line = in.readLine();
                QStringList fields = line.split(";");
                if (fields.size() == 6) {
                    item.setDeveloper(fields[1].simplified());
                    item.setModel(fields[0].simplified());
                    item.setColor(fields[2].simplified());
                    item.setDisplay(fields[3].simplified());
                    item.setBattery(fields[4].simplified());
                    item.setYear(fields[5].simplified());

                    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(item.getModel()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(item.getDeveloper()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(item.getColor()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem(item.getDisplay()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, new QTableWidgetItem(item.getBattery()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 5, new QTableWidgetItem(item.getYear()));
                    dataBase.push_back(item.getDeveloper(), item.getModel(), item.getColor(), item.getDisplay(), item.getBattery(), item.getYear());          
                }
            }
            file.close();
            ui->statusbar->showMessage("Записи из файла добавлены");
            setWindowTitle(filepath + " – Характеристики смартфонов");
        } else ui->statusbar->showMessage("Файл '" + filepath + "' не удалось открыть на чтение (" + file.errorString() + ")");
    } else ui->statusbar->showMessage("Файл '" + filepath + "' не существует");
}


void MainWindow::on_saveItemAct_triggered() //Сохранить
{
    if (filepath == "") {
        MainWindow::on_saveAsItemAct_triggered();
        return;
    }

    QFile file(filepath);

    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        int size = ui->tableWidget->rowCount();
        if (size != dataBase.getSize()) QMessageBox::warning(this, "debug", "size != dataBase size");

        for (int i = 0; (i < dataBase.getSize()) && (dataBase.get(i)!=NULL); i++){
            QString model = dataBase.get(i)->getModel();
            QString developer = dataBase.get(i)->getDeveloper();
            QString color = dataBase.get(i)->getColor();
            QString display = dataBase.get(i)->getDisplay();
            QString battery = dataBase.get(i)->getBattery();
            QString year = dataBase.get(i)->getYear();
            out << model << ";" << developer << ";" << color << ";" << display << ";" << battery << ";" << year << "\n";
        }
        file.close();
        ui->statusbar->showMessage("Файл записан");
        setWindowTitle(filepath + " – Характеристики смартфонов");
    }

}


void MainWindow::on_createItemAct_triggered() //Создать
{
    if (ui->tableWidget->rowCount() > 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание");
        msgBox.setText("Вы уверены, что хотите создать новый файл?\nВсе проделанные изменения не будут сохранены.");
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        if (msgBox.exec() == QMessageBox::Cancel) {
            return;
        }
    }

    ui->tableWidget->setRowCount(0);
    dataBase.clean();
    filepath = "";
    setWindowTitle("*" + filepath + " – Характеристики смартфонов");
}


void MainWindow::on_exitAct_triggered() //Выход
{
    if (ui->tableWidget->rowCount() > 0 || filepath != "") {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание");
        msgBox.setText("Вы уверены, что хотите выйти?\nВсе проделанные изменения не будут сохранены.");
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        if (msgBox.exec() == QMessageBox::Cancel) {
            return;
        }
    }
    exit(0);
}


void MainWindow::on_saveAsItemAct_triggered() //Сохранить как
{
    QString file_name = QFileDialog::getSaveFileName(this, "Сохранить файл...", ".", "TXT files (*.txt);;All files (*.*);;");
    if (file_name != "") {
        filepath = file_name;
        MainWindow::on_saveItemAct_triggered();
    }
}


void MainWindow::on_mergeAct_triggered() //Объединить
{
    filepath = QFileDialog::getOpenFileName(this, "Открытие файла", "D://OOP/kur_lab/Kur_lab/databases/", "TXT files (*.txt);;All files (*.*);;");
    QFileInfo file(filepath);

    if (file.exists() && file.isFile()) {

        QFile file(filepath);

        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                Smartphone item;
                QString line = in.readLine();
                QStringList fields = line.split(";");
                if (fields.size() == 6) {
                    item.setDeveloper(fields[0].simplified());
                    item.setModel(fields[1].simplified());
                    item.setColor(fields[2].simplified());
                    item.setDisplay(fields[3].simplified());
                    item.setBattery(fields[4].simplified());
                    item.setYear(fields[5].simplified());

                    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(item.getModel()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(item.getDeveloper()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(item.getColor()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem(item.getDisplay()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, new QTableWidgetItem(item.getBattery()));
                    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 5, new QTableWidgetItem(item.getYear()));
                    dataBase.push_back(item.getDeveloper(), item.getModel(), item.getColor(), item.getDisplay(), item.getBattery(), item.getYear());
                }
            }
            //qDebug () << dataBase.getSize() << "\n";
            file.close();
            ui->statusbar->showMessage("Записи из файла добавлены");
            setWindowTitle(filepath + " – Характеристики смартфонов");
        } else ui->statusbar->showMessage("Файл '" + filepath + "' не удалось открыть на чтение (" + file.errorString() + ")");
    } else ui->statusbar->showMessage("Файл '" + filepath + "' не существует");
} //Объединение


void MainWindow::on_addItemAct_triggered() //Добавить
{
    AddData myDialog;

    if (myDialog.exec() == QDialog::Accepted){
        Smartphone item = myDialog.getData();
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(item.getModel()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 1, new QTableWidgetItem(item.getDeveloper()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 2, new QTableWidgetItem(item.getColor()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, new QTableWidgetItem(item.getDisplay()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, new QTableWidgetItem(item.getBattery()));
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 5, new QTableWidgetItem(item.getYear()));

        dataBase.push_back(item.getDeveloper(), item.getModel(), item.getColor(), item.getDisplay(), item.getBattery(), item.getYear());
        ui->statusbar->showMessage("Запись добавлена");
        setWindowTitle("*" + filepath + " – Характеристики смартфонов");
    }
} //Добавление элемента



void MainWindow::on_deleteItemAct_triggered()
{
    auto list = ui->tableWidget->selectionModel()->selectedRows();

    if (list.size() > 0) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Внимание");
        msgBox.setText("Вы уверены, что хотите удалить строки с выбранными элементами?");
        msgBox.setIcon(QMessageBox::Question);
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        if (msgBox.exec() == QMessageBox::Ok) {
            for (auto k = list.rbegin(); k != list.rend(); ++k) {
                auto idx = (*k).row();
                dataBase.pop(idx);
                ui->tableWidget->removeRow(idx);
            }
            ui->statusbar->showMessage("Запись удалена");
            setWindowTitle("*" + filepath + " – Характеристики смартфонов");
        }
    } else ui->statusbar->showMessage("Ничего не выбрано");
} //Удаление элемента


void MainWindow::on_editItemAct_triggered()
{
    auto list = ui->tableWidget->selectedItems();
    if (list.size() > 0) {
        AddData myDialog;
        myDialog.setModel(list.at(0)->text());
        myDialog.setDeveloper(list.at(1)->text());
        myDialog.setColor(list.at(2)->text());
        myDialog.setDisplay(list.at(3)->text());
        myDialog.setBattery(list.at(4)->text());
        myDialog.setYear(list.at(5)->text());

        if (myDialog.exec() == QDialog::Accepted) {
            Smartphone item = myDialog.getData();
            list.at(0)->setText(item.getModel());
            list.at(1)->setText(item.getDeveloper());
            list.at(2)->setText(item.getColor());
            list.at(3)->setText(item.getDisplay());
            list.at(4)->setText(item.getBattery());
            list.at(5)->setText(item.getYear());

            dataBase.changeModel(list.at(0)->row(), item.getModel());
            dataBase.changeDeveloper(list.at(1)->row(), item.getDeveloper());
            dataBase.changeColor(list.at(2)->row(), item.getColor());
            dataBase.changeDisplay(list.at(3)->row(), item.getDisplay());
            dataBase.changeBattery(list.at(4)->row(), item.getBattery());
            dataBase.changeYear(list.at(5)->row(), item.getYear());

            ui->statusbar->showMessage("Запись изменена");
            setWindowTitle("*" + filepath + " – Характеристики смартфонов");
        }
    }
} //Редактирование элемента


int cur_row = -1;

void MainWindow::on_findItemAct_triggered()
{
    cur_row = -1;
    if (ui->tableWidget->rowCount() == 0) {
        ui->statusbar->showMessage("Таблица пуста");
        return;
    }

    QString text = ui->lineEdit->text();

    if (text == "") {
        ui->statusbar->showMessage("Строка поиска пуста");
        return;
    }

    int count = 0;
    int pr_count = 0;
    int rowcount = 0;
    QString mas[6];

    //ui->tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);

    for (int i = 0; (i < dataBase.getSize()) && (dataBase.get(i)!=NULL); i++){
        mas[0] = dataBase.get(i)->getModel();
        mas[1] = dataBase.get(i)->getDeveloper();
        mas[2] = dataBase.get(i)->getColor();
        mas[3] = dataBase.get(i)->getDisplay();
        mas[4] = dataBase.get(i)->getBattery();
        mas[5] = dataBase.get(i)->getYear();
        pr_count = count;
        for (int j = 0; j < 6; j++){
            if (mas[j] == text) {
                count++;
                if (ui->tableWidget->rowCount() > i) ui->tableWidget->selectRow(i);
            }
        }
        if (pr_count != count) rowcount++;
    }
    QString textcount = QString::number(count);
    QString textrowcount = QString::number(rowcount);

    if (count%10 == 1 && count != 11) {
        if (rowcount == 1) ui->statusbar->showMessage("Найдено " + textcount + " совпадение в 1 строкe");
        else ui->statusbar->showMessage("Найдено " + textcount + " совпадение в " + textrowcount + " строках");
    } else if (count%10 >= 2 && count%10 <= 4 && !(count > 11 && count < 15)) {
        if (rowcount == 1) ui->statusbar->showMessage("Найдено " + textcount + " совпадения в 1 строкe");
        else ui->statusbar->showMessage("Найдено " + textcount + " совпадения в " + textrowcount + " строках");
    } else {
        if (rowcount == 1) ui->statusbar->showMessage("Найдено " + textcount + " совпадений в 1 строкe");
        else ui->statusbar->showMessage("Найдено " + textcount + " совпадений в " + textrowcount + " строках");
    }

} //Поиск элемента

void MainWindow::on_pushButton_2_clicked()
{
    if (cur_row > ui->tableWidget->rowCount()) cur_row = -1;

    if (ui->tableWidget->rowCount() == 0) {
        ui->statusbar->showMessage("Таблица пуста");
        return;
    }

    QString text = ui->lineEdit->text();

    if (text == "") {
        ui->statusbar->showMessage("Строка поиска пуста");
        cur_row = -1;
        return;
    }

    int count = 0;
    int pr_count = 0;
    int rowcount = 0;
    QString mas[6];
    int cur_row_pr = cur_row;
    int cur_row_first = -1;
    for (int i = 0; (i < dataBase.getSize()) && (dataBase.get(i)!=NULL); i++){
        mas[0] = dataBase.get(i)->getModel();
        mas[1] = dataBase.get(i)->getDeveloper();
        mas[2] = dataBase.get(i)->getColor();
        mas[3] = dataBase.get(i)->getDisplay();
        mas[4] = dataBase.get(i)->getBattery();
        mas[5] = dataBase.get(i)->getYear();
        pr_count = count;
        for (int j = 0; j < 6; j++){
            if (mas[j] == text) {
                count++;
                if (cur_row_first == -1) cur_row_first = i;
                if ((ui->tableWidget->rowCount() > i) && (cur_row_pr == cur_row) && (cur_row < i)) {
                    ui->tableWidget->selectRow(i);
                    cur_row = i;
                }
            }
        }
        if (pr_count != count) rowcount++;
    }
    if (cur_row == cur_row_pr) {
        cur_row = cur_row_first;
        ui->tableWidget->selectRow(cur_row);
    }
    if (count == 0) {
        ui->tableWidget->clearSelection();
    }
    QString textcount = QString::number(count);
    QString textrowcount = QString::number(rowcount);
    if (rowcount == 1) ui->statusbar->showMessage("Найдено " + textcount + " совпадений в 1 строкe");
    ui->statusbar->showMessage("Найдено " + textcount + " совпадений в " + textrowcount + " строках");
    //qDebug() << cur_row;
} //Поиск: следующий

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    cur_row = -1;
} //Строка поиска изменилась



void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    ui->tableWidget->clearSelection();
}

