#include<bits/stdc++.h>

using namespace std;

vector<char>check;

void charToBinary(char c) {

    for (int i = 7; i >= 0; --i) {

         check.push_back(((c & (1 << i))? '1' : '0'));
    }

}

int main(){


    ifstream ifile2;
    ifile2.open("compresstext.txt");
    char s1;
    while(ifile2>>s1){
        cout<<(int)s1;
        charToBinary(s1);
    }
    cout<<"decompression"<<endl;

    vector<char>:: iterator c;
    for(c = check.begin();c!=check.end();c++){
        cout<<*c;
    }

    return 0;
}
