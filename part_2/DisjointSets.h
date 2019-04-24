//
// Created by vladimir on 07.04.19.
//

#ifndef PART_2_DISJOINTSETS_H
#define PART_2_DISJOINTSETS_H


#include "Edge.h"
#include "List_graph.h"

// klasa zbiorów rozłącznych
class DisjointSets {
private:
    // struktura która posiada informacje o
    struct St{
        int up,rank; // up ma informcje o korzeniu zbioru rank o randze drzewa
    };
    St *vetrexs;
public:
    DisjointSets(int vetrex);
    ~DisjointSets();

    void MakeSet(int vetrex);

    int FindSet(int vetrex);

    void UnionSets(Edge e);
};


#endif //PART_2_DISJOINTSETS_H
