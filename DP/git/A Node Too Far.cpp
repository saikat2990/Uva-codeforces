#include<bits/stdc++.h>

using namespace std;

struct node{

    int val;
    vector<node>link;
    bool index;

};

bool search(int a,vector<int>id){

    for(int i=0;i<id.size();i++){
        if(id[i]==a)return true;
    }

    return false;
}

int main(){

    int pairs;
    vector<node>nd;
    vector<int>id;
    cin>>pairs;
    bool tag1,tag2;

    for(int i=0;i<pairs;i++){

        int a,b;
        cin>>a>>b;

        tag1 = search(a,id);
        tag2 = search(b,id);


        if(!tag1 && !tag2){

            node temp1,temp2;

            temp1.val = a;
            temp1.index = false;

            temp2.val= b;
            temp2.index = false;

            temp1.link.push_back(temp2);
            temp2.link.push_back(temp1);

            nd.push_back(temp1);
            nd.push_back(temp2);

            id.push_back(a);
            id.push_back(b);


        }else if(!tag1 && tag2){

            node temp;
            temp.val=a;
            temp.index = false;



            for(int i=0;i<nd.size();i++){

                if(nd[i].val==b){
                    temp.link.push_back(nd[i]);
                    nd[i].link.push_back(temp);
                    break;
                }


            }

            nd.push_back(temp);
            id.push_back(a);

        }else if(!tag2 && tag1){

            node temp;
            temp.val=b;
            temp.index = false;



            for(int i=0;i<nd.size();i++){

                if(nd[i].val==a){
                    temp.link.push_back(nd[i]);
                    nd[i].link.push_back(temp);
                    break;
                }


            }

            nd.push_back(temp);
            id.push_back(b);
            //id.push_back(b);

        }else{

            node temp1,temp2;

            for(int i=0;i<nd.size();i++){

                if(nd[i].val==a){
                    temp1 = nd[i];
                }
                else if(nd[i].val==b){
                    temp2 = nd[i];
                }

            }

            for(int i=0;i<nd.size();i++){


                if(nd[i].val==a){
                    nd[i].link.push_back(temp2);
                }
                else if(nd[i].val==b){
                    nd[i].link.push_back(temp1);
                }


            }

        }



    }
    int numberOfnode,paisi=0;
    numberOfnode = id.size();

    while(1){

        paisi=0;
        int s,range1,range,inde;
        cin>>s>>range1;
        range=range1;
        paisi++;
        if(s==0 && range==0)break;

        vector<int>bfs[30];
         for(int i=0;i<nd.size();i++){
            nd[i].index=false;
         }

        for(int i=0;i<nd.size();i++){

            //cout<<nd[i].val<<" --->  ";

            if(nd[i].val==s){
                range--;
                nd[i].index = true;

                for(int j=0;j<nd[i].link.size();j++){

                    cout<<nd[i].link[j].val<<",";
                    bfs[0].push_back(nd[i].link[j].val);

                    for(int h=0;h<nd.size();h++){
                        if(nd[h].val == nd[i].link[j].val ){
                            nd[h].index = true;
                            paisi++;
                            break;
                        }
                    }

                }

            }
            cout<<endl;
        }

        int u=0;
        if(range1>1)
        for(int i=0;i<bfs[u].size();i++){

            s = bfs[u][i];
            cout<<s<<"    source";
            for(int j=0;j<nd.size();j++){

                if(s==nd[j].val){
                    //nd[j].index=true;
                    for(int k=0;k<nd[j].link.size();k++){


                        for(int h=0;h<nd.size();h++){

                            if(nd[h].val == nd[j].link[k].val && nd[h].index==false){
                                nd[h].index = true;

                                bfs[u+1].push_back(nd[j].link[k].val);
                                cout<<nd[j].link[k].val<<",";
                                paisi++;
                                break;
                            }

                        }


                        //inde++;
                    }
                }
            }
            cout<<endl;



            if(i+1==bfs[u].size()){

                u=u+1;
                for(int k=0;k<bfs[u].size();k++){
                    cout<<bfs[u][k]<<",";
                    i=-1;
                }
                range--;
                if(range==0)break;
            }



        }

        cout<<endl<<numberOfnode-paisi<<" "<<paisi<<endl;

    }

    for(int i=0;i<nd.size();i++){

            cout<<nd[i].val<<" --->  ";
        for(int j=0;j<nd[i].link.size();j++){
            cout<<nd[i].link[j].val<<",";
        }
        cout<<endl;
    }


return 0;
}
