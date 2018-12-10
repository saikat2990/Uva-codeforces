#include<bits/stdc++.h>

using namespace std;

struct node{

    int val;
    int x,y;
    bool tag;

};

int main(){

    int n;
    while(cin>>n){

        int num;
        cin>>num;
        int wt[num];
        node ans[num+1][n+1];

        for(int i=0;i<num;i++){
            cin>>wt[i];
        }

        for(int i=0;i<=num;i++){
            for(int j=0;j<=n;j++){

                if(i==0 || j==0){

                    ans[i][j].val = 0;
                    ans[i][j].x = 0;
                    ans[i][j].y = 0;
                    ans[i][j].tag = false;
                }
                else if(j>=wt[i-1]){

                        ans[i][j].val = max(ans[i-1][j-wt[i-1]].val+wt[i-1],ans[i-1][j].val);
                        if(ans[i][j].val==ans[i-1][j-wt[i-1]].val+wt[i-1]){
                            ans[i][j].x = i-1;
                            ans[i][j].y = j-wt[i-1];
                            ans[i][j].tag = true;
                        }else{
                            ans[i][j].x = i-1;
                            ans[i][j].y = j;
                            ans[i][j].tag = false;
                        }

                }else{
                    ans[i][j].val = ans[i-1][j].val;
                    ans[i][j].x = i-1;
                    ans[i][j].y = j;
                    ans[i][j].tag = false;
                }
            }
        }

        int n1,n2,b1,b2;
        stack<int>st;

        if(ans[num][n].tag == true){
            //cout<<wt[num-1]<<" ";
            st.push(wt[num-1]);

        }
        n1 = ans[num][n].x;
        n2 = ans[num][n].y;

        while(1){

            if(n2==0)break;
            if(ans[n1][n2].tag==true){
                //cout<<wt[n1-1]<<" ";
                st.push(wt[n1-1]);
            }
            b1 = ans[n1][n2].x;
            b2 = ans[n1][n2].y;

            n1=b1;
            n2=b2;
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<"sum:"<<ans[num][n].val<<endl;


    }


return 0;
}

