#include<bits/stdc++.h>

using namespace std;

string func(int str){

    stringstream iss;
    string ans;
    iss<<str;
    iss>>ans;
    return ans;

}

int main(){

    //freopen("test.txt","w",stdout);
    string str;
    while(getline(cin,str)){

        int tp=0;
        vector<char>vecInt;
        vector<int>vec;
        int u=0;

        for(int i=str.length()-1;i>=0;i--){

            if(str[i]>='0' && str[i]<='9' ){

                tp = tp*10+str[i]-48;

                if(u==1 && tp/10!=1){

                   //cout<<(char)tp;
                   vecInt.push_back((char)tp);
                   tp=0;
                   u=-1;

                }else if(u==2 && tp/100==1){

                   //cout<<(char)tp;
                   vecInt.push_back((char)tp);
                   tp=0;
                   u=-1;

                }
                  u++;

            }else{

                vec.push_back((int)str[i]);

            }

        }

        for(int i=0;i<vecInt.size();i++){
            cout<<vecInt[i];
        }

        for(int i=0;i<vec.size();i++){
            string vug = func(vec[i]);
            for(int j=vug.length()-1;j>=0;j--){
                cout<<vug[j];
            }
        }


        cout<<endl;
    }

return 0;
}
