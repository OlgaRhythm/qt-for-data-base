#include "smartphone.h"

    Smartphone :: Smartphone(){
        developer = ""; //производитель
        model = "";//название модели
        color = "";//цвет
        display = "";//размер дисплея, см
        battery = "";//ёмкость батареи
        year = "";//год выпуска
        next = NULL;
    }//конструктор по умолчанию

    Smartphone :: Smartphone(QString de, QString m, QString c, QString di, QString b, QString y, Smartphone* next_){
        developer = de; //производитель
        model = m;//название модели
        color = c;//цвет
        display = di;//размер дисплея, см
        battery = b;//ёмкость батареи
        year = y;//год выпуска
        next = next_;
    }//конструктор с параметрами

    Smartphone :: Smartphone (const Smartphone &A){
        developer = A.developer; //производитель
        model = A.model;//название модели
        color = A.color;//цвет
        display = A.display;//размер дисплея, см
        battery = A.battery;//ёмкость батареи
        year = A.year;//год выпуска
        next = A.next;
    }//конструктор копирования

    Smartphone :: ~Smartphone(){
        next = NULL;
    }//деструктор

    //перегрузка оператора присваивания
    Smartphone Smartphone :: operator= (Smartphone A){
        developer = A.developer; //производитель
        model = A.model;//название модели
        color = A.color;//цвет
        display = A.display;//размер дисплея, см
        battery = A.battery;//ёмкость батареи
        year = A.year;//год выпуска
        //next = A.next;
        return (*this);
    }

    //оператор получения элемента по индексу
 //   Smartphone :: QString &operator[](int i){}
    //очистка массива
 //   void clear();

    //установка производителя
    void Smartphone :: setDeveloper (QString de){
        developer = de;
    }
    //получение производителя
    QString Smartphone :: getDeveloper (){
        return developer;
    }
    //установка модели
    void Smartphone :: setModel (QString m){
        model = m;
    }
    //получение модели
    QString Smartphone :: getModel (){
        return model;
    }
    //установка цвета
    void Smartphone :: setColor (QString c){
        color = c;
    }
    //получение цвета
    QString Smartphone :: getColor (){
        return color;
    }
    //установка размера дисплея
    void Smartphone :: setDisplay (QString di){
        display = di;
    }
    //получение размера дисплея
    QString Smartphone :: getDisplay (){
        return display;
    }
    //установка ёмкости батареи
    void Smartphone :: setBattery (QString b){
        battery = b;
    }
    //получение ёмкости батареи
    QString Smartphone :: getBattery (){
        return battery;
    }
    //установка года выпуска
    void Smartphone :: setYear (QString y){
        year = y;
    }
    //получение года выпуска
    QString Smartphone :: getYear (){
        return year;
    }
    void Smartphone :: setNext (Smartphone* n){
        next = n;
    }
    //получение указателя
    Smartphone* Smartphone :: getNext (){
        return next;
    }
