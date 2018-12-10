
#include<bits/stdc++.h>
#include<sstream>

using namespace std;

struct st{
    int num1,num2;
};

void knapsack(int wt[],int val[],int W,int n,int weight[]){

    int tag[n+1];
    int arr[n+2][W+2];

    for(int i=0;i<=n;i++)tag[i]=false;

    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(i==0 || w==0)arr[i][w]=0;
            else if(w>=wt[i-1]){
                arr[i][w]=max(val[i-1]+arr[i-1][w-wt[i-1]],arr[i-1][w]);
            }
            else {
                arr[i][w]=arr[i-1][w];
            }
        }
    }

    int index=W;
    ofstream ofile;
    ofile.open("hellobro1.txt",fstream::app);
    stack<st>vec;

    for(int i=n;i>0;i--){
        if(arr[i][index]!=arr[i-1][index]){
                index = index-wt[i-1];
                st war;
                war.num1 = weight[i-1];
                war.num2 = val[i-1];
                vec.push(war);
        }
    }

    ofile<<arr[n][W]<<endl;
    ofile<<vec.size()<<endl;
    /*for(int i=0;i<vec.size();i++){
        ofile<<vec[i].num1<<" "<<vec[i].num2<<endl;
    };*/
    while(!vec.empty()){
        st temp ;
        temp= vec.top();
        vec.pop();
        ofile<<temp.num1<<" "<<temp.num2<<endl;

    }
        ofile<<endl;
        //cout<<" "<<endl;

}

int main(){

    string str;
    getline(cin,str);

    while(str.length()!=0){

        stringstream iss;
        iss<<str;
        int a[2];
        int h=0;

        while(iss>>a[h]){
            h++;
        }

        int m;
        cin>>m;
        int val[m],wt[m];
        int s,weight[m];
        for(int i=0;i<m;i++){
            cin>>s>>val[i];
            //sum+=val[i];
            weight[i]=s;
            wt[i]=3*a[1]*s;

        }
        int W ;
        W=a[0];
        int n = (sizeof(val)/sizeof(val[0]));
        //cout<<n<<endl;
        knapsack(wt, val, W,n,weight);
        getline(cin,str);
        getline(cin,str);
        getline(cin,str);
    }

return 0;
}
