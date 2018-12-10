#include<bits/stdc++.h>

using namespace std;

//#define inf 100000;


map<string , int>msi;
//map<int , string>mis;
//vector< vector<int> >vvi;
vector< int >vvi[5000];
vector<int>vecInt;

int main(){

    //freopen("dada.txt","w",stdout);
    //
    string strline,word;
    string name="";

    int n=1;

    int test,line,ck;
    cin>>test;


    for(int t=1;t<=test;t++){

        cin>>line>>ck;
        getline(cin,strline);
        cout<<"Scenario "<<t<<endl;
        for(int i=0;i<=4999;i++)vvi[i].clear();
        msi.clear();
        //mis.clear();
        //vvi.push_back(vecInt);

        msi["Erdos, P."]=1;
        //mis[1] = "Erdos, P.";
        for(int l=1;l<=line;l++){

            vector<int>lists;
            getline(cin,strline);

            for(int i=0;i<strline.length();i++){
                if(strline[i]==',')strline[i]=' ';
            }

            stringstream iss;
            iss<<strline;
            while(iss>>word){

                name+=word;
                name=name+", ";
                iss>>word;

                if(word[word.length()-1]==':'){

                    //word[word.length()-1]='\0';
                    for(int i=0;i<word.length()-1;i++){
                        name+=word[i];
                    }

                    if(msi.count(name)==0){
                        msi[name]=++n;
                        //vvi.push_back(vecInt);
                        //mis[n] = name;
                    }
                    //cout<<name<<msi[name]<<endl;
                    lists.push_back(msi[name]-1);
                    name="";
                    break;

                }
                name+=word;
                if(msi.count(name)==0){
                        msi[name]=++n;
                        //vvi.push_back(vecInt);
                        //mis[n] = name;
                }
                //cout<<name<<msi[name]<<endl;
                lists.push_back(msi[name]-1);
                name="";

            }

            for(int i=0;i<lists.size();i++){
                for(int j=i+1;j<lists.size();j++){
                    vvi[lists[i]].push_back(lists[j]);
                    vvi[lists[j]].push_back(lists[i]);
                }
            }


        }

        /*for(int i=1;i<=n;i++){

            ans[mis[i]]=inf;
        }

        for(int i=0;i<vvi[0].size();i++){
            ans[mis[vvi[0][i]+1]]=2;
        }*/

        for(int i=0;i<ck;i++){

            string stll,stl="",word;
            getline(cin,stl);

            //cout<<msi[stl]<<endl;
            /*stringstream is;
            is<<stll;
            is>>word;
            stl=word;
            is>>word;
            stl+=word;*/
            int y;
            for(int p=0;p<stl.length();p++){
                if(stl[p]!=' '){y=p; break;}
            }
            word=stl;
            stl="";
            for(int p=y;p<word.length();p++)stl+=word[p];

            int kk = msi[stl];

            queue<int>q;
            map<int,int>mp;
            mp[kk]=1;

            q.push(kk);

            while(!q.empty()){

                int temp = q.front();
                q.pop();

                for(int j=0;j<vvi[temp-1].size();j++){

                    if(mp.count(vvi[temp-1][j]+1)==0){

                        q.push(vvi[temp-1][j]+1);
                        mp[vvi[temp-1][j]+1] = mp[temp]+1;
                    }
                    if(vvi[temp-1][j]==0)goto hell;
                }

            }
            hell:
                cout<<word;
                if(mp[1]==0){
                    cout<<" infinity"<<endl;
                }else cout<<" "<<mp[1]-1<<endl;

        }



        /*for(int i=0;i<n;i++){
            cout<<i<<" --> ";
            for(int j=0;j<vvi[i].size();j++){
                cout<<vvi[i][j]<<",";
            }
            cout<<endl;
        }*/

    }



}

