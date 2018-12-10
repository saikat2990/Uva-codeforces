#include<bits/stdc++.h>

using namespace std;

#define V 6
#define Max 99999

bool bfs(int newGraph[V][V],int s,int d,int parent[V]){

    queue<int>q;
    bool visit[V];
    for(int i=0;i<V;i++)visit[i]=false;
    //int parent[V];
    parent[s]= -1;

    q.push(s);
    while(!q.empty()){

        int u = q.front();
        q.pop();
        visit[u]=true;
        for(int v=0;v<V;v++){

            if(visit[v]==false && newGraph[u][v]>0){
                parent[v]=u;
                q.push(v);
                //visit[v]=true;
            }
        }

    }
    if(visit[d]==true)return true;
    else return false;

}

int main(){

    int graph[V][V] = {
                            {0,16,13, 0, 0, 0},
                            {0, 0,10,12, 0, 0},
                            {0, 4, 0, 0,14, 0},
                            {0, 0, 9, 0, 0,20},
                            {0, 0, 0, 7, 0, 4},
                            {0, 0, 0, 0, 0, 0}
                        };

    int newGraph[V][V];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            newGraph[i][j] = graph[i][j];
        }
    }

    int s,d;
    cin>>s>>d;
    int parent[V]={};
    int sum=0;

    while(bfs(newGraph,s,d,parent)){

        for(int i=0;i<V;i++){
            cout<<parent[i]<<" ";
        }
        int minVal = Max;

        for(int v=d;v!=s;v=parent[v]){
            int u = parent[v];
            cout<<newGraph[u][v]<<" ";
            minVal = min(newGraph[u][v],minVal);
        }

        for(int v=d;v!=s;v=parent[v]){

            int u = parent[v];
            newGraph[u][v] = newGraph[u][v]-minVal;
        }
        sum+=minVal;
        cout<<endl;
    }
    cout<<sum;

return 0;
}
