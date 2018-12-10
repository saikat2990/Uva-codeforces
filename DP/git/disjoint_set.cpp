#include<iostream>
#include<algorithm>
#include<map>
#include<utility>

using namespace std;

struct Node{

    int data;
    int rank;
    Node parent;

};

map<int,Node>mp;

Node makeNode(int value){

    Node node = new Node();
    node[0].data = value;
    node[0].rank = 0;
    node[0].parent = node;
    return node;

}

void unionbro(int a,int b){

    Node node1 = mp.find(a);
    Node node2 = mp.find(b);

    Node parent1 = findNode(node1);
    Node parent2 = findNode(node2);

    if(parent1[0].data==parent2[0].data)return;

    if(node1[0].rank==node2[0].rank){

        node1[0].rank = node1[0].rank+1;
        node2[0].parent = node1;

    }else if(node1[0].rank>node2[0].rank){

         node2[0].parent = node1;

    }else node1[0].parent = node2;

}

//path compression

Node findNode(Node node){

    if(node[0].parent == node)return node;

    node[0].parent = findNode(node[0].parent);

    return node[0].parent;
}


int main(){


return 0;
}
