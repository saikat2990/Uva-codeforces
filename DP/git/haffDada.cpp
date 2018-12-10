#include<bits/stdc++.h>

using namespace std;

struct s{

    char ch;
    string code;
    int codeLen;
    int val;

};

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp/10;

        dec_value += last_digit*base;

        base = base*2;
    }

    return dec_value;
}

string charToString(char ch){

    stringstream iss;
    string sr;
    iss<<ch;
    iss>>sr;
    return sr;
}

int stringToNum(string ch){

    stringstream iss;
    int sr;
    iss<<ch;
    iss>>sr;
    return sr;
}

int main(){

    s A ;
    A.ch = 'A';
    A.code = "01000111";
    A.codeLen = 8;
    A.val = 8;


    s B;
    B.ch = 'B';
    B.code = "010000";
    B.codeLen = 6;
    B.val = 7;

    s C;
    C.ch = 'C';
    C.code = "110100011";
    C.codeLen=9;
    C.val = 99;

    vector<s>p;

    p.push_back(A);
    p.push_back(B);
    p.push_back(C);


    vector<s>:: iterator it;
    vector<char>ans;
    unsigned int n=0,store=0,need=0,storeVal=0,useVal=0;
    unsigned char ch=0;
    bool tag=false;
    vector<char>:: iterator c;

    for(it=p.begin();it!=p.end();it++){

        s temp = *it;
        for(int i=0;i<temp.codeLen;i++){
            ans.push_back(temp.code[i]);
        }


       /* if(n+temp.codeLen>8){

            store = (n+temp.codeLen)-8;
            need = temp.codeLen - store;
            //convert = temp.val;
            cout<<need<<store<<endl;
            storeVal=temp.val<<(32-store);
            cout<<storeVal<<"is the store value"<<endl;
            storeVal = storeVal>>(32-store);
            cout<<storeVal<<"is the store value"<<endl;
            useVal = temp.val>>store;
            cout<<useVal<<endl;
            //cout<<ch<<endl;
            ch=ch<<need;
            ch = ch|useVal;
            cout<<ch<<endl;
            ch=0|storeVal;
            cout<<(int)ch<<endl;
            n=store;
            tag = true;

        }
        else{

            if(tag==true){
                tag = false;
                cout<<n<<" n  "<<endl;
                ch=ch<<temp.codeLen;
                cout<<(int)ch<<"  "<<temp.val;
            }
            ch=ch|temp.val;
            cout<<"jani na "<<ch<<endl;
             n = n+temp.codeLen;
        }
        //n = n+temp.codeLen;
        */


    }

    if(ans.size()%8!=0){
        cout<<ans.size()%8<<endl;
        for(int j=8-ans.size()%8;j<=8;j++){
            ans.push_back('0');
        }
    }

    string num="";
    int i=0;
    char ch1;
    for(c = ans.begin(); c!=ans.end();c++){
        //cout<<*c;

        i++;
        num+=(charToString(*c));
        if(i%8==0){

            ch1 = binaryToDecimal(stringToNum(num));
            cout<<ch1<<endl;
            num="";
        }
    }





return 0;
}
