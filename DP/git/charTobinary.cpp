#include<bits/stdc++.h>

using namespace std;

vector<char>check;

void charToBinary(char c) {

    for (int i = 7; i >= 0; --i) {

         check.push_back(((c & (1 << i))? '1' : '0'));
    }

}

int main(){

    std::string s = "hello "; // Some string.

    for (int i = 0; i < s.size(); i += 1) {
        charToBinary(s[i]);
       // std::cout << " - ";
       // printBinary(s[i + 1]);
       // std::cout << " - ";
    }

    vector<char>:: iterator it;

    for(it=check.begin();it!=check.end();it++){

        cout<<*it;
    }
}
