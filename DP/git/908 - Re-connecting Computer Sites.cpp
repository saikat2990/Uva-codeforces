#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> edges;
typedef pair<int, edges> node;
vector <node> nds;

bool operator < (const node nd1, const node nd2){

    if(nd1.first < nd2.first)return true;
    return false;

}


struct disjoint{

    int sets;
    int *paddress;
    int *numchild;

    void init(int v){

        paddress = new int [v+1];
        numchild = new int [v+1];
        sets = v;
        for(int i=0;i<=v;i++){

            paddress[i] = i;
            numchild[i] = 1;

        }

    }

    int findroot(int x){

        if(x==paddress[x])return x;

        else paddress[x] = findroot(paddress[x]);
    }

    bool issame(int x ,int y){

        if(findroot(x)==findroot(y)){
            return true;
        }
        else return false;
    }

    void unions(int x,int y){

        int xroot = findroot(x);
        int yroot = findroot(y);

        if(xroot<=yroot){

            paddress[yroot] = xroot;
            numchild[xroot]+=numchild[yroot];

        }else{

             paddress[xroot] = yroot;
            numchild[yroot]+=numchild[xroot];

        }
        /*if(!issame(xroot, yroot)){
            numchild[yroot] += numchild[xroot];
            paddress[xroot] = yroot;
            //sets--;
        }*/


    }

};

int kruskal(int v){

    disjoint tp;

    tp.init(v);
    sort(nds.begin(),nds.end());

    int origin,des,total=0,wt;

    for(int i=0;i<nds.size();i++){

        wt = nds[i].first;
        origin = nds[i].second.first;
        des = nds[i].second.second;

        if(!tp.issame(origin,des)){

            total+=wt;
            tp.unions(origin,des);
        }

    }

    return total;


}

int main(){

    //freopen("dada.txt","w",stdout);
    int V,K,M,u,v,wt=0,T=0,total=0;
    int y=0;

    while(scanf("%d",&V) != EOF){

        if(y!=0)printf("\n");

        y++;
        for(int i=0;i<V-1;i++){
            scanf("%d %d %d",&u,&v,&wt);
            total+=wt;
        }

        printf("%d\n",total);
        total=0;

        scanf("%d",&K);
        for(int i=0;i<K;i++){

            scanf("%d %d %d",&u,&v,&wt);
            nds.push_back(node(wt,edges(u,v)));
        }

        scanf("%d",&M);
        for(int i=0;i<M;i++){

            scanf("%d %d %d",&u,&v,&wt);
            nds.push_back(node(wt,edges(u,v)));
        }

        printf("%d\n",kruskal(V));
        nds.clear();

    }

    exit(1);

    return 0;
}
