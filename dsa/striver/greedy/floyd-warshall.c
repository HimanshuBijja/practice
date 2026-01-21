// C program to implement Floyd-Warshall algorithm for all pairs shortest path problem

#include <stdio.h>
#include <limits.h>

#define v 4
#define INF 99999

void main()
{
    int n, c[10][10], i, j, k;
    printf("\nEnter number of vertices:");
    scanf("%d", &n);
    printf("\nEnter adjacency matrix");
    printf("\nEnter 0 for self-loop & enter 999 if no direct edge between two vertices\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &c[i][j]);
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (c[i][k] + c[k][j] < c[i][j])
                    c[i][j] = c[i][k] + c[k][j];
            }
        }
    }
    printf("All pairs shortest path matrix is...\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (c[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", c[i][j]);
        }
        printf("\n");
    }
}