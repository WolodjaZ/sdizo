//
// Created by vladimir on 06.04.19.
//

#include <iomanip>
#include "Matrix_graph.h"

// Konstruktor ustawiający wskaźnik na macierz oraz liczbe krawędzi i wierzchołków na NULL
Matrix_graph::Matrix_graph(): table_matrix(nullptr), vertex(0), edges(0) {

}

// Destruktor który usuwa macierz
Matrix_graph::~Matrix_graph() {
    delete_matrix();
}

// metoda tworząca graf losowy poprzez podanie liczby wierchołków, procentowej gęstości wierchołka, typu algorytmu, oraz przedziałów wielkości krawędzi
void Matrix_graph::generator(int vertex, int density_procent, int type, int max, int min) {
    if(table_matrix != nullptr)delete_matrix();
    this->table_matrix = new int* [vertex];
    this->vertex = vertex;
    // wyliczamy liczbę krawędzi
    this->edges = (density_procent*vertex*(vertex-1))/(200);
    this->directed = type == 0? false:true;

    bool* in_tree = new bool[vertex];


    for(int a = 0; a < vertex; a++) {
        table_matrix[a] = new int[vertex];
        for(int b = 0; b < vertex; b++){
            table_matrix[a][b] = 0;
        }
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
        table_matrix[first][second] = edge;
        //srand(time(NULL));
        // jeśli jest graf nieskierowany to dodajemy przeciwnego sąsiada
        if(!directed) table_matrix[second][first] = edge;
        a++;
        first = second;
        in_tree[first] = true;
    }

    // tworzymy ostatnią krawędz drzewa/okręgu łączącą pierwszy wiechołek w drzewie z ostatnim
    edge = (std::rand()%max)+min;
    table_matrix[first][0] = edge;
    if(!directed) table_matrix[0][first] = edge;
    a++;

    // uzupełniamy  reszte krawędzi w losowe pary wierzchołków
    while(a < edges){
        first = std::rand()%vertex;
        second = std::rand()%vertex;
        //srand(time(NULL));
        edge = (std::rand()%max)+min;
        //srand(time(NULL));
        // wiechołki nie mogą być takie same oraz nie możę istnie taka już krawędź
        if(first != second && 0 == table_matrix[first][second]){
            table_matrix[first][second] = edge;
            if(!directed) table_matrix[second][first] = edge;
            a++;
        }
    }

    // wybieramy losowo koniec oraz początek grafu
    start = std::rand()%vertex;
    do{
        end = std::rand()%vertex;
    }while(end != start);

}

int Matrix_graph::random_vertex(bool *in_tree) {
    int ansver;
    do{
        ansver = (std::rand() % this->vertex-1)+1;
    }while(in_tree[ansver]);
    return ansver;
}
// metoda która zczytuje dane z pliku poprzez podanie scieżki oraz typu problemu który będzie rozwiązywany
void Matrix_graph::readFromFile(std::string path, int algorithm) {
    std::ifstream file;
    file.open(path);

    // otwieramy plik o podanej scieżce
    if (file.good())
    {
        if(table_matrix != nullptr)delete_matrix();
        // Dla odpowiedniego typu algorytmu ustawiamy czy macierz jest nieskierowana oraz końce i początki grafu
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
        int i, j;

        // tworzymy pustą macierz i ustawiamy wszystkie wartości na 0
        table_matrix = new int*[vertex];
        for (i = 0; i < vertex; i++) table_matrix[i] = new int[vertex];

        for (i = 0; i < vertex; i++) {
            for (j = 0; j < vertex; j++) {
                table_matrix[i][j] = 0;
            }
        }

        int startVertex, endVertex, weight;

        // zczytujemy po koleji krawędzie i wpisujemy w odpowiednie wartości macierzy wagi
        // jeśli graf jest nieskierowany powtarzamy te wartości dla przeciwnych wierzchołków
        for (i = 0; i < edges; i++)
        {
            file >> startVertex >> endVertex >> weight;
            table_matrix[startVertex][endVertex] = weight;
            if (!directed) table_matrix[endVertex][startVertex] = weight;
        }

        file.close();
    }
    // Jeśli plik nie da się otworzyć wyskakuje komunikat
    else std::cout << "Error opening file!!!" << std::endl;

}

int Matrix_graph::get(int start_vertex, int end_vertex) {
    if(vertex == 0)return -1;
    return this->table_matrix[start_vertex][end_vertex];
}

PriorityQueue* Matrix_graph::create_priority_queue() {
    if(vertex <= 0)return nullptr;
    PriorityQueue *priorityQueue = new PriorityQueue(edges);
    for(int a = 0; a < vertex; a++){
        for(int i = 0; i < vertex; i++){
            if(table_matrix[a][i] != 0 && i > a){
                priorityQueue->push(Edge(a,i, table_matrix[a][i]));
            }
        }
    }
    return priorityQueue;
}

