#include<bits/stdc++.h>

using namespace std;

int main(){

    int test;
    cin>>test;
    ofstream ofile;
    ofile.open("hx.txt");


    while(test--){

        int n,k;
        cin>>n>>k;
        bool arr[n+1]={false};
        vector<int>ans[100];
        int h=0;
        for(int i=0;i<k;i++){

            int s;
            cin>>s;
            vector<int>vec;
            for(int j=0;j<2*s;j++){
                int k;
                cin>>k;
                vec.push_back(k);
            }
            string str;
            //cin>>str;
            char ch;
            cin>>ch;
            if(ch=='='){
                for(int j=0;j<vec.size();j++){
                    arr[vec[j]]=true;
                }
            }else {
                //cout<<"asasas"<<endl;
            }

        }
        h=0;
        for(int i=1;i<=n;i++){
            if(arr[i]==false)h++;
        }
        if(h>1){
            cout<<"0"<<endl;
            ofile<<"0"<<endl;
            if(test!=0)cout<<endl,ofile<<endl;
        }else{
            for(int i=1;i<=n;i++){
                if(arr[i]==false){
                        cout<<i<<endl,ofile<<i<<endl;
                        if(test!=0)cout<<endl,ofile<<endl;

                }
            }
        }

    }

}
