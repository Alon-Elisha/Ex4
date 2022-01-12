#include <stdio.h>
#include <stdlib.h>


typedef struct edge_ *pedge;



typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;