#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int parent[9];
int low[9];
int dis[9];
bool tag[9];
vector<int>gp[9];
vector<int>ap;

int co=0;

void content(int a,int b){

    gp[a].push_back(b);
    gp[b].push_back(a);

}

void DFS(int u,int time,int prent){

    parent[u] = prent;
    low[u] = time;
    dis[u] =  time;

    vector<int>:: iterator it;

     for(it = gp[u].begin();it!= gp[u].end();it++){

        int v= *it;

        if(tag[v]==false){

            tag[v] = true;
            time++;
            DFS(v,time,u);
            low[u] = min(low[u],low[v]);

            if(dis[u]<=low[v])ap.push_back(u);

            else

        }else if(v!=parent[u]){

            low[u] = min(low[u],dis[v]);

        }

     }

}

int main(){

    content(4,3);
    content(3,1);
    content(1,2);
    content(2,3);
    content(4,5);
    content(5,6);
    content(5,8);
    content(6,8);
    content(6,7);
    content(6,5);

    vector<int>::iterator it;
    int choise;
    cin>>choise;
    tag[choise] = true;


    for(it = gp[choise].begin(); it!=gp[choise].end(); it++){

        tag[*it]=true;
        DFS(*it,co+1,choise);

    }
    for(it = ap.begin();it!=ap.end();it++)cout<<"  "<<*it;

return 0;
}
