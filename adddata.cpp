#include "adddata.h"
#include "ui_adddata.h"

AddData::AddData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddData)
{
    ui->setupUi(this);
    setWindowTitle("Редактор записи");
}

AddData::~AddData()
{
    delete ui;
}

Smartphone AddData :: getData(){
    Smartphone item;
    item.setModel(ui->lineEdit->text().simplified().replace(";", ","));
    item.setDeveloper(ui->lineEdit_2->text().simplified().replace(";", ","));
    item.setColor(ui->lineEdit_3->text().simplified().replace(";", ","));
    item.setDisplay(ui->lineEdit_4->text().simplified().replace(";", ","));
    item.setBattery(ui->lineEdit_5->text().simplified().replace(";", ","));
    item.setYear(ui->lineEdit_6->text().simplified().replace(";", ","));

    return item;
}

void AddData :: setDeveloper(QString arg){
    ui->lineEdit_2->setText(arg);
}

void AddData :: setModel(QString arg){
    ui->lineEdit->setText(arg);
}

void AddData :: setColor(QString arg){
    ui->lineEdit_3->setText(arg);
}

void AddData :: setDisplay(QString arg){
    ui->lineEdit_4->setText(arg);
}

void AddData :: setBattery(QString arg){
    ui->lineEdit_5->setText(arg);
}

void AddData :: setYear(QString arg){
    ui->lineEdit_6->setText(arg);
}


void AddData::on_buttonBox_accepted()
{
    accept();
}


void AddData::on_buttonBox_rejected()
{
    reject();
}