int** Matrix_graph::create_matrix_from_edges(Edge* edge, int size) {
    int ** matrix = new int* [this->vertex];
    for (int j = 0; j < this->vertex; j++) {
        matrix[j] = new int[this->vertex];
        for(int a = 0; a < vertex; a++) matrix[j][a] = 0;
    }
    for(int i = 0; i < size-1; i++){
        matrix[edge[i].startVertex][edge[i].endVertex] = edge[i].weight;
        if(!directed) matrix[edge[i].endVertex][edge[i].startVertex] = edge[i].weight;
        //std::cout << matrix[edge[i].startVertex][edge[i].endVertex] << " " <<edge[i].startVertex << " "  << edge[i].endVertex << std::endl;
        //if(!directed) matrix[edge[i].endVertex][edge[i].startVertex] = edge[i].weight;
    }

    return matrix;
}


void Matrix_graph::Kruskal_algorithm() {
    if(vertex == 0)return;
    PriorityQueue* priorityQueue = create_priority_queue();
    Edge *edge = MST::kruskal_algorithm(priorityQueue, this->vertex);
    int** matrix = create_matrix_from_edges(edge, vertex);
    delete[] edge;
    print(matrix, vertex);
    for(int i = 0; i < vertex; i++) delete[] matrix[i];
    delete[] matrix;
}

void Matrix_graph::Prims_algorithm() {
    if(vertex == 0)return;
    Edge* edge = MST::prim_algorithm(table_matrix, nullptr, vertex, edges);
    int** matrix = create_matrix_from_edges(edge, vertex);
    delete[] edge;
    print(matrix, vertex);
    for(int i = 0; i < vertex; i++) delete matrix[i];
    delete[] matrix;
}

void Matrix_graph::Dijikstras_algorithm() {
    if(vertex == 0)return;
    std::cout << "Start vertex: " << start << std::endl;
    Edge* vertexs = QPG::Djikstry_algorithm(table_matrix, nullptr, vertex, start);
    if (vertexs == nullptr) return;
    for(int a = 0; a < vertex; a++){
        Edge edge = vertexs[a];
        std::cout << "Vertex:" << a << " cost: " << edge.weight <<" road: " << edge.endVertex;
        while(edge.startVertex != -1){
            std::cout << " " << edge.startVertex;
            edge = vertexs[edge.startVertex];
        }
        std::cout <<  std::endl;
    }

    delete[] vertexs;
}

void Matrix_graph::Bellmana_Forda_algorithm() {
    if(vertex == 0)return;
    std::cout << "Start vertex: " << start << std::endl;
    Edge* vertexs = QPG::Forda_Belmana_algorithm(table_matrix, nullptr, vertex, start);
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

//metoda nie działa poprawnie
/*void Matrix_graph::Ford_Fulkerson_algorithm() {
    if(vertex == 0)return;
    std::cout << start << " " << end << std::endl;
    MS max_flow(table_matrix, nullptr, start, end, vertex);
    int flow = max_flow.Ford_Fulkerson_algorithm();
    std::cout << "Maksymalny przepływ pomiędzy " << start << "-" << end << " wynosi:" << flow << std::endl;
}*/

// metoda wypisująca macierz jeśli macierz = nullptr to bierze macierz główną i zamienia size na vertex
void Matrix_graph::print(int** matrix, int size) {
    if(matrix == nullptr) {
        matrix = table_matrix;
        size = vertex;
    }

    // wypsiujemy wierzchołek a potem jego sąsiadów w postaci macierzy
    std::cout << "\nMatrix representation:" << std::endl;
    std::cout << std::endl;
    int sum = 0;
    for(int a = 0; a < size; a++){
        std::cout << "Start vertex: " << a << " :";
        for(int b = 0; b < size; b++){
            // podajemy krawędz końcową i wagę i przechodzimy dalej
            if(matrix != table_matrix){
                if(matrix[a][b] != 0){
                    // dla algorymtów drzewa nie trzeba wypisywać całą macierz tylko te miejsca gdzie są wartości
                    std::cout << " (" << b << " " << matrix[a][b] << "), ";
                }
            }else{
                std::cout << " (" << b << " " << matrix[a][b] << "), ";
            }
            sum += matrix[a][b];
        }
        std::cout << std::endl;
    }
    // podajemy sumaryczną wagę listy
    std::cout << "Sumaryczna waga: " << sum << std::endl;
}

void Matrix_graph::delete_matrix() {
    for (int a = 0; a < this->vertex; a++) delete table_matrix[a];
    delete[] table_matrix;
    table_matrix = nullptr;
}