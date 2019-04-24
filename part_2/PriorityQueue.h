//
// Created by vladimir on 11.04.19.
//

#ifndef PART_2_PRIORITYQUEUE_H
#define PART_2_PRIORITYQUEUE_H

#include "Edge.h"
#include <iostream>


// Działanie PriorityQueue opiera się na kopcu gdzie na szczczycie jest minimalna liczba
// kopiec działa na obiektach klasy Edge gdzie wartość bierze ze zmiennej weigth
class PriorityQueue {
private:
    Edge* root;
    int size;
    int actual_size;
public:
    PriorityQueue(int size);
    ~PriorityQueue();


    Edge first();
    void push(Edge edge);
    void pop();
    bool is_Empty();

    // jedyna metoda objaśniona w cpp jako iż poprzednie metody były objaśnione w poprzednim projekcie
    void change_neighbours(int vertex, int value, int change_vertex);

    void print();


private:
    void queue_fix_up(int index);
    void queue_fix_down(int index);
    void print_helper(int index, int c);
};


#endif //PART_2_PRIORITYQUEUE_H
