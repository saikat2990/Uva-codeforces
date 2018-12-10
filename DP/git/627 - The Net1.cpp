#include<bits/stdc++.h>

using namespace std;

int func(string s){

    stringstream iss(s);
    int re;
    iss>>re;
    return re;

}

int main(){

    //freopen("hack.txt","w",stdout);

    int n;
    int h=1;
    while(cin>>n){

        //if(h!=1)cout<<endl;

        h=2;
        string str;
        getline(cin,str);

        int arr[301][301]={0};

        for(int i=0;i<n;i++){

            getline(cin,str);

            for(int j=0;j<str.length();j++){
                if(str[j]=='-' || str[j]==',')str[j]=' ';
            }

            stringstream iss(str);
            string word;
            iss>>word;
            int sr = func(word);

            while(iss>>word){

                int index = func(word);
                arr[sr][index] = 1;
            }


        }

        int cases;
        cout<<"-----"<<endl;
        cin>>cases;

        for(int i=0;i<cases;i++){

            int sr,des;
            cin>>sr>>des;

            queue<int>qu;
            qu.push(sr);
            bool tag[n+1]={false};
            tag[sr] = true;

            map<int ,int>mp;

            while(!qu.empty()){

                int tp = qu.front();
                qu.pop();
                //cout<<tp<<" ";
                for(int k=1;k<=n;k++){

                    if(arr[tp][k]==1 && tag[k]==false){
                        qu.push(k);
                        mp[k] = tp;
                        tag[k] = true;
                        if(k==des)break;
                    }

                }
                if(qu.back()==des)break;
            }

            /*while(!qu.empty()){
                cout<<qu.front()<<" ";
                qu.pop();
            }*/

            if(qu.empty()){
                cout<<"connection impossible"<<endl;
                continue;
            }

            vector<int>vec;
            vec.push_back(des);
            //cout<<endl<<des<<" ";
            int parent = mp[des];

            while(1){
                if(parent!=sr){
                    //cout<<parent<<" ";
                    vec.push_back(parent);
                    parent = mp[parent];
                }else break;
            }
            //cout<<sr<<endl;
            vec.push_back(sr);

            for(int i=vec.size()-1;i>=0;i--){
                cout<<vec[i]<<" ";
            }
            cout<<endl;



        }


    }

}
