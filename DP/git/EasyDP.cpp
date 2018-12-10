#include<bits/stdc++.h>

using namespace std;

int main(){

    int cases;
    cin>>cases;
    int t=0;
    while(cases--){
        t++;
        int  input;
        cin>>input;
        int temp=1000000007;
        int arr[3][input+1];
        int  val[2]={1,3};

        for(int i=0;i<2;i++){
            for(int j=0;j<=input;j++){
                if(i==0)arr[i][j]=1;
                else if(j>=val[i]){
                    (arr[i][j] = (((arr[i][j-val[i]])%temp)+
                      (arr[i][j-1])%temp)%temp);
                    //cout<<arr[i][j]<<" ";
                }
                else if(j<val[i])arr[i][j] = arr[i-1][j];
            }
        }
        for(int i=0;i<=1;i++){
           // for(int j=0;j<=input;j++)cout<<arr[i][j]<<" ";
            //cout<<endl;
        }
        cout<<"Case "<<t<<": "<<(arr[1][input])<<endl;
    }

return 0;
}
