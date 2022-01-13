#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "algo.h"



int main()
{
    
    char command_letter, ch;
    // our input
    char *ptr;

    bool flag = true;
    // making graph
    graph g = {NULL};
    int check = 0, i =0, n = 0;
    // keeping n in pointer outside of loops
    int *vertexs = &n;
    // keeping the number of erased num to make sure we dont step ou tof bounds
    

    while(flag == true)
    {
      printf("Enter Command:\n");
      scanf(" %c", &command_letter);
      if(command_letter == 'A')
      {
        printf("Enter number of vertexs:\n");
        scanf("%d", vertexs);
        if(g.node_array != NULL)
        {
          free(g.node_array);
        }
        // CLEANING THE BUFFER  
        ch = getchar();
        // getting the input
        printf("begin:\n");
        ptr = (char*)malloc(255 * sizeof(char));
        char arr1[255];
        for(i = 0; i < 255 && check == 0; i++)
        {
          ch = getchar();
          if(ch == '\n' || ch == EOF)
          {
              check = 1;
          }
          else
          {
              ptr[i] = ch;
          }
        }

      
      //printf("%s\n", ptr);

        
        g.node_array = (node*)malloc(255 * sizeof(node));
        // creating the graph nodes
        for(i = 0; i < *vertexs; i++)
        {
            node new_node = {i, NULL, NULL};
            g.node_array[i] = new_node;     
        }
        // taking the input and seperate by n
        // then create edge and put them in the right nodes
        char *seperate1 =strtok(ptr, "n");
        int g_edge_counter = 0;
        while(seperate1 != NULL)
        {
            
            char *edge_str;
            edge_str = strdup(seperate1);
            node add_to_node = g.node_array[edge_str[1]];
            node src = g.node_array[edge_str[1]];
            int j;
            edge *new_next = src.edges;
            for(i = 3; i < strlen(edge_str); i = i + 4)
            {
                edge e1 = {edge_str[i + 2] - 48,&(g.node_array[i]), NULL};
                //g.edge_array[g_edge_counter] = e1;
                //g_edge_counter++;
                new_next = &e1;
                new_next = e1.next;
            }
            seperate1 = strtok(NULL, "n");
        }
        // new graph meaning no nodes erased
        
        printf("the graph is updated\n");
      }

     
      


      
 
     

    

    if(command_letter == 'B')
    {
     
        int node_num = 0;
        // clearing the buffer
        ch = getchar();
        printf("input number of node:\n");
        scanf("%d", &node_num);
        ch = getchar();
        printf("begin:\n");
        ch = getchar();
        int check = 0;
        // taking input
        ptr = (char*)malloc(255 * sizeof(char));
        for(i = 0; i < 255 && check == 0; i++)
        {
          ch = getchar();
          if(ch == '\n' || ch == EOF)
          {
              check = 1;
          }
          else
          {
              ptr[i] = ch;
          }
          check = i;
        }
        // taking the node from the array
        // using the num_erased to make sure that we get the right node,
        // since after every erasure, the place the nodes are is down by 1.
        node src = {node_num , NULL, NULL};
        bool is_there = false;
        for(i = 0; i < *vertexs; i++)
        {
          if(g.node_array[i].node_num = node_num)
          {
            src = g.node_array[i];
            src.edges = NULL;
            is_there = true;
          }
        }
        if(is_there == false)
        {       
            g.node_array[*vertexs] = src;
            *vertexs = (*vertexs + 1);
        }
        int g_edge_counter = 0;
        edge *new_next = src.edges;
        for(i = 0; i < check; i = i + 4)
        {
            edge e1 = {ptr[i + 2] - 48,&(g.node_array[i + 2]), NULL};
            //g.edge_array[g_edge_counter] = e1;
            //g_edge_counter++;
            new_next = &e1;
            new_next = e1.next;
        }
        free(ptr);
        printf("the edges of node %d are updated\n", node_num);
    }



    if(command_letter == 'D')
    {
      int node_num = 0;
      ch = getchar();
      printf("input number of node:\n");
      scanf("%d", &node_num);
      ch = getchar();
      for(i = 0; i < *vertexs - 1; i++)
      {
        if(g.node_array[i].node_num = node_num)
        {
          int j = i;
          for(j = i; j < *vertexs -1; j++)
          {
             g.node_array[j] = g.node_array[j + 1];
          }
          (*vertexs) = (*vertexs) - 1;
        }
       
      }
      printf("the node %d has been erased\n", node_num);
    }





  }
  return 0;
}
