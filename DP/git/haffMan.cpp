#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data;
    Node *left,*right;
    Node *parent;

};

struct compare{

    bool operator()(const Node* l,const Node* r){
        return l[0].data>r[0].data;
    }
};

priority_queue< Node*,vector<Node*>,compare >pq;


Node* createNode(int data){

    Node *temp = new Node[1];
    temp[0].data = data;
    temp[0].left = NULL;
    temp[0].right = NULL;
    temp[0].parent = NULL;
    return temp;

}

void printPath(Node *node,string str){

    //string str="";

    if(node[0].left==NULL && node[0].right==NULL){
            cout<<str<<"-->"<<node[0].data<<endl;
            return;
    }

    if(node[0].left!=NULL){
        str+="0";
        printPath(node[0].left,str);
        str[str.length()-1]='\0';
    }

    if(node[0].right!=NULL){
        str+="1";
        printPath(node[0].right,str);
        str[str.length()-1]='\0';
    }

  return;
}


int main(){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){

        int a;
        cin>>a;
        Node *newNode = new Node[1];
        newNode = createNode(a);
        pq.push(newNode);

    }
   /* while(!pq.empty()){
        Node *node1 = new Node[1];
        node1 = pq.top();
        pq.pop();
        cout<<node1[0].data<<endl;

    }*/

    while(pq.size()!=1){

        Node *node1 = new Node[1];
        node1 = pq.top();
        pq.pop();

        Node *node2 = new Node[1];
        node2 = pq.top();
        pq.pop();

        int sum  = node1[0].data+node2[0].data;
        Node *newNode = new Node[1];
        newNode = createNode(sum);

        newNode[0].left = node1;
        newNode[0].right = node2;

        node1[0].parent = newNode;
        node2[0].parent = newNode;

        pq.push(newNode);

    }

    Node *root = new Node[1];
    root  = pq.top();

    string str="";
    printPath(root,str);
    cout<<root[0].data<<endl;

return 0;
}
