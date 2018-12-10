#include<bits/stdc++.h>

using namespace std;

struct node{

    string name;
    int cd[11];
    int low[11];
    int save[11];
    int c0;
    int dimen;

};

int main(){

    int total,chk;
    cin>>total>>chk;

    map<string,node>mp;

    for(int j=0;j<total;j++){

        string str;
        node temp;
        cin>>str;
        temp.name = str;
        int base,elementSize,dimention;
        cin>>base>>elementSize>>dimention;
        temp.c0 = base;
        temp.dimen = dimention;

        for(int i=0;i<dimention;i++){

            int m;
            cin>>temp.low[i]>>m;
            temp.save[i] = m - temp.low[i]+1;

        }

        temp.cd[dimention-1] = elementSize;
        int pos = dimention-2;

        for(;pos>=0;pos--){
            temp.cd[pos] = temp.cd[pos+1]*temp.save[pos+1];
        }

        for(int i=0;i<dimention;i++){
            temp.c0-=(temp.cd[i]*temp.low[i]);
        }

        mp[str] = temp;

    }

    for(int i=0;i<chk;i++){

        string str;
        cin>>str;
        cout<<str<<"[";
        node nd = mp[str];

        int f = nd.dimen;
        int b = nd.c0;

        for(int j=0;j<f;j++){
            int dj;
            cin>>dj;
            b = b+dj*nd.cd[j];
            cout<<dj;
            if(j!=(f-1))cout<<", ";
        }

        cout<<"] = "<<b<<endl;
    }

return 0;
}
