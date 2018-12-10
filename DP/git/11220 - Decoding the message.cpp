#include<bits/stdc++.h>

using namespace std;

string func(char ch){

    stringstream iss;
    iss<<ch;
    string st;
    iss>>st;
    //cout<<st<<" ";
    return st;
}

int main(){

    freopen("hel.txt","w",stdout);
    string str;
    int n;
    cin>>n;
    int h=n;
    //cout<<endl;
    getline(cin,str);
    getline(cin,str);
    int y=1;
    while(n){


        vector<string>vec;
        //getline(cin,str);
        cout<<"Case #"<<y<<":"<<endl;
        y++;
        while(getline(cin,str)){


            if(str==""){
                n--;
                if(y-1!=h)cout<<endl;
                //cout<<"hey bro "<<vec.size()<<endl;
                //for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";
                //vec.clear();
                break;
            }else{

                string word,ans="";
                int cn=0;
                stringstream iss(str);
                while(iss>>word){
                    //cout<<word<<endl;
                    if((cn+1)<=word.length()){
                        ans=ans+func(word[cn]);
                        //cout<<ans<<"  ans "<<endl;
                        cn++;
                    }
                }

                cout<<ans;
                cout<<endl;
               // vec.push_back(ans);
            }
        }

    }



return 0;
}
