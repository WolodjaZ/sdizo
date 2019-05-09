//
// Created by vladimir on 12.04.19.
//

#include "QPG.h"

// Oby dwie metody bazują na klasie Edge jednak dla tych metod atrbuty owej klasy mają inne znaczenia
// startVertex - to Vertex poprzednika
// endVertex - jest to Vertex tego wierchołka
// weight - koszt dojścia
QPG::QPG() {

}

// metoda wyznaczenia najkrótszej scieżki algorytmem Djikstry
Edge* QPG::Djikstry_algorithm(int** matrix, Node** list, int vertex, int start) {
    // tworzymy kolejke priotytetową
    PriorityQueue expenses(vertex);
    // tworzymy tablice wierchołków przejść
    Edge* vertexs = new Edge[vertex];
    // sprawdzamy czy podano nam wartości listy albo macierzy
    if(matrix != nullptr || list != nullptr){

        // tworzymy kolejke priorytetową gdzie każdy obiekt znajdujący się w niej będzie zawierał
        // wskażnik na poprzednika -1 i koszt dojść równt MAXINT
        for(int i = 0; i < vertex; i++){
            if(i == start){
                // jesli będzie to wiechołek startowy to jego wartość kosztu dojścia wynosi 0
                expenses.push(Edge(-1,i,0));
            } else{
                expenses.push(Edge(-1,i,MAXINT));
            }
        }

        // przechodzimy tyle razy ile jest wierzchołków
        for(int i = 0; i < vertex; i++) {
            // pobieramy wiechołek o najmniejszej wartości dojścia
            Edge edge = expenses.first();
            expenses.pop();
            // przechodzimy teraz po wszystkich jego sąsiadach i ustawiamy ich wartości poprzednika na obiekt
            // ostatnio wyciągnięty oraz koszt na koszt tego samego wierchołka i krawędzi ich łączocą o ile
            // koszt tego wiechołka jet większy od sumy wcześniej wspomnianych wartości
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
            // dodajemy wiechołek do tablicy wierzchołków
            vertexs[edge.endVertex] = edge;
        }

    } else{
        std::cout << "Nie podałeś struktruy" << std::endl;
    }

    return vertexs;

}

Edge* QPG::Forda_Belmana_algorithm(int **matrix, Node **list, int vertex, int start) {
    // tworzymy tablice poprzedników, kosztów i wierzchołków
    Edge* vertexs = new Edge[vertex];
    int* expenses;
    int* prev;
    if(matrix != nullptr || list != nullptr){
        // przypisujemy warotości wierzchołków poprzedników i kosztów dojść na wartości -1 i MAXINT
        expenses = new int[vertex];
        prev = new int[vertex];
        for(int a = 0; a < vertex; a++){
            expenses[a] = MAXINT;
            prev[a] = -1;
        }

        // wartość dojscia startowego wierzchołka wynosi 0
        expenses[start] = 0;

        // tworzymy pętle relaksacji
        for(int i = 1; i < vertex; i++) {
            // Przechodzimy przez kolejne wierzchołki grafu
            for(int x = 0; x < vertex; x++){
                // przechodzimy przez sąsiadów wierzchołka x i sprawdzamy czy koszt dojścia  do sąsiada jest mniejsza
                // od sumy kosztu dojścia wierzchołka i wagi krawędzi. Jeśl tak to ustawiamy poprzednika owego sąsiada
                // na dany wiechołek i ustawiamy nowy koszty dojścia na wspomnianą sumę
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
        }

    }

    // po relaksacki grafu sprawdzamy czy nie wystapiły cykle ujemne
    if(expenses == nullptr) return nullptr;
    for(int a = 0; a < vertex; a++){
        if(list != nullptr){
            Node* element = list[a];
            while (element != nullptr){
                if(expenses[element->vetrex] > expenses[a] + element->weight){
                    delete[] expenses;
                    delete[] prev;
                    return nullptr;
                }
                element = element->next_element;
            }
        } else if(matrix != nullptr){
            for(int b = 0; b < vertex; b++){
                if(matrix[a][b] == 0) continue;
                if(expenses[b] > expenses[a] + matrix[a][b]) {
                    delete[] expenses;
                    delete[] prev;
                    return nullptr;
                }
            }
        }
        // tworzymy wierzchołek a o jego wartościach poprzednika i kosztu i dodajemy do tablicy wierzchołków
        // przejść
        vertexs[a] = Edge(prev[a], a, expenses[a]);
    }
    delete[] expenses;
    delete[] prev;

    return vertexs;
}