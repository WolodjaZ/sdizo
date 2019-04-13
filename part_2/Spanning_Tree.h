//
// Created by vladimir on 07.04.19.
//

#ifndef PART_2_SPANNING_TREE_H
#define PART_2_SPANNING_TREE_H


#include "Edge.h"
#include "List_graph.h"

class Spanning_Tree {
private:
    struct St{
        int up,rank;
    };
    St *vetrexs;
    int size;
public:
    Spanning_Tree(int vetrex);
    ~Spanning_Tree();

    void MakeSet(int vetrex);

    int FindSet(int vetrex);

    void UnionSets(Edge e);
};


#endif //PART_2_SPANNING_TREE_H
