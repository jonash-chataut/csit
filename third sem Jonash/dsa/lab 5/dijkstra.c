#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // for INT_MAX

#define V 6 // number of vertices

int miniDist(int distance[], bool Tset[]) // calculating minimum distance
{
    int minimum = INT_MAX, ind = -1;

    for (int k = 0; k < V; k++)
    {
        if (!Tset[k] && distance[k] <= minimum)
        {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[V][V], int src) // adjacency matrix
{
    int distance[V]; //  array to calculate the minimum distance for each node
    bool Tset[V];    // boolean array to mark visited and unvisited for each node

    for (int k = 0; k < V; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0; // Source vertex distance is set 0

    for (int count = 0; count < V - 1; count++)
    {
        int m = miniDist(distance, Tset);
        if (m == -1)
            break; // all reachable nodes done
        Tset[m] = true;

        for (int j = 0; j < V; j++)
        {
            // updating the distance of neighbouring vertex
            if (!Tset[j] && graph[m][j] && distance[m] != INT_MAX &&
                distance[m] + graph[m][j] < distance[j])
            {
                distance[j] = distance[m] + graph[m][j];
            }
        }
    }

    printf("Vertex\t\tDistance from Source\n");
    for (int k = 0; k < V; k++)
    {
        char vertex = 'A' + k;
        if (distance[k] == INT_MAX)
            printf("%c\t\t\t∞\n", vertex);
        else
            printf("%c\t\t\t%d\n", vertex, distance[k]);
    }
}

int main()
{
	printf("\t*****Complied by Jonash Chataut*****\n");
    int graph[V][V] = {
        {0, 1, 2, 0, 0, 0},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}};

    DijkstraAlgo(graph, 0); // starting from vertex A (index 0)
    return 0;
}