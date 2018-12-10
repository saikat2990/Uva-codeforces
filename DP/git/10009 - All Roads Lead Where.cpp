#include<bits/stdc++.h>

using namespace std;

struct st{

    string str;
    int parent;

};

int main(){

    //freopen("dada.txt","w",stdout);

    int n;
    cin>>n;
    while(n--){

        int node,query;
        cin>>node>>query;
        map<string,int>mp;
        map<int,string>antimp;
        int cn=1;

        int arr[2*node+1][2*node+1]={0};

        for(int i=0;i<node;i++){

            string str1,str2;
            cin>>str1>>str2;

            if(mp.count(str1)==0){
                mp[str1]  = cn;
                antimp[cn] = str1;
                //cout<<str1<<" --> " <<cn;
                cn++;
            }
            if(mp.count(str2)==0){
                mp[str2] = cn;
                antimp[cn] = str2;
                //cout<<str2<<" --> " <<cn;
                cn++;
            }

           // cout<<endl<<mp[str1]<<"  "<<mp[str2]<<endl;
            arr[mp[str1]][mp[str2]] =1;
            arr[mp[str2]][mp[str1]] =1;

        }


        for(int i=0;i<query;i++){

            string source,des;
            cin>>source>>des;
            queue<st>qu;


            st temp;
            temp.str = source;
            temp.parent = mp[source];
            bool tag[node+1] = {false};
            tag[mp[source]] = true;
            qu.push(temp);

            map<string,int>ans;
            ans[source] = mp[source];
            while(!qu.empty()){

                st tp = qu.front();
                qu.pop();
                if(tp.str==des)break;
                int in = mp[tp.str];

                for(int j=1;j<cn;j++){
                    if(arr[in][j]==1 && tag[j]==false){

                        st tep;
                        tep.str = antimp[j];
                        tep.parent = in;
                        qu.push(tep);
                        tag[j] = true;
                        ans[antimp[j]] = in;
                         //if(antimp[j]==des)break;

                    }
                }
                //if(qu.back().str==des)break;

            }
            string ch = qu.back().str;
            vector<char>v;

            //cout<<des<<" ";
            v.push_back(des[0]);
            while(1){

                if(ans[ch] == mp[source])break;
                //cout<<antimp[ans[ch]]<<" ";
                v.push_back(antimp[ans[ch]][0]);
                ch=antimp[ans[ch]];

            }
            //cout<<source<<endl<<endl;
            v.push_back(source[0]);
            for(int i=v.size()-1;i>=0;i--){
                cout<<v[i];
            }
            cout<<endl;

        }

        if(n!=0)cout<<endl;
    }



return 0;
}
