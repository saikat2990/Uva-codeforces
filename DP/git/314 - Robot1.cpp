#include<bits/stdc++.h>

using namespace std;

struct node{

    int a,b,dir,time;
    node(int x,int y,int d,int t ){

        a = x;
        b = y;
        dir = d;
        time = t;
    }


};

bool obstacle[50][50];
bool visited[51][51][4];

int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
int M,N;

bool possible(int x,int y){

    if(x<=0 || y<=0 || x>=(M) || y>=(N) )return false;
    if(obstacle[x-1][y-1])return false;
    if(obstacle[x-1][y])return false;
    if(obstacle[x][y-1])return false;
    if(obstacle[x][y])return false;

    return true;

}

int bfs(int startx,int starty,int dir,int endx,int endy){

    queue<node>q;

    if(possible(startx,starty)){

        q.push(node(startx,starty,dir,0));
        visited[startx][starty][dir] = true;
    }


    while(!q.empty()){

        node temp = q.front();
        q.pop();

        if(temp.a==endx && temp.b==endy)return temp.time;

        if(!visited[temp.a][temp.b][(temp.dir+1)%4]){

            visited[temp.a][temp.b][(temp.dir+1)%4] = true;
            q.push(node(temp.a,temp.b,(temp.dir+1)%4,temp.time+1));

        }

        if(!visited[temp.a][temp.b][(temp.dir+3)%4]){

            visited[temp.a][temp.b][(temp.dir+3)%4] = true;
            q.push(node(temp.a,temp.b,(temp.dir+3)%4,temp.time+1));

        }

        for(int i=1;i<4;i++){

            if(possible(temp.a+di[temp.dir]*i,temp.b+dj[temp.dir]*i)){

                if(!visited[temp.a+di[temp.dir]*i][temp.b+dj[temp.dir]*i][temp.dir]){

                    visited[temp.a+di[temp.dir]*i][temp.b+dj[temp.dir]*i][temp.dir]=true;
                    q.push(node(temp.a+di[temp.dir]*i,temp.b+dj[temp.dir]*i,temp.dir,temp.time+1));

                }

            }else break;
        }

    }

    return -1;


}


int main(){

    //freopen("dada.txt","w",stdout);

    while(cin>>M>>N){

        if(M==0 && N==0)break;

        int ax;
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++){
                scanf("%d",&ax);
                obstacle[i][j]=ax;
            }

        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++) fill(visited[i][j],visited[i][j]+4,false);


        int startx,starty,dir,endx,endy;
        cin>>startx>>starty>>endx>>endy;
        string way;
        cin>>way;

        if(way[0]=='n')dir=0;
        if(way[0]=='e')dir=1;
        if(way[0]=='s')dir=2;
        if(way[0]=='w') dir=3;

        cout<<bfs(startx,starty,dir,endx,endy)<<endl;
    }



}
