#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

// Number of vertices in given graph
#define V 6

struct st{
    int index;
    int value;
};

/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V+V+2][V+V+2], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V+V+2];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v=0; v<V+V+2; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V+V+2][V+V+2], int s, int t)
{
    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int rGraph[V+V+2][V+V+2]; // Residual graph where rGraph[i][j] indicates
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)
    for (u = 0; u < V+V+2; u++)
        for (v = 0; v < V+V+2; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V+V+2];  // This array is filled by BFS and to store path

    int max_flow = 0;  // There is no flow initially

    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}
int main(){

    int graph[V+V+2][V+V+2] = {
                        {0, 16, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 4, 0, 0, 14, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 9, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 7, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
    int sum1=0;


    for(int i=0;i<6;i++){

        for(int j=0;j<6;j++){
            if(graph[i][j]!=0){
                sum+=graph[i][j];
                sum1+=graph[i][j];
            }
        }
        graph[12][i]=sum1;
        graph[i+6][13]= sum1;
        sum1=0;
    }
    sum++;

    for(int i=0;i<6;i++){

        for(int j=0;j<6;j++){
            if(graph[i][j]!=0){
                graph[i][j+6]=graph[i][j];
                graph[i][j]=0;
            }
        }
    }

    for(int i=0;i<6;i++){
        graph[i][i+6]=sum;
    }

    for(int i=0;i<14;i++){

        for(int j=0;j<14;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "The maximum possible flow is " << fordFulkerson(graph, 12, 13);

return 0;
}
