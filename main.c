#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "algo.h"



int main()
{
    char command_letter, ch;
    char *ptr;
    /*
    printf("Enter Command:\n")
    scanf(" %c", command_letter)
    */
    bool flag = true;
    graph g = {NULL, NULL};
    int check = 0, i =0, n = 0;

    while(flag == true)
    {
      printf("Enter Command:\n");
      scanf(" %c", &command_letter);
      if(command_letter == 'A')
      {
        printf("Enter number of vertexs:\n");
        scanf("%d", &n);
        if(g.node_array != NULL)
        {
          free(g.node_array);
          free(g.edge_array);
        }
        // CLEANING THE BUFFER  
        ch = getchar();
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

      }
      //printf("%s\n", ptr);

      printf("%s\n","-----------------------");
      g.node_array = (node*)malloc(255 * sizeof(node));
      g.edge_array = (edge*)malloc(255 * sizeof(edge));
      for(i = 0; i < n; i++)
      {

        node new_node = {i, NULL, NULL};
        g.node_array[i] = new_node;     
      }
      char *seperate1 =strtok(ptr, "n");
      int g_edge_counter;
      while(seperate1 != NULL)
      {
        printf("string = %s\n", seperate1); //printing each token
        char *edge_str;
        edge_str = strdup(seperate1);
        node add_to_node = g.node_array[edge_str[1]];
        node src = g.node_array[edge_str[1]];
        int j;
        edge *new_next = src.edges;
        for(i = 3; i < strlen(edge_str); i = i + 4)
        {
            edge e1 = {edge_str[i + 2] - 48,&(g.node_array[i]), NULL};
            g.edge_array[g_edge_counter] = e1;
            g_edge_counter++;
            new_next = &e1;
            new_next = e1.next;
        }
        seperate1 = strtok(NULL, "n");
      }

     
      

      edge *this_edge = g.edge_array;
      for(i = 0; i < 3; i++)
      {
        printf("%d", this_edge[i].weight);
        
      }
      
 
      flag = false;

    }

}



