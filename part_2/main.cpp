#include <iostream>

#include "List_graph.h"
#include "Matrix_graph.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    List_graph l;
    //l.readFromFile("/home/vladimir/Desktop/github-file/sdizo_project/part_2/text.txt", 2);
    l.generator(12, 50, 1, 10, 1);
    l.print(nullptr, 0);
    l.Dijikstras_algorithm();
    l.Bellmana_Forda_algorithm();

    Matrix_graph m;
    //m.readFromFile("/home/vladimir/Desktop/github-file/sdizo_project/part_2/text.txt", 2);
    m.generator(12, 50, 1, 10, 1);
    m.print(nullptr, 0);
    l.Dijikstras_algorithm();
    l.Bellmana_Forda_algorithm();

    return 0;
}