#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<fstream>

using namespace std;

#define Max 1001

struct hell{
    int u,v;
};

int gr[Max][Max];
bool tag[Max]={0};
vector<int >vec;
int n,m,dis[Max],low[Max];
int t=0;

void dfs(int parent,int v){

   // time++;
    dis[v]=t+1;
    low[v]=t+1;
    t++;
    tag[v] = true;
    for(int i=0;i<=n;i++){

        if(gr[v][i]){

            if(tag[i]==false){

                dfs(v,i);
                low[v] = min(low[v],low[i]);
                if(low[i]<=dis[v]){
                    gr[i][v]=0;
                    //vec.push_back(v);
                }

            }else if( i!=parent){
                low[v] = min(low[v],dis[i]);
                gr[i][v]=0;
            }

        }
    }


}

int main(){

    //ofstream ifile;
    //ifile.open("hel.txt");

    int c=1;
    while(1){

        cin>>n>>m;
        if(n==0 && m==0 )break;
        cout<<c<<endl<<endl;
        c++;
        for(int i=0;i<=n;i++)tag[i] = false;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)gr[i][j]=0;
        }
        for(int i=0;i<m;i++){

            int a,b;
            cin>>a>>b;
            gr[a][b]=1;
            gr[b][a]=1;

        }
       // for(int i=0;i<=n;i++){
           // for(int j=0;j<=n;j++)cout<<gr[i][j];
            //cout<<endl;
       // }

        for(int i=1;i<=n;i++){
            if(tag[i]==false )dfs(i,i);
        }
         for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(gr[i][j]==1)cout<<i<<" "<<j<<endl;

        /*vector<int>::iterator it;
        for(it=vec.begin();it!=vec.end();it++)
            cout<<*it<<"  ";*/

        cout<<"#"<<endl;
    }


return 0;
}
