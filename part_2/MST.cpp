//
// Created by vladimir on 12.04.19.
//

#include "MST.h"


MST::MST() {

}

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

Edge* MST::prim_algorithm(int** matrix, List_graph::Node** list, int vertex, int edges) {
    PriorityQueue priorityQueu(edges);
    Edge* edges_array = new Edge[vertex];
    bool* visited = new bool [vertex];
    visited[0] = true;
    int v = 0;


    for(int i = 0; i < vertex; i++) visited[i] = false;

    if(matrix != nullptr){
        for(int i = 0; i < vertex; i++){
            for(int a = 0; a < vertex; a++){
                if(matrix[i][a] != 0 && !visited[a]){
                    Edge edge(v, a, matrix[i][a]);
                    priorityQueu.push(edge);
                }
            }

            Edge edge;
            do{
                edge = priorityQueu.first();
                priorityQueu.pop();
            }while (visited[edge.endVertex]);
            edges_array[i] = edge;
            visited[edge.endVertex] = true;
            v = edge.endVertex;
        }

    } else if(list != nullptr) {
        List_graph::Node* element;

        for(int i = 0; i < vertex; i++){
            element = list[i];
            while (element != nullptr){
                if(!visited[element->vetrex]){
                    Edge edge(v, element->vetrex, element->weight);
                    priorityQueu.push(edge);
                    element = element->next_element;
                }
            }

            Edge edge;
            do{
                edge = priorityQueu.first();
                priorityQueu.pop();
            }while (visited[edge.endVertex]);
            edges_array[i] = edge;
            visited[edge.endVertex] = true;
            v = edge.endVertex;

        }
    } else return nullptr;

    delete[] visited;
    return edges_array;
}