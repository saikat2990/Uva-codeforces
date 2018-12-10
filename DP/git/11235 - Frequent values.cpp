#include<bits/stdc++.h>

using namespace std;

int main(){

    int test;
    cin>>test;
    while(test--){

        string str;
        cin>>str;
        int len = str.length();
        int f=0;
        vector<int>ans;
        int an=0;
        bool tag =false;

        for(int i=0;i<len;i++){

            if(str[i]=='O'){

                f++;
                ans.push_back(f);
                //ans+=f;

            }else{
                f=0;
            }

        }
        for(int i=0;i<ans.size();i++)an+=ans[i];
        cout<<an<<endl;
    }



return 0;
}
