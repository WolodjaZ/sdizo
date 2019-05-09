//
// Created by vladimir on 12.04.19.
//

#include "MST.h"


MST::MST() {

}
// metoda tworzenia minimalnego drzewa rozpinającego algorytmem Kruskala
Edge* MST::kruskal_algorithm(PriorityQueue* priorityQueue, int vetrex) {
    // twrzymy Obiektów zbiorów rozłącznych o wielkości ilosći krawędzi;
    DisjointSets spanningTree(vetrex);
    // tablica krawędzi które będą opisywały drzewo
    Edge *edges = new Edge[vetrex-1];
    // tworzymy dla każdego wierchołka odrębny zrbiór w spanningTree
    for(int i = 0; i < vetrex; i++){
        spanningTree.MakeSet(i);
    }
    Edge edge;
    // będziemy powtrzać cykl liczba_wierzchołków - 1 razy jako iż taką wielkośći powino mieć drzewo
    for(int a = 1; a < vetrex; a++){
        do{
            // pobieramy krawędź o najmniejszej wartości weight dopóki w zbiorze rozłącznym
            // wierzchołek początkowa i wierzchołek końcowy krawędzi nie są w jednym zbiorze
            edge = priorityQueue->first();
            priorityQueue->pop();
        }while (spanningTree.FindSet(edge.startVertex) == spanningTree.FindSet(edge.endVertex));
        // dodajemy krawędz którą wyjeślimy do tablicy krawędzi
        edges[a-1] = edge;
        // łączymy zbiory wierzchołka początkowego i wierzchołka końcowego krawędzi
        spanningTree.UnionSets(edge);
    }
    delete priorityQueue;

    return edges;
}


// metoda tworzenia minimalnego drzewa rozpinającego algorytmem prima
Edge* MST::prim_algorithm(int** matrix, Node** list, int vertex, int edges) {
    // inicjalizujemy kolejke priorytetową o wielkości ilości krawędzi
    PriorityQueue *priorityQueu = new PriorityQueue(edges);
    // tablica krawędzi które będą opisywały drzewo
    Edge* edges_array = new Edge[vertex-1];
    // tablica informacji które wiechołki drzewo zawiera
    bool* visited = new bool [vertex];

    // wstępnie drzewo nie zawiera ani jednego wierzchołka
    for(int i = 0; i < vertex; i++) visited[i] = false;

    // ustawiamy pierwszy wierchołek w drzewie jako o indeksie zerowym
    int v = 0;
    visited[v] = true;

    // będziemy powtrzać cykl liczba_wierzchołków - 1 razy jako iż taką wielkośći powino mieć drzewo
    for(int i = 1; i < vertex; i++){
        // doajemy krawędzi do kolejki które nie kończą się w wierchołkach które są już w drzewach
        // i które wychodzą z wierchołka ostatnio dodanego do drzewa
        if(matrix != nullptr){
            for(int a = 0; a < vertex; a++){
                if(matrix[v][a] != 0 && !visited[a]){
                    Edge edge(v, a, matrix[v][a]);
                    priorityQueu->push(edge);
                }
            }
        } else if(list != nullptr){
            Node* element = list[v];
            while (element != nullptr){
                if(!visited[element->vetrex]){
                    Edge edge(v, element->vetrex, element->weight);
                    priorityQueu->push(edge);
                }
                element = element->next_element;
            }
        }  else {
            delete priorityQueu;
            delete[] visited;
            return nullptr;
        }

        Edge edge;

        do{
            // pobieramy krawędź o najmniejszej wartości weight dopóki wiechołek końcowy
            // krawędzi nie będzie znajdował się w drzewie
            edge = priorityQueu->first();
            priorityQueu->pop();
        }while (visited[edge.endVertex]);
        // dodajemy otrzymaną krawędzi do tablicy krawędzi drzewa
        edges_array[i-1] = edge;
        // ustawiamy że wierchołek końcowy krawędzi został już dodany do drzewa
        visited[edge.endVertex] = true;
        // i ustawiamy ten wierchołek jak wierchołek ostatnio dodany
        v = edge.endVertex;
    }


    delete priorityQueu;
    delete[] visited;
    return edges_array;
}