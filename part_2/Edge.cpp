//
// Created by vladimir on 06.04.19.
//

#include "Edge.h"

bool Edge::operator()(const Edge &fist, const Edge &second) {
    return fist.weight > second.weight? true: false;
}

Edge::Edge() {
    this->startVertex = 0;
    this->endVertex = 0;
    this->weight = 0;
}

Edge::Edge(int s, int e, int w)
{
    this->startVertex = s;
    this->endVertex = e;
    this->weight = w;
}

Edge::~Edge()
{
    this->startVertex = 0;
    this->endVertex = 0;
    this->weight = 0;
}