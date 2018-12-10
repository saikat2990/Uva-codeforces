#include<bits/stdc++.h>

using namespace std;

struct behave{

    string name,len;
    bool tag;
};

int main(){

    int n;
    cin>>n;
    behave arr[n];
    int h=0;

    for(int i=0;i<n;i++){
        string str1,str2;

        cin>>str1>>str2;
        int l = str2.length();

        for(int j=0;j<n;j++){

            if(arr[h].tag==false){
                l--;
                if(l==1){
                    node temp;
                    temp.name = str1;
                    temp.len = str2;
                    temp.tag = true;
                    arr[h] = temp;
                }

            }
            h++;
            if(h==12)h=0;

        }

    }

    for(int i=0;i<n;i++){
        cout<<arr[i].name<<" ";
    }


return 0;
}
