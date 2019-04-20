//
// Created by vladimir on 06.04.19.
//


#include "List_graph.h"

List_graph::List_graph(): list_table(nullptr), verticles(0), edges(0){}

List_graph::~List_graph() {
    Node* element, *replace;
    for(int a = 0; a < this->verticles; a++){
        element = list_table[a];
        while (element != nullptr){
            replace = element;
            //std::cout << replace->weight << replace->vetrex << std::endl;
            element = element->next_element; // coś tu nie tak
            delete replace;
        }
    }
    delete[] list_table;
}

void List_graph::readFromFile(std::string path, int algorithm) {
    std::ifstream file;
    file.open(path);

    if(file.good()){

        if(algorithm == 0){
            directed = false;
            file >> this->edges >> this->verticles;
        } else if(algorithm == 1){
            directed = true;
            file >> this->edges >> this->verticles >> this->start;
        } else if(algorithm == 2){
            directed = true;
            file >> this->edges >> this->verticles >> this->start >> this->end;
        } else{
            std::cout << "Nieznany algorytm" << std::endl;
            return;
        }

        list_table = new Node* [this->verticles];

        int startVertex, endVertrx, weight;

        for(int i = 0; i < this->edges; i++){
            file >> startVertex >> endVertrx >> weight;
            add_node(startVertex, endVertrx, weight);
            if(!directed) add_node(endVertrx, startVertex, weight);
        }

        file.close();
    }
    else std::cout << "Error opening file!!!" << std::endl;
}

Node* List_graph::getNeighboursList(int vertex) {
    if(verticles == 0) return nullptr;
    return list_table[vertex];
}

PriorityQueue* List_graph::create_priority_queue() {
    if(verticles <= 0) return nullptr;
    PriorityQueue *priorityQueue = new PriorityQueue(edges);

    Node* element;
    for(int i = 0; i < verticles; i++){
        element = list_table[i];
        while(element != nullptr){
            if(element->vetrex > i) priorityQueue->push(Edge(i,element->vetrex, element->weight));

            element = element->next_element;
        }
    }
    return priorityQueue;
}

Node** List_graph::create_list_from_edges(Edge *edge, int size) {
    Node** list = new Node* [verticles];
    for(int a = 0; a < size; a++) list[a] = nullptr;

    for(int i = 0; i < size-1; i++){
        Node* node = new Node(list[edge[i].startVertex],edge[i].endVertex, edge[i].weight);
        list[edge[i].startVertex] = node;

        if(!directed){
            node = new Node(list[edge[i].endVertex] ,edge[i].startVertex, edge[i].weight);
            list[edge[i].endVertex] = node;

        }
    }

    return list;
}


void List_graph::generator(int vertex, int density_procent, int type, int max, int min) {
    this->list_table = new Node* [vertex];
    this->verticles = vertex;
    this->edges = (density_procent*vertex*(vertex-1))/(200);
    this->directed = type == 0? false:true;

    bool* in_tree = new bool[vertex];


    for(int a = 0; a < verticles; a++) {
        list_table[a] = nullptr;
        in_tree[a] = false;
    }

    srand(time(NULL));

    int first = 0;
    in_tree[first] = true;
    int second;
    int edge;
    int a = 0;
    while(a < verticles-1){
        second = random_vertex(in_tree);
        edge = (std::rand()%max)+min;
        srand(time(NULL));
        add_node(first, second, edge);
        srand(time(NULL));
        if(!directed) add_node(second, first, edge);
        a++;
        first = second;
        in_tree[first] = true;
    }

    edge = (std::rand()%max)+min;
    add_node(first, 0, edge);
    if(!directed) add_node(0, first, edge);
    a++;

    while(a < edges){
        first = std::rand()%verticles;
        second = std::rand()%verticles;
        srand(time(NULL));
        edge = (std::rand()%max)+min;
        srand(time(NULL));
        if(first != second && !exist_edge(first,second)){
            add_node(first, second, edge);
            if(!directed) add_node(second, first, edge);
            a++;
        }
    }

    start = std::rand()%verticles;
    do{
        end = std::rand()%verticles;
    }while(end != start);

}

