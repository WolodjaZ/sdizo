//
// Created by vladimir on 07.04.19.
//

#include "Spanning_Tree.h"

Spanning_Tree::Spanning_Tree(int vetrexs) {
    this->vetrexs = new Spanning_Tree::St[vetrexs];
}

Spanning_Tree::~Spanning_Tree() {
    delete[] vetrexs;
}

void Spanning_Tree::MakeSet(int vetrex) {
    vetrexs[vetrex].up = vetrex;
    vetrexs[vetrex].rank = 0;
}

int Spanning_Tree::FindSet(int vetrex) {
    if(vetrexs[vetrex].up != vetrex) vetrexs[vetrex].up = FindSet(vetrexs[vetrex].up);
    return vetrexs[vetrex].up;
}

void Spanning_Tree::UnionSets(Edge e) {
    int root_v, root_u;

    root_u = FindSet(e.startVertex);
    root_v = FindSet(e.endVertex);
    if(root_u != root_v){
        if(vetrexs[root_u].rank > vetrexs[root_v].rank){
            vetrexs[root_v].up = root_u;
        } else{
            vetrexs[root_u].up = root_v;
            if(vetrexs[root_u].rank == vetrexs[root_v].rank) vetrexs[root_v].rank++;
        }
    }
}
