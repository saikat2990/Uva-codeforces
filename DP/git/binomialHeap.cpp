#include<bits/stdc++.h>

using namespace std;

struct Node{

    int data,degree;
    Node *child,*parent,*sibling;

};

Node* newNode(int data){

    Node *temp = new Node;
    temp->data = data;
    temp->degree = 0;
    temp->child=temp->parent=temp->sibling=NULL;
    return temp;

}

Node* mergeNode(Node* l1,Node* l2){

    if(l1->degree>l2->degree){
        swap(l1,l2);
    }

    l2->sibling=l1->child;
    l2->parent = l1;
    l1->child = l2;
    l1->degree++;
    return l1;

}

list<Node*> unionList(list<Node*>l1,list<Node*>l2){

    list<Node* >newHeap;
    list<Node*>::iterator it1,it2;
    cout<<"in  unionList1"<<endl;
    it1=l1.begin();
    it2=l2.begin();

    while(it1!=l1.end() && it2!=l2.end()){

        if((*it1)->degree<(*it2)->degree){
            newHeap.push_back(*it1);
            it1++;
        }
        else{
            newHeap.push_back(*it2);
            it2++;
        }

    }

    while(it1!=l1.end()){
        newHeap.push_back(*it1);
        it1++;
    }
    while(it2!=l2.end()){
        newHeap.push_back(*it2);
        it2++;
    }
    cout<<"in  unionList2"<<endl;
    return newHeap;
}

list<Node* >adjust(list<Node* >heap){

    list<Node* >::iterator it1,it2,it3;
    it1=it2=it3=heap.begin();
    cout<<"in  adjust1"<<endl;
    if(heap.size()==2){

        it2++;
        it3=heap.end();
    }
    else{
        it2++;
        it3=it2;
        it3++;
    }

    while(it1!=heap.end()){

        if((*it1)->degree<(*it2)->degree){
            it1++;
            it2++;
            if(it3!=heap.end())it3++;
        }
        else if((*it1)->degree<(*it2)->degree && it3!=heap.end() &&
                (*it1)->degree<(*it3)->degree){


                it1++;
                it2++;
                it3++;
        }

        else if((*it1)->degree==(*it2)->degree){

            *it1 = mergeNode(*it1,*it2);
            it2 = heap.erase(it2);
           if(it3!=heap.end())it3++;
        }

    }
    cout<<"in  adjust"<<endl;
    return heap;

}

list<Node* > insertATreeInHeap(list<Node* >heap,int key){

    list<Node*> temp;
    Node* node =  newNode(key);

    temp.push_back(node);
    cout<<"in  insertATreeInHeap"<<endl;
    temp = unionList(heap,temp);

    return adjust(temp);


}

void printTree(Node *node){

    while(node){
        cout<<node->data<<": ";
        printTree(node->child);
        node = node->sibling;
    }
}

void printHeap(list<Node*> heap){

    list<Node*>::iterator it=heap.begin();
    cout<<"in printHeap"<<endl;
    while(it!=heap.end()){

        printTree(*it);
        it++;
    }
}

int main(){

    int ch,key;
    list<Node*> _heap;

    // Insert data in the heap
    _heap = insertATreeInHeap(_heap,10);
    _heap = insertATreeInHeap(_heap,20);
    _heap = insertATreeInHeap(_heap,40);
    _heap = insertATreeInHeap(_heap,50);
    _heap = insertATreeInHeap(_heap,60);

    cout << "Heap elements after insertion:\n";
    printHeap(_heap);
}
