#include<bits/stdc++.h>

using namespace std;

int knapsack(int wt[], int val[],int W,int n ){

    if(W==0 || n==0)return 0;

    if(wt[n-1]>W)return knapsack(wt,val,W,n-1);

    else return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));

}

int main(){

    int s,n;
    cin>>s>>n;
    int wt[n],val[n];
    for(int i=0;i<n;i++){

        int a,b;
        cin>>a>>b;
        wt[i]=a;
        val[i]=b;
    }


    cout<<knapsack(wt,val,s,n)<<endl;

return 0;
}
