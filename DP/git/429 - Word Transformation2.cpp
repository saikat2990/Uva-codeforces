#include<bits/stdc++.h>

using namespace std;

struct node{

    string name;
    int val;

};

int main(){

    freopen("f.txt","w",stdout);

    int cases;
    cin>>cases;
    string endline;
    getline(cin,endline);
    getline(cin,endline);

    for(int i=0;i<cases;i++){

        //cout<<"I am in"<<endl;
        vector<string>store;

        while(1){

            string initial,sr;
            getline(cin,initial);
            stringstream iss(initial);

            iss>>sr;
            //cout<<sr<<endl;
            store.push_back(sr);

            if(initial=="*")break;
        }

        while(1){

            string check;
            getline(cin,check);
            if(check==""){
                //cout<<" shes "<<endl;
                break;
            }

            stringstream iss(check);
            string source,des;
            iss>>source;
            iss>>des;

            cout<<source<<" "<<des<<" ";
            if(source==des){
                cout<<"0"<<endl;
                continue;
            }
            node tp;
            tp.name = source;
            tp.val =0;
            queue<node>qu;
            qu.push(tp);
            map<string,int>mp;
            mp[source] = 0;

            while(!qu.empty()){

                node temp = qu.front();
                qu.pop();
                string ch = temp.name;
                int len = ch.length();

                for(int j=0;j<store.size();j++){

                    if(store[j].length()==len && mp.count(store[j])==0){

                        int r=0;

                        for(int k=0;k<len;k++){
                            if(store[j][k]!=ch[k])r++;
                        }

                        if(r==1){

                            node sre;
                            sre.name = store[j] ;
                            sre.val = temp.val+1;
                            qu.push(sre);
                            mp[store[j]] = temp.val+1;
                            if(des==store[j])break;
                        }
                    }
                }
                if(qu.back().name==des)break;

            }
            node nd = qu.back();
            cout<<nd.val<<endl;
        }

        if(i!=cases-1)cout<<endl;
    }


}
