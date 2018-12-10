#include<bits/stdc++.h>

using namespace std;

int  knapsack(int wt[],int val[],int W,int n){
     int arr[n+2][W+2];

    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0)arr[i][w]=0;
            else if(w>=wt[i-1]){
                arr[i][w]=max(val[i-1]+arr[i-1][w-wt[i-1]],arr[i-1][w]);
            }
            else {
                arr[i][w]=arr[i-1][w];
            }
        }
    }

    return arr[n][W];

}

int main(){

    int cases;
    cin>>cases;
    while(cases--){

        int numberOfInputs;
        cin>>numberOfInputs;
        int wt[numberOfInputs],val[numberOfInputs];

        for(int i=0;i<numberOfInputs;i++){

            cin>>val[i]>>wt[i];
        }

        int man;
        cin>>man;
        int sum=0;
        for(int i=0;i<man;i++){
                int W;
                cin>>W;
            sum+=knapsack( wt,val,W,numberOfInputs) ;
        }
        cout<<sum<<endl;
    }

  return 0;
}
