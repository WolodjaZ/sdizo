//
// Created by vladimir on 18.04.19.
//


#include "MS.h"


MS::MS(int **matrix, Node** list, int start, int end, int size) : matrix(matrix),
start(start), end(end), size(size), list(list) {}


MS::~MS() {
    for(int a = 0; a < size; a++){
        if(list != nullptr) delete [] list[a];
        if(matrix != nullptr) delete [] matrix[a];
    }
    delete matrix;
    delete list;
}

int MS::Ford_Fulkerson_algorithm() {
    int* prev = new int[size];
    bool* visited = new bool[size];
    int max_flow = 0;

    if(matrix != nullptr){
        int** rGraph = new int* [size];
        for(int i = 0; i < size; ++i) {
            rGraph[i] = new int[size];

            for (int j = 0; j < size; ++j) rGraph[i][j] = matrix[i][j];
        }

        while (DFS_matrix(rGraph, prev, visited, size, start, end)){
            std::memset(visited, false, sizeof(visited));
            int path_flow = 0xfffffff;

            for(int v = end; v != start; v = prev[v]){
                int u = prev[v];
                path_flow = std::min(path_flow, rGraph[u][v]);
            }

            for(int v = end; v != start; v = prev[v]){
                int u = prev[v];
                rGraph[u][v] -= path_flow;
                rGraph[v][u] += path_flow;
            }

            max_flow += path_flow;
        }

        for(int a = 0; a < size; a++) delete rGraph[a];
        delete [] rGraph;

    } else if(list != nullptr){
        Node** rList = new Node* [size];
        Node* element;
        for(int a = 0; a < size; a++) {
            rList[a] = nullptr;
            for(element = list[a]; element != nullptr; element = element->next_element){
                Node *node = new Node {rList[a], element->vetrex, element->weight};
                rList[a] = node;
            }
        }

        while (DFS_list(rList, prev, visited, size, start, end)) {
            std::memset(visited, false, sizeof(visited));
            int path_flow = 0xfffffff;

            for (int v = end; v != start; v = prev[v]) {
                int u = prev[v];
                element = list[u];
                while(element != nullptr && element->vetrex != v) element = element->next_element;
                if(element == nullptr) path_flow = 0;
                else path_flow = std::min(path_flow, element->weight);
            }

            for (int v = end; v != start; v = prev[v]) {
                int u = prev[v];
                element = list[u];
                while(element != nullptr && element->vetrex != u) element = element->next_element;
                if(element != nullptr)  element->weight -= path_flow;
                element = list[v];
                while(element != nullptr && element->vetrex != u) element = element->next_element;
                if(element != nullptr) element->weight += path_flow;
            }

            max_flow += path_flow;
        }
        Node*replace;
        for(int a = 0; a < this->size; a++){
            element = rList[a];
            while (element != nullptr){
                replace = element;
                element = element->next_element;
                delete replace;
            }
        }
        delete [] rList;
    }

    delete prev;
    delete visited;
    return max_flow;

}

bool MS::DFS_matrix(int** graph, int* prev, bool* visited, int n, int x, int t) {
    if(x == t) return true;
    visited[x] = true;

    for(int a = 0; a < n; ++a){
        if(graph[x][a] > 0 && !visited[a]){
            prev[a] = x;
            if(DFS_matrix(graph, prev, visited, n, a, t)){
                return true;
            }
        }
    }

    return false;
}

bool MS::DFS_list(Node **list, int *prev, bool *visited, int n, int x, int t) {
    if(x == t) return true;
    visited[x] = true;

    Node* element = list[x];
    while(element != nullptr){
        if(element->weight > 0 && !visited[element->vetrex]){
            prev[element->vetrex] = x;
            if(DFS_list(list, prev, visited, n, element->vetrex, t)){
                return true;
            }
        }
    }

    return false;
}

