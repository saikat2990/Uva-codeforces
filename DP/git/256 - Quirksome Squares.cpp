#include<bits/stdc++.h>

using namespace std;

void func2(){

    int str2[2]={0,0};
    vector<int>ans[100];


    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if((i+j)*(i+j)==i*10+j){
                str2[0] = i;
                str2[1] = j;
                //ans[h].push_back(str2[0]);
                //ans[h].push_back(str2[1]);
                cout<<str2[0]<<str2[1]<<endl;
            }
        }
    }



}
void func4(){

    int str4[4]={0,0,0,0};

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if((i+j)*(i+j)==i*100+j){
                str4[0] = i/10;
                str4[1] = i%10;
                str4[2] = j/10;
                str4[3] = j%10;
                cout<<str4[0]<<str4[1]<<str4[2]<<str4[3]<<endl;
            }
        }
    }


}

void func6(){


    int str6[6]={0,0,0,0,0,0};

    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if((i+j)*(i+j)==i*1000+j){
                str6[0] = i/100;
                str6[1] = (i%100)/10;
                str6[2] = i%10;
                str6[3] = j/100;
                str6[4] = (j%100)/10;
                str6[5] = j%10;
                cout<<str6[0]<<str6[1]<<str6[2]<<str6[3]<<str6[4]<<str6[5]<<endl;
            }
        }
    }

}

void func8(){

    int str8[8]={0,0,0,0,0,0,0,0};

    for(int i=0;i<10000;i++){
        for(int j=0;j<10000;j++){
            if((i+j)*(i+j)==i*10000+j){
                str8[0] = i/1000;
                str8[1] = (i%1000)/100;
                str8[2] = (i%100)/10;
                str8[3] = (i%10);
                str8[4] = j/1000;
                str8[5] = (j%1000)/100;
                str8[6] = (j%100)/10;
                str8[7] = (j%10);
                cout<<str8[0]<<str8[1]<<str8[2]<<str8[3]<<str8[4]<<str8[5]<<str8[6]<<str8[7]<<endl;
            }
        }
    }


}

int main(){


    int n;
    while(cin>>n){
    if(n==2){
        func2();
    }
    else if(n==4){
        func4();
    }
    else if(n==6){
        func6();
    }
    else if(n==8){
        func8();
    }
    }
return 0;
}
