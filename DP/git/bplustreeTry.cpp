#include<bits/stdc++.h>
using namespace std;

#define Max 50
#define T_MAX 99999;

struct Block{

    Block *parentBlock;
    int tNodes;
    int value[Max];
    Block *childrenBlock[Max];
    Block(){

        parentBlock = NULL;
        tNodes = 0;
        for(int i=0;i<Max;i++){

            childrenBlock[i] = NULL;
            value[i] = T_MAX;
        }
    }

};

int numberOfPointer;

void insert(Block *cuBlock){

    int x,i,j;
    if(numberOfPointer%2){

        x = (numberOfPointer+1)/2;

    }else {
         x = numberOfPointer/2;
    }

    Block *rightBlock;

    cuBlock.tNodes = x;
    right.tNodes = numberOfPointer-x;

    right.parent = cuBlock.parent;

    for(i=x, j=0;i<numberPointer;i++,j++ ){

        rightBlock[j] = cuBlock[i];
        cuBlock[i] = T_MAX;

    }

    int val = rightBlock[0];

    if(right.parent==NULL){

        Block *parentBlock = new Block();
        parentBlock.value[0] = val;
        parentBlock.children[0] = rightBlock;
        parentBlock.children[1] = cuBlock;
        parentBlock = NULL;
        cuBlock.parent = parentBlock;
        rightBlock.parent = parentBlock;

    }else{

        cuBlock = cuBlock.parent;
        Block *children = new Block();
        children = rightBlock;

        for( i=0;i<=cuBlock.tNodes;i++){
            if(val<cuBlock[i])
                swap(cuBlock[i],val);
        }
        cuBlock.tNodes++;

        for( i=0;i<cuBlock.tNodes;i++){
            if(children.value[0]<cuBlock.childrenBlock[i].value[0]){
                swap(cuBlock.childrenBlock[i],children);
            }
        }

        cuBlock.childrenBlock[i] = children;
        for(i=0;cuBlock.children[i]!=NULL;i++){

            cuBlock.children[i].parent = cuBlock;

        }

    }


}
