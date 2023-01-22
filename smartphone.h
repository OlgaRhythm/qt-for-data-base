#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include <qstring.h>

class Smartphone
{
    public:
        Smartphone();//конструктор по умолчанию
        Smartphone(QString developer, QString model, QString color, QString display, QString battery, QString year, Smartphone* next);//конструктор с параметрами
        Smartphone (const Smartphone &A);//конструктор копирования
        virtual ~Smartphone();//деструктор
        //перегрузка оператора присваивания
        Smartphone operator= (Smartphone A);

        //установка производителя
        void setDeveloper (QString);
        //получение производителя
        QString getDeveloper ();
        //установка модели
        void setModel (QString);
        //получение модели
        QString getModel ();
        //установка цвета
        void setColor (QString);
        //получение цвета
        QString getColor ();
        //установка размера дисплея
        void setDisplay (QString);
        //получение размера дисплея
        QString getDisplay ();
        //установка ёмкости батареи
        void setBattery (QString);
        //получение ёмкости батареи
        QString getBattery ();
        //установка года выпуска
        void setYear (QString);
        //получение года выпуска
        QString getYear ();
        //установка указателя
        void setNext (Smartphone*);
        //получение указателя
        Smartphone* getNext ();

    protected:

    private:
        QString developer; //производитель
        QString model;//название модели
        QString color;//цвет
        QString display;//размер дисплея, см
        QString battery;//ёмкость батареи
        QString year;//год выпуска
        Smartphone *next;//указатель на следующий узел

};

#endif // SMARTPHONE_H
