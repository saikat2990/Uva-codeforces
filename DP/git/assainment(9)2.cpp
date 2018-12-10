#include<bits/stdc++.h>

using namespace std;

int main(){


    //ofstream ofile;
    //ofile.open("vai.txt");

    int cases;
    cin>>cases;
    while(cases--){

        int W,number;
        cin>>W>>number;
        int arr[W+1][number+1];
        vector<int>val[number+1];

        for(int i=1;i<=number;i++){
            int a;
            cin>>a;
            for(int j=0;j<a;j++){
                int b;
                cin>>b;
                val[i].push_back(b);
            }
        }

        for(int i=0;i<=W;i++)
            for(int j=0;j<=number;j++)
                arr[i][j]=-4;

        arr[0][0]=0;

        for(int i=1;i<=W;i++){
            arr[i][0]=0;
            for(int j=1;j<=number;j++){


                for(int k=0;k<val[j].size();k++){
                     int temp;
                    if((i-val[j][k]<0) || arr[i-val[j][k]][j-1]<0 )temp=-4;
                    else temp = arr[i-val[j][k]][j-1]+val[j][k];

                    arr[i][j] = max(arr[i][j],temp);
                }

            }

        }
        /*for(int i=0;i<=W;i++){
            for(int j=0;j<number;j++)
                cout<<arr[i][j]<<" ";
            cout<<endl;
        }*/

        if(arr[W][number]>=0)cout<<arr[W][number]<<endl;
        else cout<<"no solution"<<endl;

    }


}
