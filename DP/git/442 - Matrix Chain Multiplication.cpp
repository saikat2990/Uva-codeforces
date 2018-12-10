#include<bits/stdc++.h>

using namespace std;

struct idk{

    int index,num1,num2;
};

int main(){

    int number;
    cin>>number;
    stack<int>stc;

    idk vec[5000];
    string str;
    for(int i=0;i<number;i++){

        char ch;
        int row,col;
        cin>>ch>>row>>col;
        getline(cin,str);
        //cout<<ch-'A'+1<<endl;
        vec[ch-'A'+1].index = ch-'A'+1;
        vec[ch-'A'+1].num1 = row;
        vec[ch-'A'+1].num2 = col;

    }


    while(cin>>str){

        int sum=0;
        int l=31;
        bool tag=true;
        //cout<<str;
        if(str[0]!='(')cout<<0<<endl;
        else {
            for(int i=0;i<str.length();i++){

                if(str[i]!='(' && str[i]!=')'){
                    stc.push(str[i]-'A'+1);
                    //cout<<str[i]<<" "<<str[i]-'A'+1<<" "<<vec[str[i]-'A'+1].num1<<endl;
                }
                else if(str[i]==')'){

                    int a = stc.top();
                    stc.pop();
                    //cout<<a<<" ";
                    int b = stc.top();
                    stc.pop();
                    //cout<<b<<" ";

                    idk i2 = vec[a];
                    idk i1 = vec[b];

                    //cout<<i1.num2<<"  "<<i2.num1<<endl;
                    if(i1.num2!=i2.num1){
                        tag=false;
                        break;
                    }
                    else{

                        sum+=(i1.num1*i1.num2*i2.num2);
                        //cout<<sum<<endl;
                        idk newI ;
                        newI.index=0;
                        newI.num1 = i1.num1;
                        newI.num2 = i2.num2;
                        vec[l] = newI;
                        stc.push(l);
                        l++;

                    }
                }

            }

            if(tag==false){
                cout<<"error"<<endl;
                tag=true;
            }
            else cout<<sum<<endl;
        }
    }



return 0;
}
/*
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
((D(EF))((GH)I))
*/
