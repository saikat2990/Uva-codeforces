#include<bits/stdc++.h>

using namespace std;

#define Max 1000000

int pa[Max];

struct edge{

    int a,b;
    double w;

    edge(int x,int y,double wt){
        a=x;
        b=y;
        w=wt;
    }

    bool operator < (const edge & other) const{
        return w < other.w;
    }

};

int findPa(int x){

    cout<<x<<"   "<<pa[x]<<endl;
    if(x==pa[x])return x;
    else pa[x] = findPa(pa[x]);

}

vector<edge>vec;

bool issame(int x,int y){

    if(findPa(x)==findPa(y))return true;
    else return false;

}

void unions(int x,int y){

    int xroot = findPa(x);
    int yroot = findPa(y);

    cout<<"xroot  "<<xroot<<"yroot "<<yroot<<endl;

    if(xroot<=yroot){
        pa[yroot] = xroot;
    }else{

        pa[xroot] = yroot;
        cout<<"xroot "<<xroot<<"  "<<pa[xroot]<<" pa root "<<endl;
    }
    cout<<findPa(x)<<findPa(y)<<endl;
}

double kruskal(int v){

    double total=0.0;

    for(int i=0;i<=v;i++){
        pa[i]=i;
    }

    sort(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++){

        if(!issame(vec[i].a,vec[i].b)){
                cout<<findPa(vec[i].a)<<"    "<<findPa(vec[i].b)<<endl;
                cout<<endl<<vec[i].a<<"  "<<vec[i].b<<" "<<vec[i].w<<endl;
            total+=vec[i].w;

            unions(vec[i].a,vec[i].b);
        }

    }

    return total;
}

double dis[Max][2];

int main(){

    int test;
    cin>>test;

    while(test--){

        int ed;
        cin>>ed;

        for(int i=0;i<ed;i++){

            cin>>dis[i][0]>>dis[i][1];
        }

        for(int i=0;i<ed;i++){

            for(int j=i+1;j<ed;j++){

                double wt = sqrt(pow(dis[i][0]-dis[j][0],2)+pow(dis[i][1]-dis[j][1],2));
                cout<<j<<i<<wt<<endl;
                vec.push_back(edge(i,j,wt));
            }
        }
        cout<<kruskal(ed)<<endl;
        vec.clear();
    }


  return 0;
}
