#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    int h;
    cin>>h;
    string str;
    cin>>str;
    int n=str.length();
    int u=0,r=0,coint=0;

    bool tagu=false,tagr=false;

    if(str[0]=='U'){
        u++;
        tagu=true;
    }
    else{
        r++;
        tagr=true;
        //cout<<"hello"<<endl;
    }

    for(int i=1;i<n;i++){
            //cout<<str[i]<<endl;

            if(tagu==true && str[i]=='U')u++;
            else if(tagu==true && str[i]=='R') {
                u--;
                if(u<0){
                    tagr=true;
                    tagu=false;
                    r=1;
                    u=0;
                    coint++;
                    continue;
                }
            }


            else if(tagr==true && str[i]=='R')r++;
            else if(tagr==true && str[i]=='U'){
                r--;
                //cout<<r<<endl;
                if(r<0){
                    tagu=true;
                    tagr=false;
                    u=1;
                    r=0;
                    coint++;
                }
            }



    }
    cout<<coint<<endl;
}

