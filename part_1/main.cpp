#include <iostream>
#include "My_binary_search_tree.h"
#include "My_binary_heap.h"
#include "My_red_black_tree2.h"
#include "My_array2.h"

#include <chrono>
int main(){
    //high_resolution_clock
    /*My_red_black_tree2 *tree = new My_red_black_tree2();
    tree->create_random(15, 10, 30);
    tree->print();
    tree->remove(10);
    tree->print();
    tree->remove(13);
    tree->print();
    tree->remove(16);
    tree->print();
    tree->remove(19);
    tree->print();
    tree->remove(22);*/

    My_array2 a;
    a.create_random(1000, 10, 100);
    a.print();
    a.push_front(10);
    a.add(20,3);
    a.remove(50);


    return 0;
}
