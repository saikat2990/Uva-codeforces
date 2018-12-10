#include<bits/stdc++.h>

using namespace std;

int main(){

    int resources,process;
    cin>>resources>>process;

    int allocator[process][resources];
    int max[process][resources];
    int available[process][resources];
    int need[resources];
    bool tag[process];

    cout<<"enter your allocator array"<<endl;
    for(int i=0;i<process;i++){
        for(int j=0;j<resources;j++){
            cin>>allocator[i][j];
        }
    }

    cout<<"enter your max array"<<endl;
    for(int i=0;i<process;i++){
        for(int j=0;j<resources;j++){
            cin>>max[i][j];
        }
    }

    for(int i=0;i<resources;i++){
        cin>>need[i];
    }

    for(int i=0;i<process;i++){
        for(int j=0;j<resources;j++){
            available[i][j]=(max[i][j]-allocator[i][j]);
        }
    }

    for(int n=0;n<process;n++){

        int cn=0;
        for(int i=0;i<process;i++){

            if(tag[i]==false){

                int ch=0;
                for(int j=0;j<resources;j++){

                   if(need[j]>=available[i][j]){
                      ch++;
                   }else{
                        cn++;
                        break;
                   }

                }

                if(ch==resources){
                    for(int j=0;j<resources;j++){
                        need[j]+=available[i][j];
                    }
                    tag[i]=true;
                    cout<<"P"<<i<<" ";
                }
            }

        }

        if(cn==process){

            cout<<"Deadlock occurs"<<endl;
            break;
        }

    }


return 0;
}
/*

3 5

0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

3 0 2

*/
