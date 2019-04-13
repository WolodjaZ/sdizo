//
// Created by vladimir on 06.04.19.
//

#ifndef PART_2_LIST_GRAPH_H
#define PART_2_LIST_GRAPH_H

#include <fstream>
#include <iostream>
#include <iomanip>

#include "PriorityQueue.h"
#include "MST.h"

class List_graph {
public:
    struct Node{
        Node* next_element;
        int vetrex;
        int weight;
    };
private:
    Node** list_table;
    bool directed;
    int edges;
    int verticles;

public:

    List_graph();
    ~List_graph();

    void readFromFile(std::string path, std::string type);

    Node* getNeighboursList(int vertex);

    void Prims_algorithm();
    void Kruskal_algorithm();
    void Dijikstras_algorithm();

    void print(Node** list);

private:
    PriorityQueue* create_priority_queue();
    Node** create_list_from_edges(Edge *edge, int size);
};


#endif //PART_2_LIST_GRAPH_H
