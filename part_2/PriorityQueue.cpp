//
// Created by vladimir on 11.04.19.
//

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int size) {
    this->size = size;
    this->root = new Edge [size];
    this->actual_size = 0;
}

PriorityQueue::~PriorityQueue() {
    delete[] root;
    this->size = 0;
    this->actual_size = 0;
}

void PriorityQueue::push(Edge edge) {
    if(this->size > this->actual_size){

        *(this->root+this->actual_size) = edge;
        this->actual_size++;

        this->queue_fix_up(this->actual_size-1);

    }
}

Edge PriorityQueue::first() {
    return *root;
}

void PriorityQueue::pop() {
    *(this->root) = *(this->root+this->actual_size-1);
    this->actual_size--;
    queue_fix_down(0);

}

void PriorityQueue::queue_fix_up(int index) {
    while (index > 0){
        int parent = (index-1)/2;
        if((this->root+parent)->weight <= (this->root+index)->weight){
            return;
        }
        Edge buf = *(this->root+index);
        *(this->root+index) = *(this->root+parent);
        *(this->root+parent) = buf;
        index = parent;
    }
}


void PriorityQueue::queue_fix_down(int index) {
    int p, l = 2*index+1;
    while (index < this->actual_size){
        p = l+1;
        int min = index;
        if(l < this->actual_size && (*(this->root+l)).weight < (*(this->root+index)).weight){
            min = l;
        }
        if(p < this->actual_size && (*(this->root+p)).weight > (*(this->root+min)).weight){
            min = p;
        }
        if(min == index){
            return;
        }
        Edge buf = *(this->root+index);
        *(this->root+index) = *(this->root+min);
        *(this->root+min) = buf;
        index = min;
        l = 2*index+1;
    }
}

void PriorityQueue::print() {
    this->print_helper(0);
    std::cout << std::endl;
}

void PriorityQueue::print_helper(int index){
    if(index < this->actual_size){

        print_helper( 2*index+1);
        // przechodzimy lewe poddrzewo
        std::cout << "Początkowy:" << this->root[index].startVertex << " koncowy:" << this->root[index].endVertex << " waga:" << this->root[index].weight << ", "; // odwiedzamy węzeł

        print_helper( 2*index+2);      // przechodzimy prawe poddrzewo
    }
}