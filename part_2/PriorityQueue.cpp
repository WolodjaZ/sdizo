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
    if(actual_size == 0) return;
    if(actual_size-1 == 0){
        this->root = nullptr;
    } else{
        *(this->root) = *(this->root+this->actual_size-1);
    }
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

bool PriorityQueue::is_Empty() {
    return actual_size > 1? false: true;
}

void PriorityQueue::queue_fix_down(int index) {
    int p, l = 2*index+1;
    while (index < this->actual_size){
        p = l+1;
        int min = index;
        if(l < this->actual_size && (*(this->root+l)).weight < (*(this->root+index)).weight){
            min = l;
        }
        if(p < this->actual_size && (*(this->root+p)).weight < (*(this->root+min)).weight){
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
    this->print_helper(0, 0);
    std::cout << std::endl;
}

// metoda modyfikuje wierzchołek vertex sąsiada change_vertex
void PriorityQueue::change_neighbours(int vertex, int value, int change_vertex) {
    // szuakmy krawędzi która ma wartość vertex w endVertex
    // przechodzimy po tablicy kopca po koleji
    for(int a = 0; a < this->actual_size; a++){
        if((*(this->root+a)).endVertex == vertex){
            // kiedy znajdujemy krawędź sprawdzamy czy jej waga jest większa od value
            // jeśli tak to zamieniamy wage na value i startVertex ma change_vertex
            // i kończymy
            if((*(this->root+a)).weight > value){
                (*(this->root+a)).weight = value;
                (*(this->root+a)).startVertex = change_vertex;
                queue_fix_up(a);
                queue_fix_down(a);
            }
            return;
        }
    }
}



void PriorityQueue::print_helper(int index, int c){
    c++;
    if(index < this->actual_size){


        print_helper( 2*index+1, c);
        // przechodzimy lewe poddrzewo
        std::cout << "Początkowy:" << this->root[index].startVertex << " koncowy:" << this->root[index].endVertex << " waga:" << this->root[index].weight << " " << c <<", "; // odwiedzamy węzeł

        print_helper( 2*index+2, c);      // przechodzimy prawe poddrzewo
    }
    c--;
}