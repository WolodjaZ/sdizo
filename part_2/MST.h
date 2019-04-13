//
// Created by vladimir on 12.04.19.
//

#ifndef PART_2_MST_H
#define PART_2_MST_H


#include "PriorityQueue.h"
#include "Spanning_Tree.h"

class MST {
private:
    MST() {};
public :

    static Edge* kruskal_algorithm(PriorityQueue* priorityQueue, int vetrex);

    static Edge* prim_algorithm(PriorityQueue* priorityQueue);
};


#endif //PART_2_MST_H
