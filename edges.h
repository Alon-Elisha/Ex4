#include <stdio.h>
#include <stdlib.h>



typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


int getWeight(edge a);





