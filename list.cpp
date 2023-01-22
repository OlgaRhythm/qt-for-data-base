#include "list.h"

//СПИСОК

Smartphone* List :: get_front(){
    if (head != NULL) return (head);
    else return NULL;
}//получение значения верхнего узла

Smartphone* List :: get_back(){
    return get(size-1);
}//получение значения верхнего узла

Smartphone* List :: get(int idx){
    if ((size != 0) || (head != NULL)) {
        if (idx == 0){
            return get_front();
        }
        if (idx < size){
            Smartphone* ptr = head;
            for (int i = 0; i < idx; i++){
                ptr = ptr->getNext();
                if (ptr == NULL){
                    return NULL;
                }
            }
            return ptr;
        }
    }
    return NULL;
}//получение значения верхнего узла

List :: List():head(NULL), size(0){}//конструктор по умолчанию (создание пустого контейнера)

List :: List(QString developer_, QString model_, QString color_, QString display_, QString battery_, QString year_):head(new Smartphone(developer_, model_, color_, display_, battery_, year_, NULL)),size(1){}//конструктор с параметрами

List :: ~List(){
    if (head != NULL){
    Smartphone* ptr = head;
        while (ptr!=NULL){
            head = ptr->getNext();
            delete ptr;
            ptr = head;
        }
    }
}//деструктор

List :: List(const List& A){
    size = 0;
    head = NULL;
    Smartphone* ptr = A.head;
    for (int i = 0; (i < size) && (ptr != NULL); i++){
        QString developer_ = ptr->getDeveloper();
        QString model_ = ptr->getModel();
        QString color_ = ptr->getColor();
        QString display_ = ptr->getDisplay();
        QString battery_ = ptr->getBattery();
        QString year_ = ptr->getYear();
        push_front(developer_, model_, color_, display_, battery_, year_);
        ptr = ptr->getNext();
    }
}//конструкторо копирования

void List :: push_front(QString developer_, QString model_, QString color_, QString display_, QString battery_, QString year_){
    Smartphone* A = new Smartphone(developer_, model_, color_, display_, battery_, year_, head);
    head = A;
    size++;
}//добавление нового узла в начало списка

void List :: push_back(QString developer_, QString model_, QString color_, QString display_, QString battery_, QString year_){
    if (head == NULL){
        Smartphone* A = new Smartphone(developer_, model_, color_, display_, battery_, year_, NULL);
        head = A;
        size++;
    } else {
        Smartphone* ptr = head;
        while (ptr->getNext() != NULL){
            ptr = ptr->getNext();
        }
        Smartphone* A = new Smartphone(developer_, model_, color_, display_, battery_, year_, NULL);
        ptr->setNext(A);
        size++;
    }
}//добавление нового узла в конце списка

bool List :: push(int idx, QString developer_, QString model_, QString color_, QString display_, QString battery_, QString year_){
    if (idx <= size){
        if (idx <= 0) {
            push_front(developer_, model_, color_, display_, battery_, year_);
            return true;
        }
        if (idx >= size) {
            push_back(developer_, model_, color_, display_, battery_, year_);
            return true;
        }
        Smartphone* ptr = head;
        for (int i = 0; i < idx-1; i++){
            ptr = ptr->getNext();
            if (ptr == NULL){
                return false;
            }
        }
        Smartphone* A = new Smartphone(developer_, model_, color_, display_, battery_, year_, ptr->getNext());
        ptr->setNext(A);
        size++;
    } else {
        push_back(developer_, model_, color_, display_, battery_, year_);
        return true;
    }
    return false;
}//добавление нового узла в середину списка

bool List :: pop_front(){
    if ((size != 0) || (head != NULL)){
        Smartphone* A = head;
        head = A->getNext();
        delete A;
        size--;
        return true;
    } else return false;
}//удаление узла из начала списка

bool List :: pop_back(){
    if ((size != 0) || (head != NULL)) {
        size--;
        Smartphone* ptr = head;
        while (ptr->getNext()->getNext() != NULL){
            ptr = ptr->getNext();
        }
        delete ptr->getNext();
        ptr->setNext(NULL);
        return true;
    } else return false;
}//удаление узла из конца списка

bool List :: pop(int idx){
    if ((size != 0) || (head != NULL)) {
        if (idx == 0){
            return pop_front();
        }
        if (idx == size-1){
            return pop_back();
        }
        if (idx < size){
            Smartphone* ptr = head;
            for (int i = 0; i < idx-1; i++){
                ptr = ptr->getNext();
                if (ptr == NULL){
                    return false;
                }
            }
            Smartphone* ptr_next = ptr->getNext()->getNext();
            delete ptr->getNext();
            ptr->setNext(ptr_next);
            size--;
            return true;
        }
    }
    return false;
}//удаление узла из середины списка

void List :: clean(){
    int n = size;
    for (int i = 0; i < n; i++){
        pop_front();
    }
    return;
}//очистка списка

int List :: getSize(){
    return size;
}//получение размера

bool List :: isEmpty(){
    return (size == 0);
}//проверка на нулевой размер

bool List :: changeDeveloper(int idx, QString developer){
    Smartphone* ptr = get(idx);
    if (ptr == NULL) return false;
    ptr->setDeveloper(developer);
    return true;
}//изменить элемент по индексу - производитель

bool List :: changeModel(int idx, QString a){
    Smartphone* ptr = get(idx);
    if (ptr == NULL) return false;
    ptr->setModel(a);
    return true;
}//изменить элемент по индексу - модель

bool List :: changeColor(int idx, QString a){
    Smartphone* ptr = get(idx);
    if (ptr == NULL) return false;
    ptr->setColor(a);
    return true;
}//изменить элемент по индексу - цвет

bool List :: changeDisplay(int idx, QString a){
    Smartphone* ptr = get(idx);
    if (ptr == NULL) return false;
    ptr->setDisplay(a);
    return true;
}//изменить элемент по индексу - размер дисплея

bool List :: changeBattery(int idx, QString a){
    Smartphone* ptr = get(idx);
    if (ptr == NULL) return false;
    ptr->setBattery(a);
    return true;
}//изменить элемент по индексу - ёмкость батареи

bool List :: changeYear(int idx, QString a){
    Smartphone* ptr = get(idx);
    if (ptr == NULL) return false;
    ptr->setYear(a);
    return true;
}//изменить элемент по индексу - год

