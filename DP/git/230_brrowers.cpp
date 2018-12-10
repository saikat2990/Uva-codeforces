#include<bits/stdc++.h>

using namespace std;

struct book{

    string name,author;

   bool operator<(const book &another)const{

        if(author < another.author){
            return author < another.author;
        }
        else{
            return name<another.name;
        }
    }

};

int main(){

    vector<book>vec;


    while(1){

        string nam,author,str;
        nam ="";
        bool tag =false;

        while(cin>>str){

            if(str=="END"){

                tag = true;
                break;

            }
            nam+=str;
            if(str[str.length()-1]=='"')break;
            nam+=" ";


        }

        if(tag==true)break;

        cin>>str;
        cin.ignore();

        getline(cin,str);
        cout<<nam<<str;

        book temp;
        temp.author = str;
        temp.name = nam;

        vec.push_back(temp);

    }



            sort(vec.begin(),vec.end());
            vector<book>:: iterator it;
            for(it = vec.begin();it!= vec.end();it++){
                book kp = *it;
                cout<<"lol"<<kp.author<<endl;
            }


    stack<book>st;


    while(1){

        string str,nm;
        cin>>str;
        if(str=="END")break;

        if(str=="RETURN"){

            cin.ignore();
            getline(cin,nm);

            for(it=vec.begin();it!=vec.end();it++){

                book temp;
                temp = *it;

                if(temp.name == nm){
                    cout<<"   "<<temp.author<<endl;
                    st.push(temp);
                    break;
                }

            }

            vec.erase(it);

        }

        else if("SHELVE"){

            book temp = st.top();
            st.pop();

            vec.push_back(temp);
            sort(vec.begin(),vec.end());
            for(it = vec.begin();it!= vec.end();++it){
                book kp = *it;
                cout<<kp.author<<endl;
            }

            /*for(it = vec.begin();it!= vec.end();++it){

                    book kp = *it;

                if(kp.name==temp.name){

                    if(it == vec.begin()){
                        cout<<"at the beginning "<<endl;
                    }

                    it = it-1;
                    book h = *it;
                    cout<<" put "<<kp.name<<" after "<<temp.name<<endl;
                    break;
                }
            }*/


        }
        else{

            string strr;
            cin>>strr;
        }

    }

        while(!st.empty()){

            book temp = st.top();
            st.pop();

            vec.push_back(temp);
            sort(vec.begin(),vec.end());

            for(it = vec.begin();it!= vec.end();++it){

                    book kp = *it;

                if(kp.name==temp.name){

                    if(it == vec.begin()){
                        cout<<"at the beginning "<<endl;
                    }

                    it = it-1;
                    book h = *it;
                    cout<<" put "<<kp.name<<" after "<<temp.name<<endl;
                    break;
                }
            }

        }

}
