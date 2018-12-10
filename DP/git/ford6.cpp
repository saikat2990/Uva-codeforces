
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

// Number of vertices in given graph
#define V 12


bool bfs(int rGraph[V+2][V+2], int s, int t, int parent[])
{

    bool visited[V+2];
    memset(visited, 0, sizeof(visited));


    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;


    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V+2; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }


    return (visited[t] == true);
}


int fordFulkerson(int graph[V+2][V+2], int s, int t)
{
    int u, v;


    int rGraph[V+2][V+2];
    for (u = 0; u < V+2; u++)
        for (v = 0; v < V+2; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V+2];

    int max_flow = 0;


    while (bfs(rGraph, s, t, parent))
    {

        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }


        max_flow += path_flow;
    }

    return max_flow;
}
int main()
{
    int graph[V+2][V+2] = { {0, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 3, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 3, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                      };

    int sum=0;
    for(int i=0;i<6;i++){
            for(int j=0;j<14;j++){
                sum+=graph[i][j];
            }
        graph[12][i]= sum;
        sum=0;
    }
    sum=0;

    for(int i=6;i<12;i++){
        for(int j=0;j<14;j++){
            sum+=graph[j][i];
        }
        graph[i][13]=sum;
        sum=0;
    }

    for(int i=0;i<14;i++){
        for(int j=0;j<14;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << "The maximum possible flow is " <<fordFulkerson(graph, 12, 13) <<endl;

    return 0;
}
