#include<bits/stdc++.h>

using namespace std;

struct st{
    int index;
    vector<int>vec;

};

int main(){

    //freopen("motherfuck.txt","w",stdout);
    int n;
    int k=1;
    while(cin>>n){

        map<int,st>mp;
        map<int,int>m;
        if(n==0)break;
        while(n--){

            int a,b;
            cin>>a>>b;

            if(!m[a]){
                st temp;
                temp.vec.push_back(b);
                temp.index = a;
                mp[a] = temp;
                m[a] = 1;
            }else{
                mp[a].vec.push_back(b);
            }

            if(!m[b]){
                st temp;
                temp.vec.push_back(a);
                temp.index = b;
                mp[b] = temp;
                m[b]=1;
            }else{
                mp[b].vec.push_back(a);
            }

        }
        map<int,st>:: iterator it;

        for(it = mp.begin();it!=mp.end();it++){
            st  t = it->second;
            //cout<<t.index<<"----->  ";
            for(int i=0;i<t.vec.size();i++){
                //cout<<t.vec[i]<<" ";
            }
            //cout<<endl;
        }


        //cout<<mp.size()<<endl;
        int sz = mp.size();
        int a,b;
        cin>>a>>b;

        while(1){
             if(a==0 && b==0)break;

            vector<int>store[100];
            int h=0;

            if(!m[a]){
                cout<<"Case "<<k<<": "<<sz<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
                k++;
                cin>>a>>b;
                continue;
            }
            if(b==0){
                cout<<"Case "<<k<<": "<<sz-1<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
                k++;
                cin>>a>>b;
                continue;
            }
            st tp = mp[a];
            map<int,int>ck;
            int cn=1;
            ck[a] = 1;
            bool tag=false;

            for(int i=0;i<tp.vec.size();i++){
                   if(!ck[tp.vec[i]]){
                        store[h].push_back(tp.vec[i]);
                        cn++;
                        //cout<<tp.vec[i]<<" ";
                        ck[tp.vec[i]] = 1;
                   }
            }

            //cout<<endl<<store[h].size()<<endl;

            for(int i=0;i<store[h].size();i++){
                if(h+1==b){ break;}
                st t =  mp[store[h][i]];
                //cout<<store[h][i]<<" is a index"<<endl;
                for(int j=0;j<t.vec.size();j++){
                    if(!ck[t.vec[j]]){
                        store[h+1].push_back(t.vec[j]);
                       // cout<<t.vec[j]<<" ";
                        ck[t.vec[j]] = 1;
                        cn++;
                    }
                }
                if(i==store[h].size()-1){
                        h=h+1;
                        i=-1;
                       // cout<<"h      "<<h<<"   "<<store[h].size()<<endl;
                       //cout<<endl;
                }

            }

            cout<<"Case "<<k<<": "<<sz-cn<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
            k++;
            cin>>a>>b;

        }
    }


}
