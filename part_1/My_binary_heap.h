//
// Created by vladimir on 16.03.19.
//

#ifndef PART_1_MY_BINARY_HEAP_H
#define PART_1_MY_BINARY_HEAP_H

#include <clocale>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <chrono>


class My_binary_heap {
    int size;
    int real_size;
    int *root;
public:
    My_binary_heap(int size);
    ~My_binary_heap();

    int find(int value);

    void add(int value);
    void remove(int value);

    void print();

    void print2();


    void create_random(int real_size ,int size, int minimum, int maximum);

    void create_from_a_file(int size ,std::string name);

private:
    void heap_fix_down(int index);

    void heap_fix_up(int index);

    void heap_create();

    void print2help(int index, int in);
};


#endif //PART_1_MY_BINARY_HEAP_H