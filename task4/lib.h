#ifndef DSAA_LIB_H
#define DSAA_LIB_H

#include <iostream>

int linearSearch(int* arr, int size, int toFind, unsigned long long& C) {
    if (size != 0) {
        C++;
        int last = arr[size - 1]; //Сохраним прежний элемент массива
        arr[size - 1] = toFind; //Гарантируем, что value есть в массиве
        //Есть гарантия того, что элемент есть в массиве, значит индекс можно не проверять
        int i = 0;
        for (; arr[i] != toFind; ++i) { //Одно условие в цикле
            C++;
        }
        arr[size - 1] = last; //Восстанавливаем последний элемент
        C++;
        if (i != (size - 1) || toFind == last) { //Не уткнулись в барьер или последний элемент был искомым
            return i;
        }
    }
    return -1;
}

#endif
