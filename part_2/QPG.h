//
// Created by vladimir on 12.04.19.
//

#ifndef PART_2_QPG_H
#define PART_2_QPG_H


#include "Edge.h"
#include "List_graph.h"
#include "PriorityQueue.h"
#include <iostream>

class QPG {
private:
    QPG();
    static const int MAXINT = 2147483647;
public:
    static Edge* Djikstry_algorithm(int** matrix, Node** list, int vertex, int start);

    static Edge* Forda_Belmana_algorithm(int** matrix, Node** list, int vertex, int start);
};


#endif //PART_2_QPG_H
