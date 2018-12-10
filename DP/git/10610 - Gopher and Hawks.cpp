#include<bits/stdc++.h>

using namespace std;

int main(){

    while(1){

        int value,m;
        cin>>value>>m;
        if(value==0 && m==0)break;
        float sourceX,sourceY,desX,desY,tempX,tempY;
        cin>>sourceX>>sourceY>>desX>>desY;
        float dis = float(value*m*60);
        cout<<dis<<endl;
        string str;
        getline(cin,str);

        int cn=0;
        bool tag=false;
        while(getline(cin,str)){

            if(str.length()==0){cout<<"shes"<<endl; break;}
            stringstream iss(str);
            float x,y;
            iss>>x;
            iss>>y;

            if(sqrt(pow((sourceX-desX),2)+pow((sourceY-desY),2))<dis){
                cout<<cn<<endl;
                break;
            }

            else if(sqrt(pow((sourceX-x),2)+pow((sourceY-y),2))<dis){
                cout<<cn<<endl;
                cn++;
            }else {
                tag = true;
                cout<<"NO"<<endl;
                break;
            }
            sourceX = x;
            sourceY = y;


        }
        if(tag==false)cout<<cn<<endl;

    }





return 0;
}
