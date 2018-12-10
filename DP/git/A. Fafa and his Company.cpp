#include<iostream>
#include<cmath>

using namespace std;

bool ch(int n){

    int st = sqrt(n);

    for(int i=1;i<=st;i++){
        if(n%i==0)return true;
    }
    return false;
}


int main(){

    int n;
    cin>>n;

        int c=0;
        for(int i=1;i<=n/2;i++){
            if(n%i==0)c++;
        }
        cout<<c;


    return 0;
}
