//
// Created by vladimir on 06.04.19.
//

#include <iomanip>
#include "Matrix_graph.h"

Matrix_graph::Matrix_graph() {

}

Matrix_graph::~Matrix_graph() {
    for (int a = 0; a < this->vertex; a++) delete table_matrix[a];
    delete[] table_matrix;
}

void Matrix_graph::readFromFile(std::string path, std::string type) {
    std::fstream file;
    file.open(path, std::ios::in);

    if (file.good())
    {
        if (type == 'nieskierowany') directed = false;
        else directed = true;

        file >> edges >> vertex;
        int i, j;

        table_matrix = new int*[vertex];
        for (i = 0; i < vertex; i++) table_matrix[i] = new int[vertex];

        for (i = 0; i < vertex; i++) {
            for (j = 0; j < vertex; j++) {
                table_matrix[i][j] = 0;
            }
        }

        int startVertex, endVertex, weight;

        for (i = 0; i < edges; i++)
        {
            file >> startVertex >> endVertex >> weight;
            table_matrix[startVertex][endVertex] = weight;
            if (type == "nieskierowany") table_matrix[endVertex][startVertex] = weight;
        }

        file.close();
    }
    else std::cout << "Error opening file!!!" << std::endl;

}

int Matrix_graph::get(int start_vertex, int end_vertex) {
    return this->table_matrix[start_vertex][end_vertex];
}

PriorityQueue* Matrix_graph::create_priority_queue() {
    PriorityQueue priorityQueue(edges);
    for(int a = 0; a < vertex; a++){
        for(int i = 0; i < vertex; i++){
            if(table_matrix[a][i] != 0){
                priorityQueue.push(Edge(a,i, table_matrix[a][i]));
            }
        }
    }
    return &priorityQueue;
}

int** Matrix_graph::create_matrix_from_edges(Edge* edge, int size) {
    int ** matrix = new int* [this->vertex];
    for (int j = 0; j < this->vertex; ++j) {
        matrix[j] = new int[this->vertex];
    }
    for(int i = 0; i < size; i++){
        matrix[edge[i].startVertex][edge[i].endVertex] = edge[i].weight;
        if(!directed) matrix[edge[i].endVertex][edge[i].startVertex] = edge[i].weight;
    }
}

void Matrix_graph::Kruskal_algorithm() {
    PriorityQueue* priorityQueue = create_priority_queue();
    Edge *edge = MST::kruskal_algorithm(priorityQueue, this->vertex);
    int** matrix = create_matrix_from_edges(edge, sizeof(edge));
    delete edge;
    print(matrix);
    for(int i = 0; i < vertex; i++) delete matrix[i];
    delete[] matrix;
}

void Matrix_graph::print(int** matrix) { // do poprawienia

    std::cout << "   ";
    for(int i = 0; i < this->vertex; i++) std::cout << std::setw(3) << i;
    std::cout << std::endl << std::endl;
    for(int i = 0; i < this->vertex; i++)
    {
        std::cout << std::setw(3) << i;
        for(int j = 0; j < this->vertex; j++) std::cout << std::setw(3) << (int) matrix[i][j];
        std::cout << std::endl;
    }


    /* int i, j;
    std::cout << "\nMatrix representation: " << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(4) << " ";

    for (i = 0; i < edges; i++) std::cout << std::setw(4) << i;
    std::cout << std::endl << std::endl;

    for (i = 0; i < vertex; i++)
    {
        std::cout << std::setw(4) << i;
        for (j = 0; j < ; j++) std::cout << std::setw(4) << (int)table_matrix[i][j];
        std::cout << std::endl;
    }

    std::cout << "\nWeights of edges: " << std::endl;
    for (int i = 0; i < edges; i++)
    {
        std::cout << std::setw(2) << i << "->(" << edge_weight[i] << ")";
    }
    std::cout << std::endl;*/
}