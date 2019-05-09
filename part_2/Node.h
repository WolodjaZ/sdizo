//
// Created by vladimir on 19.04.19.
//

#ifndef PART_2_NODE_H
#define PART_2_NODE_H


class Node{
public:
    Node* next_element;
    int vetrex;
    int weight;

    Node(Node *nextElement, int vetrex, int weight);

    //virtual ~Node();
};


#endif //PART_2_NODE_H
