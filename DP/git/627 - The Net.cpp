#include<bits/stdc++.h>

using namespace std;

struct st{
    int parent;
    int  value;
};

int main(){

    freopen("kal.txt","w",stdout);
    int n;
    while(cin>>n){

        string str;
        getline(cin,str);

        vector<st>arr[301];

        for(int i=0;i<n;i++){

            string str;
            getline(cin,str);

            for(int j=0;j<str.length();j++){
                if(str[j]=='-' || str[j]==',')str[j]=' ';
                //break;
            }

            stringstream iss(str);
            int papa,son;
            iss>>papa;
            //cout<<papa<<"  papa --> ";

            while(iss>>son){

                st temp;
                temp.parent = papa;
                temp.value = son;
                arr[papa].push_back(temp);

                //cout<<son<<" ";

            }
            //cout<<endl;


        }

        int check;
        cin>>check;
        cout<<"-----"<<endl;
        while(check--){

            int sr,des;
            cin>>sr>>des;
            map<int,int>mp;

            queue<st>q;
            st temp;
            temp.parent = sr;
            temp.value = sr;
            q.push(temp);
            mp[sr]=sr;

            while(!q.empty()){

                temp = q.front();
                q.pop();
                int pa = temp.value;
                int tag = false;
                for(int i=0;i<arr[pa].size();i++){

                    if(mp.count(arr[pa][i].value)==0){
                        st t;
                        t.parent = pa;
                        t.value = arr[pa][i].value;
                        q.push(t);
                        mp[arr[pa][i].value] = pa;
                        //cout<<arr[pa][i].value<<" "<<pa<<endl;
                    }
                    if(arr[pa][i].value==des){
                        tag=true;
                        break;
                    }

                }
                if(tag==true)break;

            }
            vector<int>ans;
            //cout<<des;
            ans.push_back(des);

            int p = des;
            int cn=0;
            while(1){

                if(sr==p)break;
                if(mp[p]!=0){
                    //cout<<" "<<mp[p];
                    ans.push_back(mp[p]);
                }
                p = mp[p];
                cn++;
                if(cn==n){
                    cout<<"connection impossible";
                    break;
                }

            }

            if(ans.size()>1){
                for(int i=ans.size()-1;i>=0;i-- ){
                    cout<<ans[i]<<" ";
                }
            }

            cout<<endl;
        }




    }


return 0;
}
