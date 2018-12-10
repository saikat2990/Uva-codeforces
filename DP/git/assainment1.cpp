#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<fstream>

using namespace std;

bool art[100];

int dis[100];
int parent[100];
bool tag[100];
int t=0;
int low[100];



void content(int a,int b,vector<int>vec[]){

    vec[a].push_back(b);
    vec[b].push_back(a);

}

void dfs(int u,int prent,vector<int>vec[],vector<int>&arti){


    t++;
    parent[u] = prent;
    tag[u] = true;
    low[u] = t;
    dis[u] = t;
    int child=0;
    vector<int>::iterator it;

    for(it=vec[u].begin();it!=vec[u].end();it++){

        int v=*it;

        if(tag[v]==false){
             child++;
            dfs(v,u,vec,arti);

            low[u] = min(low[u],low[v]);

            if(parent[u]!=-1 && dis[u]<=low[v]){
                    if(art[u]==false){
                        art[u] = true;
                        arti.push_back(u);
                    }
            }

            if(parent[u]==-1 && child>1)arti.push_back(u);



        }else if(parent[u]!=v){

            low[u] = min(dis[v],low[u]);

        }

    }


}


int main(){

    //vector<int>vec[10];

    ofstream ofile;
    ofile.open("mother_fuck.txt");

    t=0;


    while(1){

        vector<int>vec[100];
        vector<int>arti;
        string str;
        int check;
        cin>>check;
        getline(cin,str);

        if(check==0)break;


        while(1){
            stringstream iss;
            getline(cin,str);
            iss<<str;
            int root,a;
            iss>>root;
           // cout<<"root   "<<root<<endl;
            if(root==0)break;

            while(iss>>a){
                content(root,a,vec);
                //cout<<a<<" ";
            }
        }

            for(int i=0;i<=check;i++){tag[i]=false; art[i]=false; parent[i]=-1;}

            vector<int>::iterator it;
            int p;
            //dfs(1,-1,vec,arti);

            for(int i=1;i<=check;i++){
                if(tag[i]==false){
                        dfs(i,-1,vec,arti);
                        p=i;
                        break;
                }
            }

            /*for(it=vec[p].begin();it!=vec[p].end();it++){
                int v=*it;
                if(tag[v]==false){
                    child++;
                    dfs(v,p,vec,arti);
                }
            }*/


            for(int i=1;i<=check;i++){
                for( it=vec[i].begin(); it!=vec[i].end(); it++){
                    //cout<<*it<<" ";
                }
               // cout<<endl;
            }


            for(it=arti.begin();it!=arti.end();it++){
                cout<<"    "<<*it<<endl;
            }

            //cout<<child<<endl;
            ofile<<arti.size()<<endl;

            for(int i=0;i<=100;i++){
                dis[i]=0;
                parent[i]=-1;
                low[i]=0;
            }

    }

return 0;

}
