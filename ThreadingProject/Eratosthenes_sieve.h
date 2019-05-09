//
// Created by vladimir on 24.04.19.
//

#ifndef UNTITLED_ERATOSTHENES_SIEVE_H
#define UNTITLED_ERATOSTHENES_SIEVE_H

#include <thread>
#include "List.h"
#include <mutex>
#include <vector>
#include <chrono>


class Eratosthenes_sieve {
private:
    int *tab;
    double time1;
    int size;
    std::thread* threadVect;
    int thread_size;

    List first;

    std::mutex vectLock;

public:
    Eratosthenes_sieve(int interval, int thread_size);
    ~Eratosthenes_sieve();

    void start();


    void print();

    double time();

private:
    void first_numbers(int index);


};


#endif //UNTITLED_ERATOSTHENES_SIEVE_H
