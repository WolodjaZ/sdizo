//
// Created by vladimir on 06.04.19.
//


#include "List_graph.h"

// Konstruktor ustawiający wskaźnik na liste sąsiadów(Na podstawie klasy Node) oraz liczbe krawędzi i wierzchołków na NULL
List_graph::List_graph(): list_table(nullptr), vertex(0), edges(0){}

// Destruktor który usuwa liste sąsiadów
List_graph::~List_graph() {
    delete_list();
}

// metoda która zczytuje dane z pliku poprzez podanie scieżki oraz typu problemu który będzie rozwiązywany
void List_graph::readFromFile(std::string path, int algorithm) {
    std::ifstream file;
    file.open(path);

    // otwieramy plik o podanej scieżce
    if(file.good()){

        if(list_table != nullptr) delete_list();
        // Dla odpowiedniego typu algorytmu ustawiamy czy list jest nieskierowana oraz końce i początki grafu
        // 0 - algorytmy MST, 1 - algorytmy najkrutszej scieżki, 2 - algorytm max przepływu
        if(algorithm == 0){
            directed = false;
            file >> this->edges >> this->vertex;
        } else if(algorithm == 1){
            directed = true;
            file >> this->edges >> this->vertex >> this->start;
        } else if(algorithm == 2){
            directed = true;
            file >> this->edges >> this->vertex >> this->start >> this->end;
        } else{
            std::cout << "Unknown algorithm" << std::endl;
            return;
        }

        list_table = new Node* [this->vertex];
        for(int a = 0; a < vertex; a++) list_table[a] = nullptr;

        int startVertex, endVertrx, weight;

        //zczytujemy krawędzie po koleji i dodajemy sąsiada do odpowiedniego wierzchołka za pomocą metody add_node
        for(int i = 0; i < this->edges; i++){
            file >> startVertex >> endVertrx >> weight;
            add_node(startVertex, endVertrx, weight);
            // jeśli graf jest nieskierowany ustawiamy też sąsiada o przeciwnych danych
            if(!directed) add_node(endVertrx, startVertex, weight);
        }

        file.close();
    }
    // Jeśli plik nie da się otworzyć wyskakuje komunikat
    else std::cout << "Error opening file!!!" << std::endl;
}

// metoda zwracająca sąsiada podanego wierzchołka
Node* List_graph::getNeighboursList(int vertex) {
    if(vertex == 0) return nullptr;
    return list_table[vertex];
}

// metoda tworząca kolejke priorytetową listy sąsiadów dla algorytmów MST
PriorityQueue* List_graph::create_priority_queue() {
    if(vertex <= 0) return nullptr;
    // Tworzymy obiekt o ilośći krawędzi
    PriorityQueue *priorityQueue = new PriorityQueue(edges);

    Node* element;
    for(int i = 0; i < vertex; i++){
        element = list_table[i];
        // dodajemy krawędzie wiechołków do kolejki jeśli wiechołek końcowy jest większy od wierzchołka
        // początkowego to tworzy się obiekt krawędzi o odpowiednich danych i dodaje się do kolejki
        // warunek wielkości wiechołka początkowego służy do nie dodawania tych samych krawędzi jako że jest to graf nieskierowany
        while(element != nullptr){
            if(element->vetrex > i)
                priorityQueue->push(Edge(i,element->vetrex, element->weight));

            element = element->next_element;
        }
    }
    return priorityQueue;
}


