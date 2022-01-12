#include "edges.h"
#include "nodes.h"

int getWeight(edge a)
{
    int g = a->weight;
    return g;
}

node* getEndpoint(edge a)
{
    node *pnode = a->endpoint;
    return pnode;
}