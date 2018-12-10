#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;
    string str1,str2;
    cin>>str1>>str2;
    char ch='0';
    int in=-1,i=0;
    bool tag=false,uff=false;
    vector<int>vec;
    if(str1==str2){cout<<"0"; return 0;}

    for(i=0;i<10000;i++){

        for(int j=0;j<n;j++){

            if(str1[j]!=str2[j] && tag==false){
                ch=str2[j];
                //cout<<ch<<" ";
                tag=true;
                continue;
            }
            if(ch!='0'){
                if(ch==str1[j]){
                        in = j;
                        //cout<<in<<" ";
                        vec.push_back(in);
                        break;
                }else in =-1;
            }

        }

        if(in==-1){

            cout<<"-1";
            return 0;
        }

        ch = str1[in-1];
        str1[in-1] = str1[in];
        str1[in] = ch;
        ch='0';
        tag=false;
        //cout<<str1<<endl;
        if(str1==str2){
            uff=true;
            break;
        }
        in=-1;
    }
    if(uff==false){
        cout<<"-1"<<endl;

    }else{
        cout<<i+1<<endl;
        for(i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
    }


return 0;
}
