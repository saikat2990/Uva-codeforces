#include<bits/stdc++.h>

using namespace std;

int main(){

    string str;
    while(getline(cin,str)){

        list<char>vec;
        list<char>:: iterator it;

        it = vec.begin();

        for(int i=0;i<str.length();i++){

                if(str[i]=='['){
                    it = vec.begin();
                }

                else if(str[i]==']'){
                    it = vec.end();
                    //cout<<*it<<endl;
                }

                else{

                    vec.insert(it,str[i]);
                }


        }

        for(it=vec.begin();it!=vec.end();it++){
            cout<<*it;
        }
        cout<<endl;

    }

}
