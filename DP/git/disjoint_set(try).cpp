#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find(int x){

    if(parent[x]!=x){
        parent[x] = find(parent[x]);
    }
    else parent[x];

}

void setunion(int x,int y){

    int xroot = find(x);
    int yroot = find(y);

    if(xroot==yroot){
        return;
    }

    if(rank[xroot]>rank[yroot]){
        parent[yroot] = xroot;
    }else if(rank[yroot]>rank[xroot]){
        parent[xroot] = yroot;
    }else {

        parent[yroot] = xroot;
        rank[xroot] = rank[xroot]+1;

    }


}

int main(){

    int number ;
    cin>>number;
    int parent[number],rank[number];


}
