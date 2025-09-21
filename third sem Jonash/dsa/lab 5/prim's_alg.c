#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INF 9999999
#define V 5 // number of vertices

// Graph represented using adjacency matrix
int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

int main()
{
    printf("\t*****Compiled by Jonash Chataut*****\n");

    int no_edge = 0; // Number of edges in MST
    int selected[V]; // Array to track selected vertices
    memset(selected, false, sizeof(selected));

    selected[0] = true; // Start from vertex 0

    int x, y; // Indexes to store the selected edge

    printf("Edge   : Weight\n");

    while (no_edge < V - 1)
    {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && G[i][j])
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d -> %d : %d\n", x, y, G[x][y]);
        selected[y] = true; // Mark the node as selected
        no_edge++;
    }

    return 0;
}
