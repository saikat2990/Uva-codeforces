
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int edit_Dis(string str1,string str2, int m,int n){

    if(m==0)return n;

    else if(n==0)return m;

    else if(str1[m-1]==str2[n-1])return edit_Dis(str1,str2,m-1,n-1);

    return 1+ min( min( edit_Dis(str1,str2,m,n-1),       //insert
                        edit_Dis(str1,str2,m-1,n)       //remove
                       ),
                   edit_Dis(str1,str2,m-1,n-1)    //replace
                 );

}

int main(){

    string str1,str2;
    cin>>str1>>str2;
    int m,n;
    m=str1.length();
    n=str2.length();

    cout<<edit_Dis(str1,str2,m,n);

    return 0;
}
