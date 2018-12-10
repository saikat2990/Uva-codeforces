#include<bits/stdc++.h>

using namespace std;

int main(){

    int a,b,x;
    cin>>a>>b>>x;
    vector<int>ans;
    ans.push_back(0);
    ans.push_back(1);
    x--;
    a--;
    b--;
    bool tag1,tag2;
    tag1=false;tag2=false;

    while(x--){

        if(tag1==false){
            ans.push_back(0);
            a--;
            tag1=true;
            tag2=false;
        }
        else{
            ans.push_back(1);
            b--;
            tag2=true;
            tag1=false;
        }

    }
    int temp = a;
    vector<int>::iterator it;
    if(a>0){

        it = ans.begin();
        ans.insert(it,a,0);
    }
    if(b>0){
        it = ans.begin();
        ans.insert(it+temp+1,b,1);
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }

return 0;
}
