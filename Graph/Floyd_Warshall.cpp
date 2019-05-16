// For shortest path in a weighted directed graph
#include <iostream>

#define V 4
#define INF 99999

using namespace std;

void floydwarshall(int graph[V][V])
{
    int dest[V][V];
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            dest[i][j] = graph[i][j];
        }
    }
    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(dest[i][j] > dest[i][k] + dest[k][j])
                {
                    dest[i][j] = dest[i][k] + dest[k][j];
                }
            }
        }
    }
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cout << dest[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int graph[V][V] = {{0, 5,  INF, 10}, 
                      {INF, 0,   3, INF}, 
                      {INF, INF, 0,   1}, 
                      {INF, INF, INF, 0}};
    floydwarshall(graph);
}
