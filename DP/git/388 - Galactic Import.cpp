#include<bits/stdc++.h>
#define INFI 9999999;

using namespace std;

int store[27][27];
int val[27];
int path[27];

typedef pair<int,int>pa;

int  main(){

    int n;

    while(cin>>n){

        for(int i=0;i<27;i++){

            path[i] = INFI;
            for(int j=0;j<27;j++){
                store[i][j] = 0;
            }

        }

        for(int i=0;i<n;i++){

            char ch;
            cin>>ch;
            float f;
            cin>>f;
            string str;
            cin>>str;

            int po = ch-'A';
            int v  = f*100;

            val[po] = v;

            for(int i=0;i<str.length();i++){

                if(str[i]=='*'){
                    store[26][po] = store[po][26] = 1;
                }else{
                    store[i][str[i]-'A'] = store[str[i]-'A'][i] = 1;
                }
            }


        }


        queue<pa>q;

        q.push(pa(26,0));

        while(!q.empty()){

            pa temp = q.front();
            q.pop();

            for(int i=0;i<26;i++){

                if(store[temp.first][i]==1 && temp.second+1<path[i]){

                    path[i] = temp.second+1;
                    q.push(pa(i,temp.second+1));


                }
            }
        }

        double e = 0.0;
        int j=0;

        for(int i=0;i<26;i++){
            double b = val[i] - (val[i]*0.05*(path[i]-1));
            if(b>e){
                j = i;
                e = b;
            }
        }
        cout<<char(j+'A')<<endl;


    }



return 0;
}
