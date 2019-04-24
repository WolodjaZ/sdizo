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
#include "MS.h"


// Metody create.. , random, oraz wszystkie algorytmy mają tą samą budowe tak jak w liscię
// sąsiadów i tam znajdują się komentarze objaśniające funckjonowanie metod
class Matrix_graph {
    int vertex;
    int edges;
    bool directed;
    int start;
    int end;

    int** table_matrix;

public:
    Matrix_graph();
    ~Matrix_graph();

    void readFromFile(std::string path, int algorithm);
    void generator(int vertex, int density_procent, int type, int max, int min);
    int get(int start_vertex, int end_vertex);
    void print(int** matrix, int size);


    std::chrono::duration<double> Prims_algorithm();
    std::chrono::duration<double> Kruskal_algorithm();
    std::chrono::duration<double> Dijikstras_algorithm();
    std::chrono::duration<double> Bellmana_Forda_algorithm();
    std::chrono::duration<double> Ford_Fulkerson_algorithm();

private:
    PriorityQueue* create_priority_queue();
    int** create_matrix_from_edges(Edge *edge, int size);
    int random_vertex(bool* in_tree);
};


#endif //PART_2_MATRIX_GRAPH_H
