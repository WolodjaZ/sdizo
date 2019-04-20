//
// Created by vladimir on 06.04.19.
//

#ifndef PART_2_LIST_GRAPH_H
#define PART_2_LIST_GRAPH_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
//#include <string>

#include "PriorityQueue.h"
#include "Node.h"
#include "MST.h"
#include "QPG.h"
#include "MS.h"




class List_graph {
private:
    Node** list_table;
    bool directed;
    int start;
    int end;
    int edges;
    int verticles;

public:

    List_graph();
    ~List_graph();

    void readFromFile(std::string path, int algorithm);
    void generator(int vertex, int density_procent, int type, int max, int min);

    Node* getNeighboursList(int vertex);

    void Prims_algorithm();
    void Kruskal_algorithm();
    void Dijikstras_algorithm();
    void Bellmana_Forda_algorithm();
    void Ford_Fulkerson_algorithm();

    void print(Node** list, int size);

private:
    PriorityQueue* create_priority_queue();
    Node** create_list_from_edges(Edge *edge, int size);
    int random_vertex(bool* in_tree);
    void add_node(int startVertex, int endVertrx, int weight);
    bool exist_edge(int start, int end);
};


#endif //PART_2_LIST_GRAPH_H
