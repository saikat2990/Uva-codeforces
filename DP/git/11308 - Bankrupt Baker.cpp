#include<bits/stdc++.h>

using namespace std;

struct binders{

    string title;
    map<string,int>ingre;
    map<string,int>rcp;
    int limit;
};

struct store{
    string s;
    int demand;
};


bool cmp(store &s1,store &s2){


    if(s1.demand==s2.demand){
        return s1.s<s2.s;
    }
    else{
        return s1.demand<s2.demand;
    }
}

int  main(){

    //freopen("motherfuck.txt","w",stdout);

    int t;
    cin>>t;
    string str;


    while(t--){

        getline(cin,str);
        binders bd;
        getline(cin,bd.title);

        for(int i=0;i<bd.title.length();i++){
            if(bd.title[i]>='a' && bd.title[i]<='z'){
                bd.title[i] = bd.title[i]-32;
            }
        }

        vector<store>vec;

        int m,n,b;
        cin>>m>>n>>b;
        bd.limit = b;

        for(int i=0;i<m;i++){

            string st;
            int dollar;
            cin>>str>>dollar;
            bd.ingre[str] = dollar;
        }

        for(int i=0;i<n;i++){

             getline(cin,str);
             store sr;
             getline(cin,sr.s);
             int cost=0;
             int u;
             cin>>u;

             while(u--){

                string g;
                int bf;
                cin>>g>>bf;
                int gh;
                gh = bd.ingre[g];
                cost = cost + gh*bf;
                //cout<<gh<<" is  a   gh"<<endl;
             }

             if(cost<=b){

                sr.demand = cost;
                vec.push_back(sr);
             }
        }

             sort(vec.begin(),vec.end(),cmp);
             cout<<bd.title<<endl;

             if(vec.size()==0){

                cout<<"Too expensive!"<<endl;

             }
             else{
                vector<store>:: iterator it;

                for(it = vec.begin();it!=vec.end();it++){
                    store ts;
                    ts = *it;
                    cout<<ts.s<<endl;
                }
             }


        cout<<endl;

    }


return 0;
}
