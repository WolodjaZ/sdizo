//
// Created by vladimir on 24.04.19.
//

#include "Eratosthenes_sieve.h"

Eratosthenes_sieve::Eratosthenes_sieve(int interval, int thread_size) {
    this->thread_size = thread_size;
    size = interval;
    tab = new int [size-2];
    threadVect = new std::thread [thread_size];
    for(int a = 2; a < size; a++) { tab[a-2] = a;}

}

Eratosthenes_sieve::~Eratosthenes_sieve() {
    delete[] tab;
    delete[] threadVect;
}

void Eratosthenes_sieve::start() {
    auto start = std::chrono::system_clock::now();
    for(int a = 0; a < thread_size; a++) {
        //threadVect.emplace_back(&Eratosthenes_sieve::first_numbers,0);
        threadVect[a] = std::thread(&Eratosthenes_sieve::first_numbers, this, 0);
    }

    for(int a = 0; a < thread_size; a++){
        threadVect[a].join();
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    time1 = elapsed_seconds.count();
}

 void Eratosthenes_sieve::first_numbers(int index) {
     if(index >= size-2) return;
     if(tab[index] != 0){
         vectLock.lock();
         if(!first.find_by_value(index)){
             first.push_front(index);
             vectLock.unlock();
             int a = index;
             while(a <= size-2){
                 if(a != index){
                     tab[a] = 0;
                 }
                 a += (index+2);
             }

             vectLock.lock();
             first.remove_by_value(index);
             vectLock.unlock();
         } else{
             vectLock.unlock();
         }
    }

    first_numbers(index+1);
}

void Eratosthenes_sieve::print() {
    for(int a = 2; a < size; a++){
        if(tab[a-2] != 0)
        std::cout << tab[a-2] << std::endl;
    }
    std::cout << "Time: " << time1 << std::endl;
}

double Eratosthenes_sieve::time() {
    return time1;
}
