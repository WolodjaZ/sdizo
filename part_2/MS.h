//
// Created by vladimir on 18.04.19.
//

#ifndef PART_2_MS_H
#define PART_2_MS_H

#include <iostream>
#include <cstring>

#include "List_graph.h"
#include "Matrix_graph.h"

class MS {
private:
    Node** list;
    int** matrix;
    int start;
    int end;
    int size;
public:
    MS(int **matrix, Node **list , int start, int end, int size);

    virtual ~MS();

    int Ford_Fulkerson_algorithm();


private:
    bool DFS_matrix(int** graph, int* prev, bool* visited, int n, int x, int t);
    bool DFS_list(Node** list, int* prev, bool* visited, int n, int x, int t);
};


#endif //PART_2_MS_H
