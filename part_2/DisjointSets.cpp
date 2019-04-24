//
// Created by vladimir on 07.04.19.
//

#include "DisjointSets.h"

// Konstrukutro Tworzymy tablice zbiorów o wielkości ilości wierzchołków
DisjointSets::DisjointSets(int vetrexs) {
    this->vetrexs = new DisjointSets::St[vetrexs];
}

// Destruktor usuwa tablice zbiorów
DisjointSets::~DisjointSets() {
    delete[] vetrexs;
}

// tworzymy jedno elementowy zbiór gdzie korzeń to podany wierzchołek
void DisjointSets::MakeSet(int vetrex) {
    vetrexs[vetrex].up = vetrex;
    vetrexs[vetrex].rank = 0;
}

// szuakmy korzenia zbiroru w którym znajduje sie podany mierzchołek
int DisjointSets::FindSet(int vetrex) {
    if(vetrexs[vetrex].up != vetrex) vetrexs[vetrex].up = FindSet(vetrexs[vetrex].up);
    return vetrexs[vetrex].up;
}

// metoda łączoce dwa zbiory
void DisjointSets::UnionSets(Edge e) {
    int root_v, root_u;

    // znajdujemy korzeń zbioru wierzchołka końcowego i początkowego krawędzi
    root_u = FindSet(e.startVertex);
    root_v = FindSet(e.endVertex);
    if(root_u != root_v){
        // Poruwnujemy rangi drzew która ranga większa to dąłączamy korzeń rangi mniejszej
        // do zbioru rangi większej
        if(vetrexs[root_u].rank > vetrexs[root_v].rank){
            vetrexs[root_v].up = root_u;
        } else{
            vetrexs[root_u].up = root_v;
            // jeśli są równe to dołączamy do zbioru krawędzi końcowej i zwiększamy range krawędzi końcowej
            if(vetrexs[root_u].rank == vetrexs[root_v].rank) vetrexs[root_v].rank++;
        }
    }
}
