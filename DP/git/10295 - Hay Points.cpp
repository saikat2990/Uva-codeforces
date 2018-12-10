#include<bits/stdc++.h>

using namespace std;

int main(){

    unsigned long int sum=0;

    int store,line;
    map<string,int>msi;
    cin>>store>>line;
    for(int i=0;i<store;i++){

        string st;
        int val;
        cin>>st;
        cin>>val;
        msi[st]=val;

    }

    for(int i=0;i<line;i++){

        sum=0;
        string wt;
        while(cin>>wt&&wt!="."){
            sum+=msi[wt];
        }
        cout<<sum<<endl;

    }

}
