#include<bits/stdc++.h>

using namespace std;




int main(){
    //freopen("kal.txt","w",stdout);
    int test;
    cin>>test;
    while(test--){

        int number,cases;
        cin>>number>>cases;
        vector<int>vec[number+1];
        map<int,int>store;
        for(int i=0;i<cases;i++){

            int a,b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);

        }
        queue<int>q;
       // bool tag[number+1]={false};
        for(int i=0;i<vec[0].size();i++){
            q.push(vec[0][i]);
            store[vec[0][i]] = 1;
        }

        while(!q.empty()){

            int index = q.front();
            q.pop();

            for(int i=0;i<vec[index].size();i++){

                if(!store.count(vec[index][i])){
                    store[vec[index][i]] = store[index]+1;
                    q.push(vec[index][i]);
                }

            }

        }
        for(int i=1;i<number;i++){
            cout<<store[i]<<endl;
        }
        if(test!=0)cout<<endl;
    }


}
