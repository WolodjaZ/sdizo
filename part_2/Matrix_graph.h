//
// Created by vladimir on 06.04.19.
//

#ifndef PART_2_MATRIX_GRAPH_H
#define PART_2_MATRIX_GRAPH_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "PriorityQueue.h"
#include "MST.h"

class Matrix_graph {
    int vertex;
    int edges;
    bool directed;

    int** table_matrix;

public:
    Matrix_graph();
    ~Matrix_graph();

    void readFromFile(std::string path, std::string type);

    int get(int start_vertex, int end_vertex);
    void print(int** matrix);


    void Prims_algorithm();
    void Kruskal_algorithm();
    void Dijikstras_algorithm();

private:
    PriorityQueue* create_priority_queue();
    int** create_matrix_from_edges(Edge *edge, int size);
};


#endif //PART_2_MATRIX_GRAPH_H
