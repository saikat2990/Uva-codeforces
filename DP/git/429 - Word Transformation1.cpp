#include<bits/stdc++.h>

using namespace std;

int main(){

    //freopen("f.txt","w",stdout);

    int cases;
    cin>>cases;
    string stri;
    getline(cin,stri);


    string m="";

    for(int o=0;o<cases;o++){

        getline(cin,stri);
        cout<<"i am in "<<endl;
        vector< string >store;
        string s;
        if(m.length()!=0){
            //sr>>s;
            //cout<<"   m  "<<m<<endl;
            store.push_back(m);
        }
        while(1){

            string str;
            stringstream iss;
            getline(cin,str);
            iss<<str;
            iss>>m;
            if(m=="*")break;
            store.push_back(m);

        }

        string str1,str2;
        int g=1;
        while(1){

            if(g!=1)cout<<str1<<" "<<str2;
            else if(g==1){
                for(int i=0;i<str1.length();i++){
                    cout<<str1[i];
                }
                cout<<" "<<str2;
            }
            if(str1==str2){
                if(g!=1 && g!=2)cout<<" 0"<<endl;
                string line;
                stringstream sr,sr1;
                int word=0;
                string stu[2];
                getline(cin,line);
                sr<<line;
                //sr1<<line;
                while(sr>>m){
                    stu[word] = m;
                    word++;
                }
                if(word==1){
                    m=stu[0];
                    break;
                }else{
                    str1 = stu[0];
                    str2 = stu[1];
                }
                continue;
            }
            vector<string>ans[1000];
            map<string,int>mp;
            mp[str1]=1;
            int n = str1.length();
            bool ui = false;
            for(int i=0;i<store.size();i++){
                string temp = store[i];
                if(temp.length()==n && mp.count(temp)==0){
                    int ch=0;
                    for(int j=0;j<n;j++){
                        if(temp[j]!=str1[j])ch++;
                    }

                    if(ch==1){
                        ans[0].push_back(temp);
                        //cout<<temp<<" ";
                        if(temp==str2){
                            cout<<" 1"<<endl;
                            ui = true;
                            break;
                        }
                        mp[temp] = 1 ;
                    }
                }
            }
            if(ui==false){

                int p=0;

                for(int h=0;h<ans[p].size();h++){

                    str1 = ans[p][h];
                    //cout<<ans[p].size()<<"   length()   "<<endl;
                    bool tag = false;
                     for(int i=0;i<store.size();i++){
                        string temp = store[i];
                        //cout<<temp<<endl;

                        if(temp.length()==n && mp.count(temp)==0){
                            int ch=0;
                            for(int j=0;j<n;j++){
                                if(temp[j]!=str1[j])ch++;
                            }
                            if(ch==1){
                                ans[p+1].push_back(temp);
                                //cout<<temp<<" ";
                                mp[temp] = 1;
                                if(temp==str2){
                                    p=p+1;
                                    tag = true;
                                    break;
                                }
                            }
                        }
                    }

                    if(tag==true)break;
                    if(h==ans[p].size()-1){
                            p = p+1;
                            h=-1;
                    }
                }
                cout<<" "<<p+1<<endl;
            }

            string line;
            stringstream sr,sr1;
            int word=0;
            string stu[2];
            getline(cin,line);
            sr<<line;
            //sr1<<line;
            while(sr>>m){
                stu[word] = m;
                word++;
            }
            if(word==1){
                m=stu[0];
                break;
            }else{
                str1 = stu[0];
                str2 = stu[1];
            }
            g++;
        }

    }


}
