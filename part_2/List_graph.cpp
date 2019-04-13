//
// Created by vladimir on 06.04.19.
//


#include "List_graph.h"


List_graph::~List_graph() {
    for(int a = 0; a < this->verticles; a++) delete this->list_table[a];
    delete[] list_table;
}

void List_graph::readFromFile(std::string path, std::string type) {
    std::fstream file;
    file.open(path, std::ios::in);

    if(file.good()){
        if (type == 'nieskierowany') directed = false;
        else directed = true;

        file >> this->edges >> this->verticles;

        Node* node;
        list_table = new Node* [this->verticles];

        int startVertex, endVertrx, weight;

        for(int i = 0; i < this->edges; i++){
            file >> startVertex >> endVertrx >> weight;
            node = new Node();
            node->vetrex = endVertrx;
            node->weight = weight;
            node->next_element = nullptr;
            Node *wierzcholek = list_table[startVertex];
            while (wierzcholek->next_element != nullptr){
                wierzcholek = wierzcholek->next_element;
            }
            wierzcholek->next_element = node;
            /*node->next_element = list_table[startVertex];
            list_table[startVertex] = node;*/

            if(type == 'nieskierowane'){
                node = new Node();
                node->vetrex = startVertex;
                node->weight = weight;
                node->next_element = nullptr;
                Node* wierzcholek = list_table[endVertrx];
                while (wierzcholek->next_element != nullptr){
                    wierzcholek = wierzcholek->next_element;
                }
                wierzcholek->next_element = node;

                /*node->next_element = list_table[endVertrx];
                list_table[endVertrx] = node;*/
            }
        }

        file.close();
    }
    else std::cout << "Error opening file!!!" << std::endl;
}

List_graph::Node* List_graph::getNeighboursList(int vertex) {
    return list_table[vertex];
}

PriorityQueue* List_graph::create_priority_queue() {
    if(verticles <= 0) return nullptr;
    PriorityQueue priorityQueue(edges);
    Node* element;
    for(int i = 0; i < verticles; i++){
        element = list_table[i];
        if (element == nullptr) continue;
        while(element->next_element != nullptr){
            priorityQueue.push(Edge(i,element->vetrex, element->weight));
            element = element->next_element;
        }
        priorityQueue.push(Edge(i,element->vetrex, element->weight));
    }
    return &priorityQueue;
}

List_graph::Node** List_graph::create_list_from_edges(Edge *edge, int size) {
    Node** list = new Node* [this->verticles];
    for(int i = 0; i < size; i++){
        Node* node = new Node();
        node->vetrex = edge[i].endVertex;
        node->weight = edge[i].weight;
        node->next_element = nullptr;
        Node *wierzcholek = list_table[edge[i].startVertex];
        while (wierzcholek->next_element != nullptr){
            wierzcholek = wierzcholek->next_element;
        }
        wierzcholek->next_element = node;
        /*node->next_element = list_table[startVertex];
        list_table[startVertex] = node;*/

        if(!directed){
            node = new Node();
            node->vetrex = edge[i].startVertex;
            node->weight = edge[i].weight;
            node->next_element = nullptr;
            Node* wierzcholek = list_table[edge[i].endVertex];
            while (wierzcholek->next_element != nullptr){
                wierzcholek = wierzcholek->next_element;
            }
            wierzcholek->next_element = node;

            /*node->next_element = list_table[endVertrx];
            list_table[endVertrx] = node;*/
        }
    }
    return list;
}

void List_graph::Kruskal_algorithm() {
    PriorityQueue* priorityQueue = create_priority_queue();
    Edge* edge = MST::kruskal_algorithm(priorityQueue, verticles);
    List_graph::Node** list = create_list_from_edges(edge, sizeof(edge));
    delete[] edge;
    print(list);
    for(int a = 0; a < this->verticles; a++) delete list[a];
    delete[] list;


}

void List_graph::print(Node** list) {
    Node* node;

    std::cout << "\nList representation:" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < this->verticles; i++)
    {
        std::cout << "[" << i << "] =";
        node = list[i];

        while (node)
        {
            std::cout << std::setw(3) << node->vetrex;
            node = node->next_element;
        }
        std::cout << std::endl;
    }
}