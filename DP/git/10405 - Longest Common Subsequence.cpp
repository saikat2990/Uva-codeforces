#include<bits/stdc++.h>
using namespace std;

void longestCommonSubsequence(string str1,string str2){

    int n1 = str1.size();
    int n2 = str2.size();

    //cout<<n1<<n2;
    int arr[n1+1][n2+1];

    for(int i=0;i<=n1;i++){

        for(int j=0;j<=n2;j++){

            if(i==0)arr[i][j]=0;
            else if(j==0)arr[i][j]=0;
            else{

                if(str1[i-1]==str2[j-1]){
                    arr[i][j] = arr[i-1][j-1]+1;
                }
                else {
                    arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
                }

            }
        }
    }
    /*for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }*/

        cout<< arr[n1][n2]<<endl;

}

int main(){

    string str1,str2;
    while(getline(cin,str1)){

        getline(cin,str2);
        //cin>>str1>>str2;
        longestCommonSubsequence(str1,str2);

    }


}
