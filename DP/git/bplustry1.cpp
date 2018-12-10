#include<bits/stdc++.h>


#define Max 100
#define I_Max 10000

using namespace std;

int numberOfPointer;


struct Block{

    int tNodes;
    Block *parent;
    Block *children[Max];
    int value[Max];

    Block(){

        tNodes = 0;
        parent =NULL;
        for(int i=0;i<Max;i++){
            children[i] = NULL;
            value[i] = I_Max;
        }
    }

};

Block *root = new Block();

void splitLeafNode(Block *curBlock){

    int x,i,j;

    if(numberOfPointer%2){

        x = (numberOfPointer+1)/2;

    }else{

        x = numberOfPointer/2;
    }


    curBlock[0].tNodes = x;
    Block *rightBlock = new Block();

    rightBlock[0].tNodes = numberOfPointer-x;

    for(i=x,j=0;i<numberOfPointer;j++,i++){ /// ! i<=numberOfPointer (because of leaf)

        ///only value exchange
        rightBlock[0].value[j] = curBlock[0].value[i];
        curBlock[0].value[i] = I_Max;

    }

    int var = rightBlock[0].value[0];

    if(curBlock[0].parent==NULL){

        Block *parentBlock = new Block();

        parentBlock[0].tNodes = 1;
        parentBlock[0].value[0] = var;
        parentBlock[0].children[0] = curBlock;
        parentBlock[0].children[1] = rightBlock;
        curBlock[0].parent = rightBlock[0].parent = parentBlock;

        root = parentBlock;
        return;

    }else{

        curBlock = curBlock[0].parent;

        Block *newChild = new Block();

        newChild = rightBlock;

        for(i=0;i<=curBlock[0].tNodes;i++){

            if(curBlock[0].value[i]>var){

                swap(curBlock[0].value[i],var);
            }
        }

        curBlock[0].tNodes++;

        cout<<newChild[0].value[0];
        cout<<curBlock[0].children[0].value[0]<<endl;
        for(i=0;i<curBlock[0].tNodes;i++){
            if(newChild[0].value[0]<curBlock[0].children[i].value[0]){
                swap(newChild,curBlock[0].children[i]);
            }
        }

        for(i=0;curBlock[0].children[i]!=NULL ;i++){

            curBlock[0].children[i].parent = curBlock[0];
        }

    }

}

void splitNonLeafNode(Block *curBlock){

    int x,i,j;

    x = numberOfPointer/2;

    curBlock[0].tNodes = x;
    Block *rightBlock = new Block();

    rightBlock[0].tNodes = numberOfPointer-x-1;

    for(int i=x,j=0;i<=numberOfPointer;j++){

        rightBlock[0].value[j] = curBlock[0].value[i];
        rightBlock[0].children[j] = curBlock[0].children[i];
        curBlock[0].value[i] = I_Max;
        if(i!=x)curBlock[0].childBlock[i]=NULL;

    }

    int var = rightBlock[0].value[0];

    memcpy(&rightBlock[0].value,&rightBlock[0].value[1],sizeof(int)*(rightBlock[0].tNodes+1))
    memcpy(&rightBlock[0].childBlock,&rightBlock[0].childBlock[1],sizeof(rightBlock[0])*(rightBlock[0].tNodes+1))

    for(i=0; i<curBlock[0].tNodes;i++){

        curBlock[0].children[i].parent = curBlock;
    }

    for(i=0;i<rightBlock[0].tNodes;i++){
        rightBlock[0].children[i].parent = rightBlock;
    }

    if(curBlock[0].parent==NULL){

        Block *parentBlock = new Block();
        parentBlock[0].parent = NULL;

        parentBlock[0].children[0] = curBlock[0];
        parentBlock[0].children[1] = rightBlock[0];

        parentBlock[0].tNodes =1;
        parentBlock[0].value[0] = var;

        curBlock[0].parent = rightBlock[0].parent = parentBlock;
        root = parentBlock;
        return ;

    }else{

        curBlock = curBlock[0].parent;

        Block *newChild = new Block();
        newChild = rightBlock;

        for(i=0;i<=curBlock[0].tNodes;i++){
            if(var<curBlock[0].value[i]){

                swap(curBlock[0].value[i],var);
            }
        }

        curBlock[0].tNodes++;

        for(i=0;i<=curBlock[0].tNodes;i++){
            if(newChild[0].value[0]<curBlock[0].children.value[0]){

                swap(curBlock[0].children,newChild);
            }
        }

        curBlock[0].children[i] = newChild;

        for(i=0;curBlock[0].children[i]!=NULL;i++){
            curBlock[0].children[i].parent = curBlock;
        }
    }

}

void insert(Block *curBlock,int var){


    for(int i=0;i<;i++){

        if(var<curBlock[0].value[i] && curBlock[0].parent!=NULL){

            insert(curBlock[0].children[i],var);

            if(curBlock[0].tNodes==numberOfPointer){

                splitNonLeafNode(curBlock);

            }

        }else if(var<curBlock[0].value[i] && curBlock[0].parent==NULL){

            swap(curBlock[0].value[i],var);
            if(i==curBlock[0].tNodes){

                curBlock[0].tNodes++;
            }

        }

    }

    if(curBlock[0].tNodes==numberOfPointer){
        splitLeafNode(curBlock);
    }

}

void printV(vector<*Block>block){

    for(int i=0;i<block.size();i++){

        int j;
        print("[|");

        Block *cur = block[i];

        for(j=0;j<cur.tNodes;j++){

            cout<<cur.value[j]<<"|";
            if(cur.children[j]!=NULL){
                block.push_back(cur.children[j]);
            }

        }
        if(cur.children[j]!=NULL && cur.value[j]==I_Max){
            block.push_back(cur.children[j]);
        }

        cout<<"|]"<<endl;
    }

}

int main(){

    vector<*Block>b;
    int m;
    cout<<"insert 1 "<<endl;
    cout<<"print 2 "<<endl;

    while(cin>>m){

        if(m==1){

            cout<<"enter the node value"<<endl;
            int var;
            cin>>var;
            insert(root,var);
        }else {

            b.clear();
            b.push_back(root);
            printV(b);

        }

    }

   return 0;
}
