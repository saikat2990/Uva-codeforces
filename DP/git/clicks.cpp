#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>

#define Max 99999

using namespace std;

int dist[1000];
bool tag[1000];
vector<int>vec[1000];
int checkcost[1000];
int cost=0;

void dfs(int node,int time){

    tag[node] = true;
    time=time+1;

    vector<int>::iterator it;
    for(it = vec[node].begin();it!=vec[node].end();it++){

       if(tag[*it]==false){

           cout<<time<<endl;
           cost+=time;
           checkcost[*it] = time;
           dfs(*it,time);
       }
       else {
            cout<<"   backtracking time"<<time<<endl;
         if(checkcost[*it]>time){

                cost=cost-(checkcost[*it])+time;
                checkcost[*it]=time;
                cout<<"   new cost "<<(*it)<<"  "<<time<<endl;
         }
       }

    }

}

int main(){
    int cases=1;
    while(1){
        vector<int>node;
        bool nodecheck[1000]={};
        int cn=0;
        while(1){

            int a,b;
            cin>>a>>b;

            if(a==0 && b==0)break;

            if(nodecheck[a]==false){ vec[a].clear(); nodecheck[a] = true; node.push_back(a); cn++;}
            if(nodecheck[b]==false){ vec[b].clear();  nodecheck[b] = true; node.push_back(b); cn++;}

            vec[a].push_back(b);

        }
        int time=0;
        vector<int>:: iterator it;

        for(it = node.begin();it!=node.end();it++){
            for(int i=0;i<1000;i++){tag[i]=false; checkcost[i]=0;}
            cout<<"   -->"<<*it<<endl;
            dfs(*it,0);
        }
        cout<<cost<<endl;
        float f= (float)cost/(float)(cn*(cn-1));
        //cout<<f<<endl;
        printf("Case %d average length between pages cases%.3f",cases,f);
        cases++;
        cost=0;
        //node.clear();
    }
 return 0;
}
