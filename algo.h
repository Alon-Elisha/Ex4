#include "nodes.h"
#include "edges.h"

/*
#ifndef GRAPH_NODE_
#define GRAPH_NODE_


#ifndef edge_
#define edge_
*/

typedef struct Graph_ {
    //edge* edge_array;
    node* node_array;
} graph;




void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

