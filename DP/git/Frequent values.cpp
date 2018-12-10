 #include<bits/stdc++.h>

 using namespace std;

 int makeTree(int arr[],int *st,int n,int ss,int se,int index){

    if(ss==se){
        st[se] = arr[ss];
        return arr[se];
    }

    int mid = (ss+se)/2;
    st[index] = min(makeTree(arr,st,n,ss,mid,2*index+1),
                    makeTree(arr,st,n,mid+1,se,2*index+2));
    return st[index];

 }

 int qr(int *st,int ss,int se,int ws,int we,int index){

    if(ss>we || se<ws){
        return 9999;
    }
    if(ss>=ws && se<=we){
        return st[index];
    }

    int mid = (ss+se)/2;
    st[index] = min(qr(st,ss,mid,ws,we,2*index+1),qr(st,mid+1,se,ws,we,2*index+2));
    return st[index];

 }

int main(){

    int arr[]={2,3,4,5,6,7,8};

    int n = sizeof(arr)/sizeof(arr[0]);
    n = (int)(ceil(log2(n)));
    n = 2*(pow(2,n))-1;

    int *st  = new int [n];

    cout<<makeTree(arr,st,n,0,6,0)<<endl;
    cout<<qr(st,0,6,2,5,0);

return 0;
}
