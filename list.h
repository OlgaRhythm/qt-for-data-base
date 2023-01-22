#ifndef LIST_H
#define LIST_H

#include "smartphone.h"
#include <cstddef>
#include <QString>

//список
class List {
private:
    Smartphone* head;//указатель на верхний (первый) узел в списке
    int size;//размер списка

protected:

public:
    friend class Iterator;

    List();//конструктор по умолчанию (создание пустого контейнера)

    List(QString developer_, QString model_, QString color_, QString display_, QString battery_, QString year_);//конструктор с параметрами

    ~List();//деструктор

    List(const List& A);//конструкторо копирования

    void push_front(QString developer_, QString model_, QString color_, QString display_, QString battery_, QString year_);//добавление нового узла в начало списка

    void push_back(QString developer_, QString model_, QString color_, QString display_, QString battery_, QString year_);//добавление нового узла в конце списка

    bool push(int idx, QString developer_, QString model_, QString color_, QString display_, QString battery_, QString year_);//добавление нового узла в середину списка

    bool pop_front();//удаление узла из начала списка

    bool pop_back();//удаление узла из конца списка

    bool pop(int idx);//удаление узла из середины списка

    Smartphone* get_front();//получение значения верхнего узла

    Smartphone* get_back();//получение значения верхнего узла

    Smartphone* get(int idx);//получение значения верхнего узла

    void clean();//очистка списка

    int getSize();//получение размера

    bool isEmpty();//проверка на нулевой размер

    bool changeDeveloper(int idx, QString developer);//изменить элемент по индексу - производитель

    bool changeModel(int idx, QString a);//изменить элемент по индексу - модель

    bool changeColor(int idx, QString a);//изменить элемент по индексу - цвет

    bool changeDisplay(int idx, QString a);//изменить элемент по индексу - размер дисплея

    bool changeBattery(int idx, QString a);//изменить элемент по индексу - ёмкость батареи

    bool changeYear(int idx, QString a);//изменить элемент по индексу - год

    //ИТЕРАТОР ДЛЯ СПИСКА
    class Iterator;

    Iterator begin() {
        return Iterator(head);
    }//итератор начала

    Iterator end() {
        return Iterator(NULL);
    }//итератор конца

    class Iterator{
        friend class List;
    private:
        Smartphone* cur;
    public:

        Iterator(Smartphone* node):cur(node){}

        Iterator& operator+ (int n){
            for (int i = 0; (cur != NULL) && (i < n); i++){
                cur = cur->getNext();
            }
            return *this;
        }

        Iterator& operator++ (){
            if (cur != NULL){
                cur = cur->getNext();
                return *this;
            }
            return *this;
        }

        Iterator& operator++ (int){
            if (cur != NULL){
                cur = cur->getNext();
                return *this;
            }
            return *this;
        }

        bool operator!= (const Iterator& it){
            return cur != it.cur;
        }

        bool operator< (const Iterator& it){
            return cur != it.cur;
        }

        bool operator== (const Iterator& it){
            return cur == it.cur;
        }

        QString getModel (){
            return cur->getModel();
        }

        QString getDeveloper (){
            return cur->getDeveloper();
        }

        QString getColor (){
            return cur->getColor();
        }

        QString getDisplay (){
            return cur->getDisplay();
        }

        QString getBattery (){
            return cur->getBattery();
        }

        QString getYear (){
            return cur->getYear();
        }

    };
};


#endif // LIST_H
