#include <iostream>

#include "Matrix.h"
#include "Eratosthenes_sieve.h"
#include "Sum_table.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Sum_table s(10,4,1);
    s.print();
    s.start();
    s.print_result();



    Matrix m(10,8,8,10,2);
    m.print();
    m.start();
    m.print_result();

    Eratosthenes_sieve e(100,2);
    e.start();
    e.print();
}
