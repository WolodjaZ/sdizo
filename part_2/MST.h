//
// Created by vladimir on 12.04.19.
//

#ifndef PART_2_MST_H
#define PART_2_MST_H


#include "PriorityQueue.h"
#include "Spanning_Tree.h"
#include "List_graph.h"
#include "Matrix_graph.h"

class MST {
private:
    MST();
public :

    static Edge* kruskal_algorithm(PriorityQueue* priorityQueue, int vetrex);

    static Edge* prim_algorithm(int** matrix, Node** list, int vertex, int edges);
};


#endif //PART_2_MST_H
