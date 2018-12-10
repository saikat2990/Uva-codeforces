#include<bits/stdc++.h>

using namespace std;

int main(){

    freopen("test.txt","w",stdout);
    string str;
    map<char ,int>mp;

    mp['B']=mp['P']=mp['F']=mp['V']=1;
    mp['C']=mp['S']=mp['K']=mp['G']=mp['J']=mp['Q']=mp['X']=mp['Z']=2;
    mp['D']=mp['T']=3;
    mp['L']=4;
    mp['M']=mp['N']=5;
    mp['R']=6;

    cout<<"         "<<"NAME"<<"                     "<<"SOUNDEX CODE"<<endl;

    while(cin>>str){

        bool tag[26]={false};
        vector<int>vec;
        cout<<"         "<<str;

        /*if(mp.count(str[0])!=0){
            tag[mp[str[0]]] = true;
        }*/
        int i;
        /*if( mp.count(str[0]) !=0 && mp.count(str[1])!=0 ){

            if(mp[str[0]] == mp[str[1]]){
                tag[mp[str[1]]] = false;
                i=2;
            }
            else i=1;
        }*/

        for(i=1;i<str.length();i++){

            if(mp.count(str[i-1])!=0 && mp.count(str[i])!=0 ){

                if(mp[str[i]] != mp[str[i-1]]){
                    vec.push_back(mp[str[i]]);
                    //tag[mp[str[i]]] = true;

                }

            }
        }

        for(int j=str.length()+10;j<35;j++)cout<<" ";

        if(vec.size()<3){
            for(int j=vec.size();j<4;j++)vec.push_back(0);
        }

        cout<<str[0]<<vec[0]<<vec[1]<<vec[2]<<endl;


    }
        for(int j=1;j<20;j++){
            cout<<" ";
        }
        cout<<"END OF OUTPUT"<<endl;

return 0;
}
