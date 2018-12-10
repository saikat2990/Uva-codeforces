#include<bits/stdc++.h>

using namespace std;

typedef vector<string>vs;
typedef map<string,vs>msvs;
typedef map<string,int>msi;
typedef map<string,string>mss;
stack<char>vc;


msi visited;
mss route;

void bfs(string s,string e,msvs graph){

    visited[s] = 1;
    queue<string>q;
    q.push(s);
    route[s] = s;

    while(!q.empty()){

        string frt = q.front();
        q.pop();
        if(frt==e)break;

        //for(int i=0;i<graph[frt].size();i++){
           // cout<<graph[frt][i]<<" ";
        //}
        //cout<<endl;//

        for(int i=0;i<graph[frt].size();i++){

            if(!visited.count(graph[frt][i])){

                visited[graph[frt][i]] = visited[frt]+1;
                q.push(graph[frt][i]);
                route[graph[frt][i]] = frt;
                //cout<<graph[frt][i]<<" is son of "<<frt<<endl;
            }
        }

    }

}

void print(string s,string e){

    if(s==e){ cout<<s[0]; return;}
    //vc.push(e[0]);

    print(s,route[e]);
    cout<<e[0];

}

int main(){
    //freopen("dada.txt","w",stdout);


    int test;
    cin>>test;

    while(test--){

        int connect,check;
        cin>>connect>>check;
        msvs graph;
        for(int i=0;i<connect;i++){

            string a,b;
            cin>>a>>b;

            graph[a].push_back(b);
            graph[b].push_back(a);

        }

        string s,e;
        for(int i=0;i<check;i++){

            cin>>s>>e;
            //vc.clear();
            visited.clear();
            route.clear();
            bfs(s,e,graph);

            print(s,e);
            //vc.push(s[0]);
            //for(int j=0;j<vc.size();j++)cout<<vc[j];
            //while(!vc.empty()){cout<<vc.top(); vc.pop();}
            cout<<endl;

        }
        if(test!=0)cout<<endl;
    }


return 0;
}
