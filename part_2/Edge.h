//
// Created by vladimir on 06.04.19.
//

#ifndef PART_2_EDGE_H
#define PART_2_EDGE_H


class Edge {
public:
    int startVertex;
    int endVertex;
    int weight;

    Edge();
    Edge(int s, int e, int w);
    ~Edge();

    bool operator()(const Edge &fist, const Edge &second);

};


#endif //PART_2_EDGE_H
