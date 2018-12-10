#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int getSum(int BITree[],int index){

    int sum=0;
    index = index+1;
    while(index>0){

        sum+=BITree[index];
        index-=(index&(-index));
    }
    return sum;

}

void updateUtil(int BinaryIn[],int n,int index,int val){

    index = index+1;

    while(index<=n){

        BinaryIn[index]+=val;
        index+=index&(-index);
    }
}

int *construct(int arr[],int n){

    int *BinaryIn = new int[n+1];

    for(int i=0;i<=n;i++){
        BinaryIn[i]=0;
    }

    for(int i=0;i<n;i++)
        updateUtil(BinaryIn,n,i,arr[i]);

    return BinaryIn;
}

int main(){

    int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};

    int n = sizeof(freq)/sizeof(freq[0]);

    int *BITree = construct(freq,n);

    cout<<getSum(BITree,5)<<endl;

return 0;
}
