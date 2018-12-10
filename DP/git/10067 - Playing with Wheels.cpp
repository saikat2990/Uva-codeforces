#include<bits/stdc++.h>

using namespace std;

vector< vector<int> >vii;
bool arr[10][10][10][10];
int n;

int di[]={-1,1,0,0,0,0,0,0};
int dj[]={0,0,-1,1,0,0,0,0};
int dk[]={0,0,0,0,-1,1,0,0};
int dl[]={0,0,0,0,0,0,-1,1};


struct node{

    int a,b,c,d,cost;
    node(int x,int y,int z,int m,int wt){

        a=x;
        b=y;
        c=z;
        d=m;
        cost=wt;

    }

};

bool check(int a,int b,int c,int d){

    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

    for(int i=0;i<n;i++){
        if(vii[i][0] == a && vii[i][1] == b && vii[i][2] == c && vii[i][3] == d){

            return true;
        }
    }
    return false;

}

int main(){

    //freopen("dada.txt","w",stdout);

    int test;
    cin>>test;

    while(test--){

        int s1,s2,s3,s4;
        int f1,f2,f3,f4;
        memset(arr,false,sizeof(arr));

        cin>>s1>>s2>>s3>>s4>>f1>>f2>>f3>>f4;
        cin>>n;

        vii.clear();

        for(int i=0;i<n;i++){

            vector<int>vi;

            for(int j=0;j<4;j++){
                int val;
                cin>>val;
                vi.push_back(val);
            }

            vii.push_back(vi);
        }

        if(s1==f1 && s2==f2 && s3==f3 && s4==f4){
                cout<<"0"<<endl;
                continue;
        }
        if(check(f1,f2,f3,f4)){
                cout<<"-1"<<endl;
                continue;

        }


        queue<node>q;

        q.push(node(s1,s2,s3,s4,0));

        while(!q.empty()){

            node temp = q.front();
            q.pop();

           /* if(temp.a==f1 &&temp.b==f2 &&temp.c==f3 &&temp.d==f4){
                    cout<<temp.cost<<endl;
                break;
            }*/
            int xx,yy,zz,kk;

            for(int i=0;i<8;i++){

                xx = temp.a+di[i];
                yy = temp.b+dj[i];
                zz = temp.c+dk[i];
                kk = temp.d+dl[i];

                if(!check(xx,yy,zz,kk) && arr[xx][yy][zz][kk]==false){
                    //&& xx>=0 && xx<=9 && yy>=0 && yy<=9 && zz>=0 && zz<=9 && kk>=0 && kk<=9){

                    //cout<<xx<<" "<<yy<<" "<<zz<<" "<<kk<<"    cost "<<temp.cost+1<<endl;
                    if(xx<0)xx=9;
                    if(xx>9)xx=0;
                    if(yy<0)yy=9;
                    if(yy>9)yy=0;
                    if(zz<0)zz=9;
                    if(zz>9)zz=0;
                    if(kk<0)kk=9;
                    if(kk>9)kk=0;

                    q.push(node(xx,yy,zz,kk,temp.cost+1));
                    arr[xx][yy][zz][kk] = true;
                    if(xx==f1 && yy==f2 && f3==zz && f4==kk){
                        cout<<temp.cost+1;
                        goto hell;
                    }
                }

            }
            //cout<<endl;

        }
        hell:
        cout<<endl;
    }


return 0;
}
