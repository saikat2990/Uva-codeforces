#include<bits/stdc++.h>

using namespace std;

struct node{

    int x,y;
    int px,py;

};

bool arr[1001][1001]= {false};
node store[1001][1001];


int main(){

    int a,b;
    while(cin>>a>>b){

        memset(arr, 0, sizeof(arr));

        int row,num;
        if(a==0 && b==0)break;


        int testCases;
        cin>>testCases;

        for(int i=0;i<testCases;i++){


            cin>>row>>num;

            for(int j=0;j<num;j++){

                int col;
                cin>>col;
                arr[row][col] = true;
                node tp;
                tp.px=-2;
                tp.py = -2;
                tp.x = row;
                tp.y = col;
                store[row][col] =tp;
            }

        }
        int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        int ix[4]={1,-1,0,0};
        int iy[4]={0,0,1,-1};

        node tp;
        tp.x = sx;
        tp.y = sy;
        tp.px = -1;
        tp.py = -1;

        queue<node>q;
        q.push(tp);
        store[sx][sy] = tp;
        arr[sx][sy] = true;

        while(!q.empty()){

            node temp = q.front();
            q.pop();


            for(int i=0;i<4;i++){

                int ckx = temp.x;
                int cky = temp.y;

                ckx+=ix[i];
                cky+=iy[i];

                if(ckx>=0 && ckx<a && cky>=0 && cky<b && arr[ckx][cky]==false ){

                    node nd;
                    nd.x = ckx;
                    nd.y = cky;
                    nd.px = temp.x;
                    nd.py = temp.y;
                    store[ckx][cky] = nd;
                    q.push(nd);
                    arr[ckx][cky] = true;
                    //cout<<nd.x<<" "<<nd.y<<" "<<nd.px<<" "<<nd.py<<endl;
                    if(nd.x==dx && nd.y==dy)break;

                }

            }

            if(q.back().x==dx && q.back().y==dy)break;
        }

        tp = q.back();
        int chx = tp.x;
        int chy = tp.y;
        int cn=0;



        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
               // cout<<store[i][j].x<<","<<store[i][j].y<<"-->"<<store[i][j].px<<","<<store[i][j].py<<"   ";
            }
            //cout<<endl;
        }

        while(1){

            if(chx==sx && chy==sy)break;
            cn++;
            //cout<<chx<<" "<<chy<<endl;
            int in1 = chx;
            int in2 = chy;
            chx = store[in1][in2].px;
            chy = store[in1][in2].py;
        }

        cout<<cn<<endl;
    }

return 0;
}

