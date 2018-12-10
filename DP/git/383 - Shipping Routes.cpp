#include<bits/stdc++.h>
using namespace std;

struct node{

    string str;
    int index;
    vector<int>store;

};

int main(){

    ofstream ofile;
    ofile.open("hx.txt");

    int test,u=1;;
    cin>>test;
    cout<<"SHIPPING ROUTES OUTPUT"<<endl;
    ofile<<"SHIPPING ROUTES OUTPUT"<<endl;
    while(test--){

        int n,m,p;
        cin>>n>>m>>p;
        cout<<endl<<"DATA SET  "<<u<<endl<<endl;
        ofile<<endl<<"DATA SET  "<<u<<endl<<endl;
        u++;


        vector<node>nd;
        node arr[n+1];

        for(int i=0;i<n;i++){

            string st;
            cin>>st;
            node temp;
            temp.str = st;
            temp.index = i+1;
            //arr[]
            nd.push_back(temp);

        }

        for(int i=0;i<m;i++){

            string str1,str2;
            cin>>str1>>str2;
            int n1,n2;

            for(int j=0;j<nd.size();j++){
                if(nd[j].str==str1)n1=nd[j].index;
                else if(nd[j].str==str2)n2 = nd[j].index;
            }

            for(int j=0;j<nd.size();j++){

                if(nd[j].str==str1){
                    nd[j].store.push_back(n2);
                }
                else if(nd[j].str==str2){
                    nd[j].store.push_back(n1);
                }

            }

        }

        for(int i=0;i<nd.size();i++){
            for(int j=0;j<nd[i].store.size();j++){
               // cout<<nd[i].store[j]<<" ";
            }
            //cout<<endl;
        }


        for(int i=0;i<p;i++){

            string str1,str2;
            int t;
            bool sym[n+1]={false};
            cin>>t>>str1>>str2;
            if(m==0){
                cout<<"$0"<<endl;
                ofile<<"$0"<<endl;
                break;
            }
            int n1,n2;
            vector<int>ans[30];
            int h=0;
            bool tg = false;

            for(int j=0;j<nd.size();j++){

                if(nd[j].str==str2){
                    //nd[j].store.push_back(n2);
                    n2=nd[j].index;
                }
            }
            int count=0;
            for(int j=0;j<nd.size();j++){

                if(nd[j].str==str1){

                    sym[nd[j].index] = true;

                    //cout<<nd[j].index<<"  ";
                     count++;

                    for(int k=0;k<nd[j].store.size();k++){

                        ans[h].push_back(nd[j].store[k]);


                        if(nd[j].store[k]==n2){
                            cout<<"$"<<t*100*(h+1)<<endl;
                            ofile<<"$"<<t*100*(h+1)<<endl;
                            tg=true;
                            break;
                        }
                    }
                    break;
                }

            }
            //cout<<endl;

            if(ans[h].size()==0){
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
                ofile<<"NO SHIPMENT POSSIBLE"<<endl;
                        //break;
                    continue;
            }

            if(tg==false){
                bool gf=false;
                for(int j=0;j<ans[h].size();j++){
                    int temp = ans[h][j];

                    for(int k=0;k<nd.size();k++){
                        if(nd[k].index == temp){
                            sym[nd[k].index]=true;
                            count++;
                            //cout<<nd[k].index<<"  ";
                            for(int g=0;g<nd[k].store.size();g++){

                                if(sym[nd[k].store[g]]==false){
                                        //cout<<nd[k].store[g]<<" hsgdfiugsidf";

                                        ans[h+1].push_back(nd[k].store[g]);

                                        if(nd[k].store[g]==n2){
                                            cout<<"$"<<t*100*(h+2)<<endl;
                                            ofile<<"$"<<t*100*(h+2)<<endl;
                                            tg=true;
                                            break;
                                        }
                                }
                            }
                            break;
                        }
                    }
                    //h=h+1;
                    //cout<<h<<" h  "<<endl;


                    if(tg==true)break;
                    if(j==ans[h].size()-1)h=h+1;
                    if(ans[h].size()==0){
                        cout<<"NO SHIPMENT POSSIBLE"<<endl;
                        ofile<<"NO SHIPMENT POSSIBLE"<<endl;
                        gf=true;
                        break;
                    }

                }
                    if(sym[n2]==false && tg==false && gf==false){
                        cout<<"NO SHIPMENT POSSIBLE"<<endl;
                        ofile<<"NO SHIPMENT POSSIBLE"<<endl;
                       // break;
                    }

            }


        }




    }

    cout<<endl<<"END OF OUTPUT"<<endl;
    ofile<<endl<<"END OF OUTPUT"<<endl;
return 0;
}
