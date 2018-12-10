#include<bits/stdc++.h>

using namespace std;

int main(){

    //freopen("test.txt","w",stdout);

    string str;
    while(getline(cin,str)){

        int i=0;

        for( ;i<str.length();i++){

            if(str[i]!=' ')break;
            cout<<" ";
        }

        string word;
        stringstream iss;
        iss<<str;

        while(iss>>word){

            i+=word.length();

            for(int j=word.length()-1;j>=0;j--){
                cout<<word[j];
            }

            for( ;i<str.length();i++){
                if(str[i]!=' ')break;
                cout<<" ";
            }

        }
        cout<<endl;
    }


}
