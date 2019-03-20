//
// Created by vladimir on 16.03.19.
//

#ifndef PART_1_MY_BINARY_SEARCH_TREE_H
#define PART_1_MY_BINARY_SEARCH_TREE_H

#include <clocale>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

class My_binary_search_tree {
public:
    struct Node{
        int data;
        Node *left, *right, *parent;
    };

private:
    int size;
    Node* root;

public:
    My_binary_search_tree();
    ~My_binary_search_tree();

    Node* find(int value);

    void add(int value);
    void remove(int value);

    void print();

    void create_random(int size, int minimum, int maximum);

    void create_from_a_file(int size ,std::string name);

private:
    void printHelp(Node* v, int in);

    void deleteHelper(Node* element);

    Node* findHelper(int value, Node* element);

    void transplant(Node* first, Node* second);

    Node* mini_value(Node* element);
    Node* max_value(Node* element);

    Node* rotate_left(Node* element);
    Node* rotate_right(Node* element);

    void dswHelper();
    void dsw();

};


#endif //PART_1_MY_BINARY_SEARCH_TREE_H
