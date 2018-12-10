#include<bits/stdc++.h>

using namespace std;

vector< vector<string> >vs;

int di[]={-1,1,0,0,0,0};
int dj[]={0,0,-1,1,0,0};
int dk[]={0,0,0,0,-1,1};

bool visited[30][30][30];

int tb,row,col;


struct node{

    int a,b,c,w;
    node(int i,int j,int z,int wt){

        a=i;
        b=j;
        c=z;
        w=wt;
    }

};

void bfs(int a,int b,int c){

    queue<node>q;
    q.push(node(a,b,c,0));
    memset(visited,false,sizeof(visited));

    visited[a][b][c] = true;
    while(!q.empty()){

        node temp = q.front();
        q.pop();

        //cout<<a<<b<<c<<endl;
        if(vs[temp.a][temp.b][temp.c]=='E'){
            cout<<"Escaped in "<<temp.w<<" minute(s)."<<endl;
            return;
        }

        int I,J,K;
        for(int i=0;i<6;i++){

            I = temp.c+di[i];
            J = temp.b+dj[i];
            K = temp.a+dk[i];

            if(K>=0 && K<tb && I>=0 && I<col && J>=0 && J<row && visited[K][J][I]==false &&
               vs[K][J][I]!='#'  ){

                    //cout<<K<<"  "<<J<<"  "<<I<<" "<<temp.w<<endl;
                    q.push(node(K,J,I,temp.w+1));
                    visited[K][J][I] = true;
               }

        }




    }
    cout<<"Trapped!"<<endl;

}


int main(){


    while(1){

        cin>>tb>>row>>col;
        if(tb==0 && row==0 && col==0)break;
        string s;`
        vector<string>v;
        vs.clear();

        for(int i=0;i<tb;i++){
            v.clear();
            for(int j=0;j<row;j++){
                cin>>s;
                v.push_back(s);
            }
            vs.push_back(v);
        }
        int a,b,c;

        for(int k=0;k<tb;k++){
            for(int j=0;j<row;j++){
                for(int i=0;i<col;i++){
                    if(vs[k][j][i]=='S'){
                        a=k;
                        b=j;
                        c=i;
                        goto h;
                    }
                }
            }
        }

        h:
        bfs(a,b,c);

    }

}
