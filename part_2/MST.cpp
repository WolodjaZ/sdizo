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
    Edge edge;
    for(int a = 1; a < vetrex; a++){
        do{
            edge = priorityQueue->first();
            priorityQueue->pop();
        }while (spanningTree.FindSet(edge.startVertex) == spanningTree.FindSet(edge.endVertex));
        edges[a-1] = edge;
        spanningTree.UnionSets(edge);
    }
    delete priorityQueue;

    return edges;
}

Edge* MST::prim_algorithm(int** matrix, Node** list, int vertex, int edges) {
    PriorityQueue priorityQueu(edges);
    Edge* edges_array = new Edge[vertex-1];
    bool* visited = new bool [vertex];


    for(int i = 0; i < vertex; i++) visited[i] = false;

    int v = 0;
    visited[v] = true;

    if(matrix != nullptr){

        for(int i = 1; i < vertex; i++){
            for(int a = 0; a < vertex; a++){
                if(matrix[v][a] != 0 && !visited[a]){
                    Edge edge(v, a, matrix[v][a]);
                    priorityQueu.push(edge);
                }
            }

            Edge edge;

            do{
                edge = priorityQueu.first();
                priorityQueu.pop();
            }while (visited[edge.endVertex]);
            edges_array[i-1] = edge;
            visited[edge.endVertex] = true;
            v = edge.endVertex;
        }

    } else if(list != nullptr) {
        Node* element;

        for(int i = 1; i < vertex; i++){
            element = list[v];
            while (element != nullptr){
                if(!visited[element->vetrex]){
                    Edge edge(v, element->vetrex, element->weight);
                    priorityQueu.push(edge);
                }
                element = element->next_element;
            }

            Edge edge;

            do{
                edge = priorityQueu.first();
                priorityQueu.pop();
            }while (visited[edge.endVertex]);
            edges_array[i-1] = edge;
            visited[edge.endVertex] = true;
            v = edge.endVertex;

        }
    } else return nullptr;

    delete[] visited;
    return edges_array;
}