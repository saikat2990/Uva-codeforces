#include<bits/stdc++.h>

using namespace std;

struct node{

    int x,y;
    int px,py;

};

int main(){

    int a,b;
    while(cin>>a>>b){

        int row,num;
        if(a==0 && b==0)break;
        bool arr[a+1][b+1]= {false};
        int testCases;
        cin>>testCases;

        for(int i=0;i<testCases;i++){


            cin>>row>>num;

            for(int j=0;j<num;j++){

                int col;
                cin>>col;
                arr[row-1][col-1] = true;
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
                    q.push(nd);
                    cout<<ckx<<" "<<cky<<endl;
                    if(nd.x==dx && nd.y==dy)break;

                }

            }

            if(q.back().x==dx && q.back().y==dy)break;
        }

    }

return 0;
}

