#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    double x,y,copies;
    cin>>x>>y;

    if(y==0){
         if(x>=0){cout<<"No"<<endl; return 0;}
    }
    if(y==1 && x>0){
        cout<<"No"<<endl; return 0;
    }
    y = y-1;

    while(1){

        if(x==y){cout<<"Yes"<<endl; break;}
        else if(x<y){cout<<"No"<<endl; break;}
        else y=y+2;

    }


return 0;
}