// otrymaną tablice krawędzi zamieniamy na listę sąsiadów do odczytu. Wielkość tablicy wynosi ilość wierchołków - 1
Node** List_graph::create_list_from_edges(Edge *edge, int size) {
    Node** list = new Node* [vertex];
    // tworzymy pustą list
    for(int a = 0; a < size; a++) list[a] = nullptr;

    // zczytujemy po koleji z tablicy krawędzie i wsadzamy w wiechołki
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

// metoda tworząca graf losowy poprzez podanie liczby wierchołków, procentowej gęstości wierchołka, typu algorytmu, oraz przedziałów wielkości krawędzi
void List_graph::generator(int vertex, int density_procent, int type, int max, int min) {
    if(list_table != nullptr) delete_list();
    this->list_table = new Node* [vertex];
    this->vertex = vertex;
    // wyliczamy liczbę krawędzi
    this->edges = (density_procent*vertex*(vertex-1))/(200);
    this->directed = type == 0? false:true;

    bool* in_tree = new bool[vertex];


    for(int a = 0; a < vertex; a++) {
        list_table[a] = nullptr;
        in_tree[a] = false;
    }

    srand(time(NULL));

    // wpierw zostaje tworzone drzewo rozpinające na wzór okręgu
    // in_tree przechowuje informacje czy dannego wierzchołka mamy już w drzewie
    int first = 0;
    in_tree[first] = true;
    int second;
    int edge;
    // liczba krawędzi
    int a = 0;
    while(a < vertex-1){
        // wybieramy randomowy wierzchołek nie znajdujący się jeszcze w drzewie
        second = random_vertex(in_tree);
        edge = (std::rand()%max)+min;
        //srand(time(NULL));
        // i tworzymy element sąsiada o danych ktróre otrzymaliśmy
        add_node(first, second, edge);
        //srand(time(NULL));
        // jeśli jest graf nieskierowany to dodajemy przeciwnego sąsiada
        if(!directed) add_node(second, first, edge);
        a++;
        first = second;
        in_tree[first] = true;
    }

    // tworzymy ostatnią krawędz drzewa/okręgu łączącą pierwszy wiechołek w drzewie z ostatnim
    edge = (std::rand()%max)+min;
    add_node(first, 0, edge);
    if(!directed) add_node(0, first, edge);
    a++;

    // uzupełniamy  reszte krawędzi w losowe pary wierzchołków
    while(a < edges){
        first = std::rand()%vertex;
        second = std::rand()%vertex;
        //srand(time(NULL));
        edge = (std::rand()%max)+min;
        //srand(time(NULL));
        // wiechołki nie mogą być takie same oraz nie możę istnie taka już krawędź
        if(first != second && !exist_edge(first,second)){
            add_node(first, second, edge);
            if(!directed) add_node(second, first, edge);
            a++;
        }
    }

    // wybieramy losowo koniec oraz początek grafu
    start = std::rand()%vertex;
    do{
        end = std::rand()%vertex;
    }while(end != start);

}

// metoda informuje czy krawędź już nie istnieje
bool List_graph::exist_edge(int start, int end) {
    Node* element = list_table[start];
    while(element != nullptr){
        if(element->vetrex == end) return true;
        element = element->next_element;
    }
    return false;
}

// tworzy obiekt Node i dodaje do list sąsiadów
void List_graph::add_node(int startVertex, int endVertrx, int weight) {
    Node* node = new Node(list_table[startVertex], endVertrx, weight);
    list_table[startVertex] = node;
}

// wybiera wierzhołek który nie jest w drzewie
int List_graph::random_vertex(bool *in_tree) {
    int ansver;
    do{
        ansver = (std::rand() % this->vertex-1)+1;
    }while(in_tree[ansver]);
    return ansver;
}

// metoda obsługująca algorytm kruskala
void List_graph::Kruskal_algorithm() {
    if(vertex == 0)return;
    // tworzymy kolejkę priorytetową z listy sąsiadóœ
    PriorityQueue* priorityQueue = create_priority_queue();
    Edge* edge = MST::kruskal_algorithm(priorityQueue, vertex);
    // otrzymaną tablice krawędzi zamieniamy na listę sąsiadów
    Node** list = create_list_from_edges(edge, vertex);
    delete[] edge;
    // odczytujemy list sąsiadów
    print(list, vertex);
    for(int a = 0; a < this->vertex; a++){
        Node* element = list[a];
        while (element != nullptr){
            Node* replace = element;
            element = element->next_element;
            delete replace;
        }
    }
    delete[] list;

}

// metoda obsługująca algorytm Prima
void List_graph::Prims_algorithm() {
    if(vertex == 0)return;
    Edge* edge = MST::prim_algorithm(nullptr, list_table, vertex, edges);
    // otrzymaną tablice krawędzi zamieniamy na listę sąsiadów
    Node** list = create_list_from_edges(edge, vertex);
    delete[] edge;
    print(list, vertex);
    for(int a = 0; a < this->vertex; a++) {
        Node* element = list[a];
        while (element != nullptr){
            Node* replace = element;
            //std::cout << replace->weight << replace->vetrex << replace->next_element << std::endl;
            element = element->next_element;
            delete replace;
        }
    }
    delete[] list;
}

// metoda obsługująca algorytm Dijikstry
void List_graph::Dijikstras_algorithm() {
    if(vertex == 0)return;
    // wstępnie wypisujemy jaki jest startowy wierchołek
    std::cout << "Start vertex: " << start << std::endl;
    Edge* vertexs = QPG::Djikstry_algorithm(nullptr, list_table,vertex, start);
    if (vertexs == nullptr) return;
    // wypisujemy wszsytkie przejscia
    for(int a = 0; a < vertex; a++){
        Edge edge = vertexs[a];
        // bierzemy po kolei krawędzie wypsiujemy jaka krawędz waga i przez jakie krawędzie przechodzi
        std::cout << "Vertex:" << a << " cost: " << edge.weight <<" road: " << edge.endVertex;
        // wypsiujemy krawędzie po których przechodzi aż dojedziemy do zera wypisuje nam od końca do początku przechodzenie
        while(edge.startVertex != -1){
            std::cout << " " << edge.startVertex;
            edge = vertexs[edge.startVertex];
        }
        std::cout << std::endl;
    }

    delete[] vertexs;
}

// metoda obsługująca algorytm Bellmana-Forda
void List_graph::Bellmana_Forda_algorithm() {
    if(vertex == 0)return;
    std::cout << "Start vertex: " << start << std::endl;
    Edge* vertexs = QPG::Forda_Belmana_algorithm(nullptr, list_table,vertex, start);
    // Podobnie jak w algo Dijikstry są wypisywane przejscia
    if (vertexs == nullptr) return;
    for(int a = 0; a < vertex; a++){
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

// metoda nie dziąła dla list
/*void List_graph::Ford_Fulkerson_algorithm() {
    if(vertex == 0)return;
    std::cout << start << " " << end << std::endl;
    MS max_flow(nullptr, list_table, start, end, vertex);
    int flow = max_flow.Ford_Fulkerson_algorithm();
    std::cout << "Maksymalny przepływ pomiędzy " << start << "-" << end << " wynosi:" << flow << std::endl;
}*/

// metoda wypisująca liste jeśli list = nullptr to bierze listę główną i zamienia size na vertex
void List_graph::print(Node** list, int size) {
    if(list == nullptr) {
        list = list_table;
        size = vertex;
    }
    Node* node;

    // wypsujemy po koleji wierchołki
    std::cout << "\nList representation:" << std::endl;
    std::cout << std::endl;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        std::cout << "[" << i << "] =";
        node = list[i];

        while (node)
        {
            // podajemy krawędź oraz wagę sąsiada i przechodzimy dopóki sąsiad istnieje
            std::cout << std::setw(3) << node->vetrex << std::setw(2) << node->weight << ", ";
            sum += node->weight;
            node = node->next_element;
        }
        std::cout << std::endl;
    }

    // wypsiujemy sumaryczną wagę wszystkich krawędzi w liscie
    std::cout << "Sumaryczna waga: " << sum << std::endl;
}

void List_graph::delete_list() {
    if(list_table == nullptr)return;

    Node* element, *replace;
    for(int a = 0; a < this->vertex; a++){
        // usuwamy po kolejki idąc po wierchołkach sąsiadów danego wierchołka
        element = list_table[a];
        while (element != nullptr){
            replace = element;
            //std::cout << replace->weight << " " << replace->vetrex << std::endl;//replace->next_element << std::endl;
            element = element->next_element; // coś tu nie tak
            delete replace;
        }
    }
    delete[] list_table;
    list_table = nullptr;
}