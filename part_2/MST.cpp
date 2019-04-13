//
// Created by vladimir on 12.04.19.
//

#include "MST.h"


Edge* MST::kruskal_algorithm(PriorityQueue* priorityQueue, int vetrex) {
    Spanning_Tree spanningTree(vetrex);
    Edge *edges = new Edge[vetrex-1];
    for(int i = 0; i < vetrex; i++){
        spanningTree.MakeSet(i);
    }

    for(int a = 1; a < vetrex; a++){
        Edge edge;
        do{
            edge = priorityQueue->first();
            priorityQueue->pop();
        }while (spanningTree.FindSet(edge.startVertex) == spanningTree.FindSet(edge.endVertex));
        edges[a-1] = edge; // do list albo matixa;
        spanningTree.UnionSets(edge);
    }
    delete priorityQueue;

    return edges;
}

Edge* MST::prim_algorithm(PriorityQueue *priorityQueue) {

}