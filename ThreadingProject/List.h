//
// Created by vladimir on 24.04.19.
//

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H

#include <iostream>

class List {
public:
    struct Node{
        int data;
        Node *prev, *next;
    };

private:
    int length;
    Node* head;
    Node* tail;

public:

    List();
    ~List();

    int getLength();

    void push_front(int data);
    Node* pop_front();

    void push_tail(int data);
    Node* pop_tail();

    bool find_by_value(int data);
    Node* find(int index);
    void add(int index, int data);
    void remove_by_value(int data);
    void remove(int index);

    void print();

};

#endif //UNTITLED_LIST_H
