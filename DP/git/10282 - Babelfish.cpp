#include<bits/stdc++.h>

using namespace std;

int main(){

    //freopen("dada.txt","w",stdout);
    string strline,word1,word2;
    map<string,string>mss;
    while(1){

        getline(cin,strline);
        if(strline.length()==0)break;
        stringstream iss;
        iss<<strline;
        iss>>word1;
        iss>>word2;
        mss[word2] = word1;

    }

    while(1){

        string ck;
        getline(cin,strline);
        if(strline.length()==0)break;
        stringstream is;
        is<<strline;
        is>>ck;
        if(mss.count(ck)==0){
            cout<<"eh"<<endl;
        }else{
            cout<<mss[ck]<<endl;
        }
    }

}
