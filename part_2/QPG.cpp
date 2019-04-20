//
// Created by vladimir on 12.04.19.
//

#include "QPG.h"

QPG::QPG() {

}

Edge* QPG::Djikstry_algorithm(int** matrix, Node** list, int vertex, int start) {
    PriorityQueue expenses(vertex);
    Edge* vertexs = new Edge[vertex];
    if(matrix != nullptr || list != nullptr){

        for(int i = 0; i < vertex; i++){
            if(i == start){
                expenses.push(Edge(-1,i,0));
            } else{
                expenses.push(Edge(-1,i,MAXINT));
            }
        }//expense[start] = 0;

        for(int i = 0; i < vertex; i++) {
            Edge edge = expenses.first();
            expenses.pop();
            if (list != nullptr) {
                Node *element = list[edge.endVertex];
                while (element != nullptr) {
                    expenses.change_neighbours(element->vetrex, edge.weight + element->weight, edge.endVertex);
                    element = element->next_element;
                }
            } else if (matrix != nullptr) {
                for (int a = 0; a < vertex; a++) {
                    if (matrix[edge.endVertex][a] == 0) continue;
                    expenses.change_neighbours(a, edge.weight + matrix[edge.endVertex][a], edge.endVertex);
                }
            }
            //std::cout << edge.endVertex << " " << edge.startVertex << " " << edge.weight << std::endl;
            vertexs[edge.endVertex] = edge;
        }

    } else{
        std::cout << "Nie podałeś struktruy" << std::endl;
    }

    return vertexs;

}

Edge* QPG::Forda_Belmana_algorithm(int **matrix, Node **list, int vertex, int start) {
    Edge* vertexs = new Edge[vertex];
    int* expenses;
    int* prev;
    if(matrix != nullptr || list != nullptr){
        expenses = new int[vertex];
        prev = new int[vertex];
        for(int a = 0; a < vertex; a++){
            expenses[a] = MAXINT;
            prev[a] = -1;
        }

        expenses[start] = 0;

        for(int i = 1; i < vertex; i++) {
            for(int x = 0; x < vertex; x++){

                if(list != nullptr){
                    Node* element = list[x];
                    while (element != nullptr){
                        if(expenses[element->vetrex] > expenses[x] + element->weight && expenses[x] < MAXINT) {

                            expenses[element->vetrex] = expenses[x] + element->weight;
                            prev[element->vetrex] = x;
                        }
                        element = element->next_element;
                    }
                } else if(matrix != nullptr){
                    for(int a = 0; a < vertex; a++){
                        if(matrix[x][a] == 0) continue;
                        if(expenses[a] > expenses[x] + matrix[x][a]  && expenses[x] < MAXINT){
                            expenses[a] = expenses[x] + matrix[x][a];
                            prev[a] = x;
                        }
                    }
                }
            }
            /*Edge* edge = expenses.pop();
            if(list != nullptr){
                Node* element = list[edge->endVertex];
                while (element != nullptr){
                    expenses.change_neighbours(element->vetrex, edge->weight+element->weight, edge->endVertex);
                    element = element->next_element;
                }
            } else if(matrix != nullptr){
                for(int a = 0; a < vertex; a++){
                    if(matrix[i][a] == 0) continue;
                    expenses.change_neighbours(a, edge->weight+matrix[i][a], edge->endVertex);
                }
            }
            vertexs[edge->endVertex] = *edge;*/
        }

    }
    if(expenses == nullptr) return nullptr;
    for(int a = 0; a < vertex; a++){
        if(list != nullptr){
            Node* element = list[a];
            while (element != nullptr){
                if(expenses[element->vetrex] > expenses[a] + element->weight) return nullptr;
                element = element->next_element;
            }
        } else if(matrix != nullptr){
            for(int b = 0; b < vertex; b++){
                if(matrix[a][b] == 0) continue;
                if(expenses[b] > expenses[a] + matrix[a][b]) return nullptr;
            }
        }
        vertexs[a] = Edge(prev[a], a, expenses[a]);
    }
    delete[] expenses;
    delete[] prev;

    return vertexs;
}