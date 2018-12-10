#include<bits/stdc++.h>

using namespace std;

struct st{
    int value,count;
};

int main(){

    int n;
    //freopen("dada.txt","w",stdout);

    while(cin>>n){

        vector<int>vec[n+1];

        for(int i=0;i<n;i++){

            int number;
            cin>>number;

            while(number--){
                int val;
                cin>>val;
                vec[i].push_back(val);
            }

        }


        int test;
        cin>>test;
        //cout<<"test  "<<test<<endl;
        for(int i=0;i<test;i++){

            queue<st>qu;
            vector<st>ans;
            int source;
            cin>>source;
            bool tag[2500]={false};
            tag[source] = true;
            st temp;
            temp.value=source;
            temp.count=0;
            qu.push(temp);
            ans.push_back(temp);
            int cn=1;

            while(!qu.empty()){

                st tp = qu.front();
                qu.pop();
                //cout<<vec[tp.value].size()<<endl;
                for(int j=0;j<vec[tp.value].size();j++){

                    if(tag[vec[tp.value][j]]==false){

                        tag[vec[tp.value][j]]=true;
                        st store;
                        store.value = vec[tp.value][j];
                        store.count = tp.count+1;
                        qu.push(store);
                        ans.push_back(store);

                    }

                }

            }

            int dada[ans.size()+1]={0};
            for(int j=0;j<ans.size();j++){
                //cout<<ans[j].value<<" "<<ans[j].count<<endl;
                dada[ans[j].count]++;
            }
            int max = *max_element(dada,dada+ans.size());
            if(ans.size()==1){cout<<"0"<<endl; continue;}
            cout<<max<<" ";
            for(int j=1;j<ans.size();j++){
                if(dada[j]==max){

                    cout<<j<<endl;
                    break;
                }
            }

        }
    }



return 0;
}
