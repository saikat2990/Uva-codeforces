#include<bits/stdc++.h>

using namespace std;

int main(){

    int arr[27];
    for(int i=0;i<27;i++)arr[i]=0;
    int n,cn=0;;
    cin>>n;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        bool tag=false;
        for(int j=0;j<str.length();j++){
            //cout<<str[j]-'a'<<" ";
            if(arr[str[j]-'a']==0){

               if(tag==false)
                    cn++;

                arr[str[j]-'a']=1;
                tag=true;
            }
        }

    }

    cout<<cn<<endl;
}
