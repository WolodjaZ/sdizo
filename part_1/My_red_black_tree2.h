//
// Created by vladimir on 17.03.19.
//

#ifndef PART_1_MY_RED_BLACK_TREE2_H
#define PART_1_MY_RED_BLACK_TREE2_H


#include <clocale>
#include <iostream>
#include <fstream>
#include <math.h>

class My_red_black_tree2 {
public:
    struct Node{
        int data;
        Node *left, *right, *parent;
        bool color;
    };

private:
    //wartownik
    Node* war;
    int size;
    Node* root;

public:
    My_red_black_tree2();
    ~My_red_black_tree2();

    Node* find(int value);

    void add(int value);
    void remove(int value);

    void print();

    void create_random(int size, int minimum, int maximum);

    void create_from_a_file(int size ,std::string name);

private:
    void addHelper(Node* element);

    void removeHelper(Node* element);

    void deleteHelper(Node* element);

    Node* findHelper(int value, Node* element);

    void transplant(Node* first, Node* second);

    Node* mini_value(Node* element);
    Node* max_value(Node* element);

    Node* rotate_left(Node* element);
    Node* rotate_right(Node* element);

    void printHelp(Node* v, int in);


};


#endif //PART_1_MY_RED_BLACK_TREE2_H
