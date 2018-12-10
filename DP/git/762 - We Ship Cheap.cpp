#include<bits/stdc++.h>

using namespace std;

struct st{

    string parent,son;

};

int main(){

    int n;
    //cin>>n;
    freopen("mal.txt","w",stdout);
    int y=0;
    while(cin>>n){

        if(y!=0)cout<<endl;
        map<string,int>mp;
        map<int,string>stmp;
        vector<st>vec;
        int k=0;
        for(int i=0;i<n;i++){

            string str1,str2;
            cin>>str1>>str2;

            st temp;
            temp.parent = str1;
            temp.son = str2;
            vec.push_back(temp);

            if(mp.count(str1)==0){
                mp[str1] = k+1;
                stmp[k+1] = str1;
                k=k+1;
            }

            if(mp.count(str2)==0){
                mp[str2] = k+1;
                stmp[k+1] = str2;
                k=k+1;
            }

        }

        vector<int>ans[2*n+1];
       // cout<<k<<endl;
        for(int i=0;i<vec.size();i++){

            st tp = vec[i];
            string s1,s2;
            s1 = tp.parent;
            s2 = tp.son;
            //cout<<mp[s1]<<" "<<mp[s2]<<endl;
            ans[mp[s1]].push_back(mp[s2]);
            ans[mp[s2]].push_back(mp[s1]);


        }

        for(int i=1;i<=n;i++){
           // cout<<stmp[i]<<" --> ";
            for(int j=0;j<ans[i].size();j++){
                //cout<<stmp[ans[i][j]]<<"  ";
            }
            //cout<<endl;

        }

        string strr;
        getline(cin,strr);

        while(getline(cin,strr)){
            //if(y!=0)cout<<endl;
            stringstream iss(strr);

            if(strr==""){
                //iss>>n;
                //cout<<"Hello vai"<<endl;
                //getline(cin,strr);
                //getline(cin,strr);
                //getline(cin,strr);
                break;
            }else {

                string sr,des;
                iss>>sr;
                iss>>des;

                //cout<<sr<<"   "<<des<<endl;
                int aa = mp[sr];
                int dd = mp[des];

                queue<int>q;
                map<string,string>mmpp;

                q.push(aa);
                int y =aa;
                mmpp[stmp[y]] = "asas";

                while(!q.empty()){
                    y= q.front();
                    //cout<<y<<"     ";
                    q.pop();
                    bool tg = false;
                    for(int u=0;u<ans[y].size();u++){

                      if(mmpp[stmp[ ans[y][u] ] ]==""){
                            q.push(ans[y][u]);
                           // cout<<"  "<<ans[y][u];
                            mmpp[stmp[ ans[y][u] ] ] = stmp[y];
                            //cout<<stmp[ ans[y][u] ]<<" ";
                            if(ans[y][u]==dd){
                                tg = true;
                                break;
                            }
                      }
                    }

                    if(tg==true)break;

                }
                if(q.empty()){
                    cout<<"No route"<<endl<<endl;
                    continue;
                }

                string desti;
                desti = des;

                //cout<<des;

                stack<string>fin;
                fin.push(des);

                while(1){

                    if(desti==sr)break;
                    //cout<<" "<<mmpp[desti];
                    fin.push(mmpp[desti]);
                    desti = mmpp[desti];

                }
                //cout<<endl;
                cout<<fin.top()<<" ";

                fin.pop();

                while(!fin.empty()){

                    cout<<fin.top()<<endl;
                    if(fin.size()!=1)cout<<fin.top()<<" ";
                    else  cout<<endl;
                    fin.pop();

                }

                //y++;

            }


        }

    }

}