bool List_graph::exist_edge(int start, int end) {
    Node* element = list_table[start];
    while(element != nullptr){
        if(element->vetrex == end) return true;
        element = element->next_element;
    }
    return false;
}

void List_graph::add_node(int startVertex, int endVertrx, int weight) {
    Node* node = new Node(list_table[startVertex], endVertrx, weight);
    list_table[startVertex] = node;
    /*node->next_element = list_table[startVertex];
    list_table[startVertex] = node;*/
}

int List_graph::random_vertex(bool *in_tree) {
    int ansver;
    do{
        ansver = (std::rand() % this->verticles-1)+1;
    }while(in_tree[ansver]);
    return ansver;
}

void List_graph::Kruskal_algorithm() {
    if(verticles == 0)return;
    PriorityQueue* priorityQueue = create_priority_queue();
    Edge* edge = MST::kruskal_algorithm(priorityQueue, verticles);
    Node** list = create_list_from_edges(edge, verticles);
    delete[] edge;
    print(list, verticles);
    for(int a = 0; a < this->verticles; a++) delete list[a];
    delete[] list;

}

void List_graph::Prims_algorithm() {
    if(verticles == 0)return;
    Edge* edge = MST::prim_algorithm(nullptr, list_table, verticles, edges);
    Node** list = create_list_from_edges(edge, verticles);
    delete[] edge;
    print(list, verticles);
    for(int a = 0; a < this->verticles; a++) delete list[a];
    delete[] list;
}

void List_graph::Dijikstras_algorithm() {
    std::cout << start << std::endl;
    Edge* vertexs = QPG::Djikstry_algorithm(nullptr, list_table,verticles, start);
    if (vertexs == nullptr) return;
    for(int a = 0; a < verticles; a++){
        Edge edge = vertexs[a];
        std::cout << "Vertex:" << a << " cost: " << edge.weight <<" road: " << edge.endVertex;
        while(edge.startVertex != -1){
            std::cout << " " << edge.startVertex;
            edge = vertexs[edge.startVertex];
        }
        std::cout << std::endl;
    }

    delete[] vertexs;
}

void List_graph::Bellmana_Forda_algorithm() {
    if(verticles == 0)return;
    std::cout << start << std::endl;
    Edge* vertexs = QPG::Forda_Belmana_algorithm(nullptr, list_table,verticles, start);
    if (vertexs == nullptr) return;
    for(int a = 0; a < verticles; a++){
        Edge edge = vertexs[a];
        std::cout << "Vertex:" << a << " cost: " << edge.weight <<" road: " << edge.endVertex;
        while(edge.startVertex != -1){
            std::cout << " " << edge.startVertex;
            edge = vertexs[edge.startVertex];
        }
        std::cout << std::endl;
    }
}

void List_graph::Ford_Fulkerson_algorithm() {
    if(verticles == 0)return;
    std::cout << start << " " << end << std::endl;
    MS max_flow(nullptr, list_table, start, end, verticles);
    int flow = max_flow.Ford_Fulkerson_algorithm();
    std::cout << "Maksymalny przepływ pomiędzy " << start << "-" << end << " wynosi:" << flow << std::endl;
}

void List_graph::print(Node** list, int size) {
    if(list == nullptr) {
        list = list_table;
        size = verticles;
    }
    Node* node;

    std::cout << "\nList representation:" << std::endl;
    std::cout << std::endl;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << i << "] =";
        node = list[i];

        while (node)
        {
            std::cout << std::setw(3) << node->vetrex << std::setw(2) << node->weight << ", ";
            sum += node->weight;
            node = node->next_element;
        }
        std::cout << std::endl;
    }

    std::cout << "Sumaryczna waga: " << sum << std::endl;
}