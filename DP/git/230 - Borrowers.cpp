#include<bits/stdc++.h>

using namespace std;

struct node{

    string name;
    string author;

};
string func(char ch){

    stringstream iss;
    string st;
    iss<<ch;
    iss>>st;
    return st;
}

int main(){

    map<string , int>mymap;


    //mymap.insert(pair<string ,int>("akib",2));

    map<string, int>::iterator it;
    it = mymap.begin();


    vector<node>nd;
    int h=1;
    while(1){

        string str;
        getline(cin,str);
        if(str=="END")break;
        string name,author;
        name=func('"');

        int i=1;
        for(i=1;i<str.length();i++){
            //name+=func(str[i]);
            name+=str[i];
            if(str[i]=='"'){
                break;
            }
        }
        cout<<str[i+1]<<str[i+2]<<str[i+3]<<endl;
        author="";
        for(i=i+5;i<str.length();i++){
            //author+=func(str[i]);
            author+=str[i];
        }

        cout<<name<<" "<<author<<endl;

        node temp;
        temp.name = name;
        temp.author = author;
        nd.push_back(temp);
        mymap.insert(pair<string ,int>(author,h));
        h++;
    }

    for(int i=0;i<nd.size();i++){
        cout<<nd[i].name<<endl;
    }
    cout<<endl;
    stack<string>stk;

    while(1){

        string st,st1,temp;
        string nam,autho;
        getline(cin,st1);
        stringstream iss;
        iss<<st1;
        iss>>st;
        nam="";
        while(iss>>temp){
            nam+=temp;
            nam+=" ";
        }
        nam[nam.length()-1]='\0';

        cout<<"st "<<st<<" name "<<nam<<endl;

        if(st=="SHELVE"){

            string temp = stk.top();
            cout<<temp;
            stk.pop();
            mymap.insert(pair<string ,int>(temp,12));
            it = mymap.find(temp);
            cout<<it->first<<endl;

        }



        /*for(int i=1;i<nam.length();i++){
            nam[i-1]=nam[i];
        }
        nam[nam.length()-1]='\0';*/

        cout<<endl<<"nam"<<nam<<endl;

        for(int i=0;i<nd.size();i++){

            cout<<nd[i].name<<" hello "<<nd[i].author<<" "<<endl;
            if(nd[i].name == nam){
                autho = nd[i].author;
                cout<<endl<<"author   "<<autho<<endl;
                break;
            }
        }
        if(st=="BORROW"){
            mymap.erase(autho);
            it = mymap.begin();
            for(;it!=mymap.end();it++){
                cout<<it->first<<" "<<endl;
            }

        }
        else if(st=="RETURN")stk.push(autho);
    }

return 0;
}
