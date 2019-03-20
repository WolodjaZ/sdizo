//
// Created by vladimir on 15.03.19.
//

#ifndef PART_1_MY_ARRAY2_H
#define PART_1_MY_ARRAY2_H

#include <clocale>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include <chrono>



class My_array2{
    int* head;
    int length;
public:

    My_array2();
    ~My_array2();

    void push_front(int data);
    int pop_front();

    void push_tail(int data);
    int pop_tail();

    int find(int data);
    int get(int index);
    void add(int index, int data);
    void remove(int index);

    void print();

    void create_random(int size, int minimum, int maximum);

    void create_from_a_file(std::string name);
};

#endif //PART_1_MY_ARRAY2_H
