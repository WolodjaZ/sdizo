#include <iostream>

#include "List_graph.h"
#include "Matrix_graph.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    List_graph l;
    //l.readFromFile("/home/vladimir/Desktop/github-file/sdizo_project/part_2/text.txt", 2);
    //l.generator(12, 50, 0, 10, 1);
    //l.print(nullptr, 0);
    //l.Kruskal_algorithm();
    //l.Prims_algorithm();
    
    double result1 = 0;
    double result2 = 0;
    double result3 = 0;
    double result4 = 0;
    l.generator(8, 25, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(12, 25, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(20, 25, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(50, 25, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

    result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(100, 25, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

    result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(8, 50, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

 result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(12, 50, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(20, 50, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(50, 50, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(100, 50, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;


    result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(8, 75, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(12, 75, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(20, 75, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(50, 75, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(100, 75, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

    result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(8, 99, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;



    result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(12, 99, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(20, 99, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(50, 99, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    l.generator(100, 99, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += l.Prims_algorithm().count();
        result2 += l.Kruskal_algorithm().count();
        result3 += l.Dijikstras_algorithm().count();
        result4 += l.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Lista Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Lista Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Lista Bellmana: " << (result1/100)*1000000000 << std::endl;

    Matrix_graph m;

    result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(8, 25, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;


result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(12, 25, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(20, 25, 0, 1, 12);
    for(int a = 0; a < 100; a++){
      result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(50, 25, 0, 1, 12);
    for(int a = 0; a < 100; a++){
result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(100, 25, 0, 1, 12);
    for(int a = 0; a < 100; a++){
result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

    result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(8, 50, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;


result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(12, 50, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(20, 50, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(50, 50, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(100, 50, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

    result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(8, 75, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;


result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(12, 75, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(20, 75, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(50, 75, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(100, 75, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

    result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(8, 99, 0, 1, 12);
    for(int a = 0; a < 100; a++){
        result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;


    result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(12, 99, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(20, 99, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(50, 99, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

result1 = 0;
    result2 = 0;
    result3 = 0;
    result4 = 0;
    m.generator(100, 99, 0, 1, 12);
    for(int a = 0; a < 100; a++){
       result1 += m.Prims_algorithm().count();
        result2 += m.Kruskal_algorithm().count();
        result3 += m.Dijikstras_algorithm().count();
        result4 += m.Bellmana_Forda_algorithm().count();
    }

    std::cout << "Macierz Prim: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Kruskal: " << (result1/100)*1000000000 << std::endl;
    std::cout << "Macierz Djikstry: " << (result2/100)*1000000000 << std::endl;
    std::cout << "Macierz Bellmana: " << (result1/100)*1000000000 << std::endl;

    

    //Matrix_graph m;
    //m.readFromFile("/home/vladimir/Desktop/github-file/sdizo_project/part_2/text.txt", 2);
    //m.generator(12, 50, 0, 10, 1);
    //m.print(nullptr, 0);
    //m.Kruskal_algorithm();
    //m.Prims_algorithm();

    return 0;
}