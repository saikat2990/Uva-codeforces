#include<bits/stdc++.h>

using namespace std;

vector<int>vec[100000];

int func(string word){

    stringstream iss(word);
    int n;
    iss>>n;
    return n;

}


int main(){

    //freopen("dada.txt","w",stdout);
    int test;
    cin>>test;
    while(test--){

        int n;
        cin>>n;
        /*string strline;
        getline(cin,strline);
        //getline(cin,strline);

        for(int i=0;i<n;i++){

            getline(cin,strline);
            stringstream iss(strline);
            string str;
            iss>>str;
            int index;
            index = func(str);
            //cout<<"index is  "<<index<<endl;
            while(iss>>str){
                vec[index].push_back( func(str) );
            }

        }*/

        for(int i=0;i<n;i++){
            int index,num;
            cin>>index>>num;
            for(int j=0;j<num;j++){
                int val;
                cin>>val;
                vec[index].push_back(val);
            }
        }

        int source,des;
        cin>>source>>des;
        cout<<source<<" "<<des<<" ";
        queue<int>q;
        map<int,int>mp;
        q.push(source);
        mp[source] = 0;
        int cn=1;
        while(!q.empty()){

            int index ;
            index = q.front();
            q.pop();
            for(int i=0;i<vec[index].size();i++){
                if(!mp.count(vec[index][i])){

                    q.push(vec[index][i]);
                    mp[vec[index][i]] = mp[index]+1;
                    if(vec[index][i]==des)break;
                }
            }
            if(des==q.back())break;
        }

        cout<<mp[des]-1<<endl;
        if(test!=0)cout<<endl;
        for(int i=0;i<n;i++){
            vec[i].clear();
        }
    }




}
