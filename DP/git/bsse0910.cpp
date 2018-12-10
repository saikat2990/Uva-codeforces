#include<bits/stdc++.h>

using namespace std;

void firstInfirstOut(){

    cout<<"enter your process"<<endl;
    int pronum;
    cin>>pronum;

    string p[pronum+1];
    map<int,string>mp;

    int store[pronum+1];
    map<int,int>burst;
    cout<<"input ___  process name --> burst time --> arrival time "<<endl;
    for(int i=0;i<pronum;i++){

        string st;
        int val,arri;
        cin>>st>>val>>arri;
        burst[arri] = val;
        store[i] = arri;
        mp[arri] = st;

    }

    sort(store,store+pronum);

    int sum=burst[store[0]];

    for(int i=0;i<pronum;i++){

        if(i!=0){


            cout<<"process"<<mp[store[i]]<<" burst time ";
            cout<<burst[store[i]]<<" waiting time "<<sum-store[i]<<endl;
            sum+=burst[store[i]];

        }else{
            cout<<"process"<<mp[store[i]]<<" burst time ";
            cout<<burst[store[i]]<<" waiting time 0"<<endl;
        }
    }


}

void shortestJobFirst(){

    cout<<"enter your process"<<endl;
    int pronum;
    cin>>pronum;

    cout<<"input ___  process name --> burst time --> arrival time "<<endl;

    int p[pronum+1];
    map<int,string>mp;
    map<string,int>arrival;

    for(int i=0;i<pronum;i++){

        int val,ar;
        string str;
        cin>>str>>val>>ar;
        mp[val] = str;
        p[i] = val;
        arrival[str] = ar;
    }

    sort(p,p+pronum);
    int tatl = p[0];
    int add = arrival[mp[p[0]]];
    tatl+=add;

    for(int i=0;i<pronum;i++){

        if(i!=0){

            cout<<"process name "<<mp[p[i]]<<" burst time "<<p[i]<<" waiting time "<<tatl-arrival[mp[p[i]]]<<endl;
            tatl+=p[i];

        }else{
            cout<<"process name "<<mp[p[i]]<<" burst time  "<<p[i]<<" waiting time "<<add<<endl;
        }
    }



}

void priority(){

    cout<<"enter your process"<<endl;
    int pronum;
    cin>>pronum;

    int p[pronum+1];
    int v[pronum+1];

    map<int,string>mpp;
    map<int,int>mp;
    map<string,int>arrival;

    cout<<"input ___  process name --> burst time --> arrival time --> priority "<<endl;

    for(int i=0;i<pronum;i++){

        int val,vl,ar;
        string str;
        cin>>str>>val>>ar>>vl;
        mpp[vl] = str;
        mp[vl] = val;
        p[i] = val;
        v[i]= vl;
        arrival[str] = ar;
    }

    sort(v,v+pronum);
    reverse(v,v+pronum);
    int tatl=mp[v[0]];
    int add = arrival[mpp[v[0]]];
    tatl+=add;
    for(int i=0;i<pronum;i++){

        if(i!=0){

            cout<<"process "<<mpp[v[i]]<<" burst "<<" "<<mp[v[i]]<<" ";
            if(tatl-arrival[mpp[v[i]]]>-1)cout<<" waiting "<<tatl-arrival[mpp[v[i]]]<<endl;
            else cout<<"0"<<endl;
            tatl+=mp[v[i]];

        }else{

            cout<<"process "<<mpp[v[i]]<<" burst "<<mp[v[i]]<<" waiting "<<add<<endl;
        }
    }


}


void round(){

    cout<<"enter your process"<<endl;
    int pronum;
    cin>>pronum;
    cout<<"input ___  process name --> burst time --> arrival time "<<endl;
    int val[pronum+1];
    string str[pronum+1];
    int arr[pronum+1];

    for(int i=0;i<pronum;i++){

        cin>>str[i]>>val[i]>>arr[i];

    }
    int cn=0;
    int time[pronum+1]={0};

    while(1){

           for(int i=0;i<pronum;i++){

                val[i]-=5;
                time[i]=(time[i]+val[i]);
                if(val[i<0])val[i]=0;
                if(val[i]==0){

                    cout<<"process "<<str[i]<<" waiting "<<endl;
                    if(time[i]<0)cout<<"0"<<endl;
                    else cout<<time[i]<<endl;
                    cn++;
                    //cout<<"cn "<<cn<<endl;
                    if(cn==pronum)break;
                }

           }
           if(cn==pronum)break;
    }

}


int main(){



    cout<<"1.firstInfirstOut()"<<endl;
    cout<<"2.shortestJobFirst()"<<endl;
    cout<<"3.priority()"<<endl;
    cout<<"4.round()"<<endl<<endl;

    int ch;
    while(1){

        cout<<"choice num"<<endl;
        cin>>ch;
        if(ch==1)firstInfirstOut();
        else if(ch==2)shortestJobFirst();
        else if(ch==3)priority();
        else round();
    }

return 0;
}
/* other
3
p1 10 2
p2 5 1
p3 2 10
*/

/* priority
3
p1 10 2 5
p2 5 1  1
p3 2 10 2
*/
