#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;

// Number of vertices in given graph
#define V 6

/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(int rGraph[V+2][V+2], int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V+2];
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

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[V+2][V+2], int s, int t)
{
    int u, v;

    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int rGraph[V+2][V+2]; // Residual graph where rGraph[i][j] indicates
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)
    for (u = 0; u < V+2; u++)
        for (v = 0; v < V+2; v++)
             rGraph[u][v] = graph[u][v];

    int parent[V+2];  // This array is filled by BFS and to store path

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
    for(int i=0;i<V+2;i++){
        for(int j=0;j<V+2;j++){
            cout<<rGraph[i][j]<<" ";
        }
        cout<<endl;
    }
    int tag=0;
    for(int i=0;i<6;i++){
        if(rGraph[6][i]!=0){
            tag=-1;
            return tag;
        }
    }

    for(int i=0;i<6;i++){
        if(rGraph[i][7]!=0){
            tag=-1;
            return tag;
        }
    }

    return max_flow;
}
int main()
{
    // Let us create a graph shown in the above example
    int graph[V+2] [V+2] = { {0, 1, 2, 0, 0, 0, 0, 0},
                        {0, 0, 0, 3, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1, 0, 0, 0},
                        {0, 0, 0, 0, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 3, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0}
                      };

    int supply[6]={3,3,0,1,0,0};
    int demand[6]={0,0,1,0,1,5};

    for(int i=0;i<6;i++){
        graph[6][i] = supply[i];
        graph[i][7] = demand[i];
    }
    int val=fordFulkerson(graph, 6, 7);

    if(val==-1){
        cout<<"it is not possible"<<endl;
    }
     cout << "The maximum possible flow is " <<val <<endl;

    /*for(int i=0;i<V+2;i++){
        for(int j=0;j<V+2;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }*/

}
