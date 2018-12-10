#include<bits/stdc++.h>

using namespace std;

struct node{

    int a,b,cost;
    node(int t, int r,int wt){
        a=t;
        b=r;
        cost= wt;
    }

};

int di[]={-1,1,0,0};
int dj[]={0,0,-1,1};

bool visited[50][50];

int main(){

    while(1){
        int row,col;
        memset(visited,false,sizeof(visited));

        cin>>row>>col;
        if(row==0 && col==0)break;

        for(int i=0;i<row;i++){

            for(int j=0;j<col;j++){
                int tag;
                cin>>tag;
                if(tag==1){
                    visited[i][j]=true;
                    //cout<<endl<<"("<<i<<","<<j<<")";
                }
            }
        }

        int sx,sy,fx,fy;
        cin>>sx>>sy>>fx>>fy;
        //cout<<endl<<sx<<" "<<sy<<endl;;

        queue<node>q;
        q.push(node(sx-1,sy-1,1));
        visited[sx-1][sy-1]=true;

        while(!q.empty()){

            node temp = q.front();
            q.pop();
            cout<<temp.a<<"  "<<temp.b<<endl;
            if((fx-1)==temp.a && (fy-1)==temp.b){
                cout<<temp.cost<<endl;
                break;
            }
            //visited[temp.a][temp.b] = true;

            int x,y;
            for(int i=0;i<4;i++){

                x = temp.a + di[i];
                y = temp.b + dj[i];
                cout<<x<<"     "<<y<<endl;
                if(visited[x][y]==false && x>=0 && x<row && y>=0 && y<col){
                    visited[x][y] = true;
                    cout<<x<<"  "<<y<<endl;
                    q.push(node(x,y,temp.cost+1));
                }
            }

        }
        if(q.empty()){
            cout<<"-1"<<endl;
        }
    }
return 0;
}
