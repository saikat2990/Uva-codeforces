#include<bits/stdc++.h>

using namespace std;
/*struct node{

    string str;
    vector<int>vec;
    int amount;
};

node func(string st){

    node temp;
    temp.str = st;
    for(int i=0;i<st.length();i++){
        temp.vec.push_back(st[i]-'0');
    }
    temp.amount=0;

}

int main(){

    int ans = 10;
    vector<node>nd;

    while(ans--){

        string st;
        getline(st);
        node n = func(st);
        vector<node>:: iterator it;
        it = nd.begin();
        bool tag = false;

        for(;it<nd.end();it++){

        }

    }

}*/
int main(){

    //ofstream ofile;
    FILE *fp;
    fp = fopen("hu.txt","w");

    int test;
    cin>>test;

    while(test--){

        map<string, int>mymap;
        int n=0;
        string str;

        while(getline(cin,str)){

            if(str=="\0")break;
            mymap[str]++;
            n++;

        }

        map<string, int>:: iterator it;

        float f = 100/(float)n;

        for(it = mymap.begin();it!=mymap.end();it++){
                cout<<it->first;
                //ofile<<it->first;

                printf(" %.4f\n",it->second*f);

                //fprintf(fp," %.4f\n",it->second*f);
                //ofile<<" "<<setprecision(4)<<it->second*f<<endl;

        }

        cout<<endl;
        //ofile<<endl;

    }

}

