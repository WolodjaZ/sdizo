#include <iostream>

#include "List_graph.h"
#include "Matrix_graph.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    List_graph l;
    l.readFromFile(reinterpret_cast<const char *>('text.txt'), 0);
    l.Kruskal_algorithm();
    return 0;
}