#include<bits/stdc++.h>
#include<string>
#include<graphics.h>

using namespace std;

struct indicator{

    int x,y;
    bool flagCom,flagPer,flag;
    string str;

};

int circle1=0,circle2=0,circle3=0,circle4=0,circle5=0,circle6=0,circle7=0,circle8=0,circle9=0;
int box1=0,box2=0,box3=0,box4=0,box5=0,box6=0,box7=0,box8=0,box9=0;
vector<int>vec;
 bool tag=false;
      int indexX,indexY,temp1,temp2;
     bool middletag=false,otherMiddletag=false,middletag1=false,otherMiddletag1=false;
     bool test=false;

string NumtoString(int num){

    stringstream iss;
    iss<<num;
    string s;
    iss>>s;
    return s;

}


void disPlay(){
    int gd  = DETECT;
    int gm;
    char* s = "c:\\TC\\BGI";

    initgraph(&gd,&gm,s);

    //circle(200,300,34);

    line(500,180,500,650);
    line(700,180,700,650);
    line(350,300,840,300);
    line(350,500,840,500);

    if(circle1==1)
        circle(400,200,38);
    if(circle4==1)
        circle(400,400,38);
    if(circle7==1)
        circle(400,600,38);
    if(circle2==1)
        circle(600,200,38);
    if(circle5==1)
        circle(600,400,38);
    if(circle8==1)
        circle(600,600,38);
    if(circle3==1)
        circle(800,200,38);
    if(circle6==1)
        circle(800,400,38);
    if(circle9==1)
        circle(800,600,38);

    if(box1==1){
        line(358,122,448,285);
        line(458,122,358,285);
    }
    if(box2==1){
        line(558,122,648,285);
        line(648,122,558,285);
    }
    if(box3==1){
        line(758,122,848,285);
        line(758,285,848,122);
    }
    if(box4==1){
        line(358,322,448,485);
        line(358,485,448,322);
    }
    if(box5==1){
        line(558,322,648,485);
        line(558,485,648,322);
    }
     if(box6==1){
        line(758,322,848,485);
        line(758,485,848,322);
     }

    if(box7==1){
        line(358,522,448,685);
        line(358,685,448,522);
    }
    if(box8==1){
        line(558,522,648,685);
        line(558,685,648,522);
    }
    if(box9==1){
        line(758,522,848,685);
        line(758,685,848,522);
    }


    //delay(660);
    //cleardevice();



}
indicator arr[3][3];

void func(){
///computer
/// row
                if(arr[0][2].flagCom==true&&arr[0][0].flagCom==true&&arr[0][1].flag==false){
                    indexX=1,indexY=2;
                }
                else if(arr[0][1].flagCom==true&&arr[0][0].flagCom==true&&arr[0][2].flag==false){
                     indexX=1,indexY=3;
                }
                else if(arr[0][1].flagCom==true&&arr[0][2].flagCom==true&&arr[0][0].flag==false){
                    indexX=1,indexY=1;
                }


                else if(arr[1][2].flagCom==true&&arr[1][0].flagCom==true&&arr[1][1].flag==false){
                    indexX=2,indexY=2;
                }
                else if(arr[1][1].flagCom==true&&arr[1][0].flagCom==true&&arr[1][2].flag==false){
                     indexX=2,indexY=3;
                }
                else if(arr[1][1].flagCom==true&&arr[1][2].flagCom==true&&arr[1][0].flag==false){
                    indexX=2,indexY=1;
                }


                else if(arr[2][2].flagCom==true&&arr[2][0].flagCom==true&&arr[2][1].flag==false){
                    indexX=3,indexY=2;
                }
                else if(arr[2][1].flagCom==true&&arr[2][0].flagCom==true&&arr[2][2].flag==false){
                     indexX=3,indexY=3;
                }
                else if(arr[2][1].flagCom==true&&arr[2][2].flagCom==true&&arr[2][0].flag==false){
                    indexX=3,indexY=1;
                }
/// column
                else if(arr[0][0].flagCom==true&&arr[1][0].flagCom==true&&arr[2][0].flag==false){
                    indexX=3,indexY=1;
                }
                else if(arr[0][0].flagCom==true&&arr[2][0].flagCom==true&&arr[1][0].flag==false){
                    indexX=2,indexY=1;
                }
                else if(arr[1][0].flagCom==true&&arr[2][0].flagCom==true&&arr[0][0].flag==false){
                    indexX=1,indexY=1;
                }


                else if(arr[0][1].flagCom==true&&arr[1][1].flagCom==true&&arr[2][1].flag==false){
                    indexX=3,indexY=2;
                }
                else if(arr[0][1].flagCom==true&&arr[2][1].flagCom==true&&arr[1][1].flag==false){
                    indexX=2,indexY=2;
                }
                else if(arr[1][1].flagCom==true&&arr[2][1].flagCom==true&&arr[0][1].flag==false){
                    indexX=1,indexY=2;
                }


                else if(arr[0][2].flagCom==true&&arr[1][2].flagCom==true&&arr[2][2].flag==false){
                    indexX=3,indexY=3;
                }
                else if(arr[0][2].flagCom==true&&arr[2][2].flagCom==true&&arr[1][2].flag==false){
                    indexX=2,indexY=3;
                }
                else if(arr[1][2].flagCom==true&&arr[2][2].flagCom==true&&arr[0][2].flag==false){
                    indexX=1,indexY=3;
                }
/// diagonal

                else if(arr[0][0].flagCom==true&&arr[1][1].flagCom==true&&arr[2][2].flag==false){
                    indexX=3,indexY=3;
                }
                else if(arr[1][1].flagCom==true&&arr[2][2].flagCom==true&&arr[0][0].flag==false){
                    indexX=1,indexY=1;
                }
                else if(arr[0][0].flagCom==true&&arr[2][2].flagCom==true&&arr[1][1].flag==false){
                    indexX=2,indexY=2;
                }

                else if(arr[0][2].flagCom==true&&arr[1][1].flagCom==true&&arr[2][0].flag==false){
                    indexX=3,indexY=1;
                }
                else if(arr[2][0].flagCom==true&&arr[1][1].flagCom==true&&arr[0][2].flag==false){
                    indexX=1,indexY=3;
                }
                else if(arr[0][2].flagCom==true&&arr[2][0].flagCom==true&&arr[1][1].flag==false){
                    indexX=2,indexY=2;
                }


///Person
/// row
                else if(arr[0][2].flagPer==true&&arr[0][0].flagPer==true&&arr[0][1].flag==false){
                    indexX=1,indexY=2;
                }
                else if(arr[0][1].flagPer==true&&arr[0][0].flagPer==true&&arr[0][2].flag==false){
                     indexX=1,indexY=3;
                }
                else if(arr[0][1].flagPer==true&&arr[0][2].flagPer==true&&arr[0][0].flag==false){
                    indexX=1,indexY=1;
                }


                else if(arr[1][2].flagPer==true&&arr[1][0].flagPer==true&&arr[1][1].flag==false){
                    indexX=2,indexY=2;
                }
                else if(arr[1][2].flagPer==true&&arr[1][0].flagPer==true&&arr[1][1].flag==false){
                     indexX=2,indexY=3;
                }
                else if(arr[1][1].flagPer==true&&arr[1][2].flagPer==true&&arr[1][0].flag==false){
                    indexX=2,indexY=1;
                }


                else if(arr[2][2].flagPer==true&&arr[2][0].flagPer==true&&arr[2][1].flag==false){
                    indexX=3,indexY=2;
                }
                else if(arr[2][1].flagPer==true&&arr[2][0].flagPer==true&&arr[2][2].flag==false){
                     indexX=3,indexY=3;
                }
                else if(arr[2][1].flagPer==true&&arr[2][2].flagPer==true&&arr[2][0].flag==false){
                    indexX=3,indexY=1;
                }
/// column
                else if(arr[0][0].flagPer==true&&arr[1][0].flagPer==true&&arr[2][0].flag==false){
                    indexX=3,indexY=1;
                }
                else if(arr[0][0].flagPer==true&&arr[2][0].flagPer==true&&arr[1][0].flag==false){
                    indexX=2,indexY=1;
                }
                else if(arr[1][0].flagPer==true&&arr[2][0].flagPer==true&&arr[0][0].flag==false){
                    indexX=1,indexY=1;
                }


                else if(arr[0][1].flagPer==true&&arr[1][1].flagPer==true&&arr[2][1].flag==false){
                    indexX=3,indexY=2;
                }
                else if(arr[0][1].flagPer==true&&arr[2][1].flagPer==true&&arr[1][1].flag==false){
                    indexX=2,indexY=2;
                }
                else if(arr[1][1].flagPer==true&&arr[2][1].flagPer==true&&arr[0][1].flag==false){
                    indexX=1,indexY=2;
                }


                else if(arr[0][2].flagPer==true&&arr[1][2].flagPer==true&&arr[2][2].flag==false){
                    indexX=3,indexY=3;
                }
                else if(arr[0][2].flagPer==true&&arr[2][2].flagPer==true&&arr[1][2].flag==false){
                    indexX=2,indexY=3;
                }
                else if(arr[1][2].flagPer==true&&arr[2][2].flagPer==true&&arr[0][2].flag==false){
                    indexX=1,indexY=3;
                }
/// diagonal

                else if(arr[0][0].flagPer==true&&arr[1][1].flagPer==true&&arr[2][2].flag==false){
                    indexX=3,indexY=3;
                }
                else if(arr[1][1].flagPer==true&&arr[2][2].flagPer==true&&arr[0][0].flag==false){
                    indexX=1,indexY=1;
                }
                else if(arr[0][0].flagPer==true&&arr[2][2].flagPer==true&&arr[1][1].flag==false){
                    indexX=2,indexY=2;
                }

                else if(arr[0][2].flagPer==true&&arr[1][1].flagPer==true&&arr[2][0].flag==false){
                    indexX=3,indexY=1;
                }
                else if(arr[2][0].flagPer==true&&arr[1][1].flagPer==true&&arr[0][2].flag==false){
                    indexX=1,indexY=3;
                }
                else if(arr[0][2].flagPer==true&&arr[2][0].flagPer==true&&arr[1][1].flag==false){
                    indexX=2,indexY=2;
                }
                else{
                    while(1){
                        cout<<"its okay"<<endl;
                        indexX = (rand()%3)+1;
                        indexY = (rand()%3)+1;
                        if(arr[indexX-1][indexY-1].flag==false){
                                cout<<"its okay"<<endl;
                                break;
                        }

                    }

                }

}

int main(){

     //disPlay();
    ifstream ifile;
    ifile.open("tic.txt");

    string name1,name2;
    cout<<"enter player Name"<<endl;

    ifile>>name1>>name2;



    int l=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            indicator temp;
            temp.x = i+1;
            temp.y = j+1;
            temp.flag = false;
            temp.flagCom=false;
            temp.flagPer=false;
           // int a = 10;
            //char *intStr = itoa(j);
            string st = NumtoString(l);
            l++;
            //cout<<st<<endl;
            temp.str=""+st ;
            arr[i][j] = temp;
        }
    }

    cout<<endl<<endl;


     cout<<"1.if you want first move from computer press 1"<<endl;
     cout<<"2.if you want  first move from you press 2"<<endl;

     int need;
     cin>>need;
     bool press1=false,press2=false;

     if(need==1)press1=true;
     else press2=true;


    if(press1==1){
        for(int k=0;k<9;k++){

        Again:

            if(k==0){
                    //cout<<"its time for player1 "<<name1<<endl;
                    indexX = 2;
                    indexY = 2;

            }
            else if(k%2==0){

                //cout<<"value"<<k<<endl;
                if(k==2){

                    ///at the middle point
                    if(temp1==1&&temp2==2 || temp1==3&&temp2==2||
                       temp1==2&&temp2==1 || temp1==2&&temp2==3){
                            indexX=1;
                            indexY=1;
                            if(temp1==1&&temp2==2 || temp1==3&&temp2==2)
                                middletag=true;
                            if(temp1==2&&temp2==1 || temp1==2&&temp2==3)
                                 middletag1=true;

                            //cout<<"middletag"<<endl;
                        }

                    ///other point
                    else {
                        test=true;
                        while(1){

                            indexX = (rand()%3)+1;
                            indexY = (rand()%3)+1;
                            if(arr[indexX-1][indexY-1].flag==false){
                                    //cout<<"its okay"<<endl;
                                    break;
                            }

                        }

                    }

                }
                else if(k==4 && middletag==true && otherMiddletag==true){
                      indexX=3;
                      indexY=1;
                      //cout<<" all true "<<endl;

                }
                else if(k==4 && middletag1==true && otherMiddletag==true){
                      indexX=1;
                      indexY=3;
                      //cout<<" all true "<<endl;

                }
                ///optimization

                else{

                    func();
                }

            }
            else {
                cout<<"its your turn "<<k<<endl;


                cin>>indexX>>indexY;
                cout<<"----------->"<<k<<endl;
                if(k==3 && test!=true){
                    if(indexX==3&&indexY==3){
                        otherMiddletag=true;
                        cout<<"its time for othermiddletag"<<endl;
                    }
                }
            }

            if(k%2==0){

                if(indexX==1&&indexY==1){box1=1;vec.push_back(box1);}
                else if(indexX==1&&indexY==2){box2=1;vec.push_back(box2);}
                else if(indexX==1&&indexY==3){box3=1;vec.push_back(box3);}
                else if(indexX==2&&indexY==1){box4=1;vec.push_back(box4);}
                else if(indexX==2&&indexY==2){box5=1;vec.push_back(box5);}
                else if(indexX==2&&indexY==3){box6=1;vec.push_back(box6);}
                else if(indexX==3&&indexY==1){box7=1;vec.push_back(box7);}
                else if(indexX==3&&indexY==2){box8=1;vec.push_back(box8);}
                else if(indexX==3&&indexY==3){box9=1;vec.push_back(box9);}

            }
            else {


                if(indexX==1&&indexY==1){circle1=1; vec.push_back(circle1);}
                else if(indexX==1&&indexY==2){circle2=1;vec.push_back(circle2);}
                else if(indexX==1&&indexY==3){circle3=1;vec.push_back(circle3);}
                else if(indexX==2&&indexY==1){circle4=1;vec.push_back(circle4);}
                else if(indexX==2&&indexY==2){circle5=1;vec.push_back(circle5);}
                else if(indexX==2&&indexY==3){circle6=1;vec.push_back(circle6);}
                else if(indexX==3&&indexY==1){circle7=1;vec.push_back(circle7);}
                else if(indexX==3&&indexY==2){circle8=1;vec.push_back(circle8);}
                else if(indexX==3&&indexY==3){circle9=1;vec.push_back(circle9);}


            }

            //cout<<indexX<<"  "<<indexY<<endl;
            if(arr[indexX-1][indexY-1].flag==true){
                //cout<<"you cannot do it"<<endl;
                //k--;
                //continue;
                goto Again;
            }

            arr[indexX-1][indexY-1].flag=true;
            //cout<<indexX-1<<"   "<<indexY-1<<endl;

            if(k%2==0){
                arr[indexX-1][indexY-1].flagCom=true;
            }else{
                arr[indexX-1][indexY-1].flagPer=true;
            }


            if(k%2==0) arr[indexX-1][indexY-1].str = name1;
            else  arr[indexX-1][indexY-1].str = name2;

            //if(k!=8)system("cls");

            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(arr[i][j].flag==true){
                        if(j==0)cout<<"        ";
                        cout<<"  "<<arr[i][j].str<<" |";
                    }
                    else{
                        if(j==0)cout<<"        ";
                        cout<<"  "<<arr[i][j].x<<","<<arr[i][j].y<<" |";
                    }
                }
                cout<<endl;
                if(i!=2)cout<<"          ----- -----  ------"<<endl;
            }
            cout<<endl;
            //disPlay();




            if(arr[0][0].str==arr[0][1].str && arr[0][1].str==arr[0][2].str && arr[0][0].str==arr[0][2].str)
                { tag = true; cout<<endl<<arr[0][0].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[0][0].str==arr[1][1].str && arr[1][1].str==arr[2][2].str && arr[0][0].str==arr[2][2].str){
                 tag = true;  cout<<endl<<arr[2][2].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[0][0].str==arr[1][0].str && arr[1][0].str==arr[2][0].str && arr[0][0].str==arr[2][0].str){
                tag = true;  cout<<endl<<arr[2][0].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[0][1].str==arr[1][1].str && arr[1][1].str==arr[2][1].str && arr[0][1].str==arr[2][1].str){
                tag = true;  cout<<endl<<arr[0][1].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[0][2].str==arr[1][2].str && arr[1][2].str==arr[2][2].str && arr[0][2].str==arr[2][2].str){
                tag = true;  cout<<endl<<arr[2][2].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[0][2].str==arr[1][1].str && arr[1][1].str==arr[2][0].str && arr[0][2].str==arr[2][0].str){
                tag = true;  cout<<endl<<arr[2][0].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[1][0].str==arr[1][1].str && arr[1][1].str==arr[1][2].str && arr[1][0].str==arr[1][2].str ){
                tag = true; cout<<endl<<arr[1][2].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[2][0].str==arr[2][1].str && arr[2][1].str==arr[2][2].str && arr[2][0].str==arr[2][2].str){
                tag = true; cout<<endl<<arr[2][2].str<<"  is winner "<<endl; disPlay(); break;}


            if(k==1)temp1 = indexX,temp2 = indexY;
        }
    }
    else {


        for(int k=0;k<9;k++){

        //Again:

            if(k%2==0){

                cin>>indexX>>indexY;

            }
            else{
                func();
            }


            if(k%2==0){

                if(indexX==1&&indexY==1){box1=1;vec.push_back(box1);}
                else if(indexX==1&&indexY==2){box2=1;vec.push_back(box2);}
                else if(indexX==1&&indexY==3){box3=1;vec.push_back(box3);}
                else if(indexX==2&&indexY==1){box4=1;vec.push_back(box4);}
                else if(indexX==2&&indexY==2){box5=1;vec.push_back(box5);}
                else if(indexX==2&&indexY==3){box6=1;vec.push_back(box6);}
                else if(indexX==3&&indexY==1){box7=1;vec.push_back(box7);}
                else if(indexX==3&&indexY==2){box8=1;vec.push_back(box8);}
                else if(indexX==3&&indexY==3){box9=1;vec.push_back(box9);}

            }
            else {


                if(indexX==1&&indexY==1){circle1=1; vec.push_back(circle1);}
                else if(indexX==1&&indexY==2){circle2=1;vec.push_back(circle2);}
                else if(indexX==1&&indexY==3){circle3=1;vec.push_back(circle3);}
                else if(indexX==2&&indexY==1){circle4=1;vec.push_back(circle4);}
                else if(indexX==2&&indexY==2){circle5=1;vec.push_back(circle5);}
                else if(indexX==2&&indexY==3){circle6=1;vec.push_back(circle6);}
                else if(indexX==3&&indexY==1){circle7=1;vec.push_back(circle7);}
                else if(indexX==3&&indexY==2){circle8=1;vec.push_back(circle8);}
                else if(indexX==3&&indexY==3){circle9=1;vec.push_back(circle9);}


            }

            cout<<indexX<<"  "<<indexY<<endl;
            if(arr[indexX-1][indexY-1].flag==true){
                cout<<"you cannot do it"<<endl;
                //k--;
                continue;
                //goto Again;
            }

            arr[indexX-1][indexY-1].flag=true;
            cout<<indexX-1<<"   "<<indexY-1<<endl;

            if(k%2==0){
                arr[indexX-1][indexY-1].flagCom=true;
            }else{
                arr[indexX-1][indexY-1].flagPer=true;
            }


            if(k%2==0) arr[indexX-1][indexY-1].str = name1;
            else  arr[indexX-1][indexY-1].str = name2;

            //if(k!=8)system("cls");

            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(arr[i][j].flag==true){
                        if(j==0)cout<<"        ";
                        cout<<"  "<<arr[i][j].str<<" |";
                    }
                    else{
                        if(j==0)cout<<"        ";
                        cout<<"  "<<arr[i][j].x<<","<<arr[i][j].y<<" |";
                    }
                }
                cout<<endl;
                if(i!=2)cout<<"          ----- -----  ------"<<endl;
            }
            //disPlay();




            if(arr[0][0].str==arr[0][1].str && arr[0][1].str==arr[0][2].str && arr[0][0].str==arr[0][2].str)
                { tag = true; cout<<endl<<arr[0][0].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[0][0].str==arr[1][1].str && arr[1][1].str==arr[2][2].str && arr[0][0].str==arr[2][2].str){
                 tag = true;  cout<<endl<<arr[2][2].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[0][0].str==arr[1][0].str && arr[1][0].str==arr[2][0].str && arr[0][0].str==arr[2][0].str){
                tag = true;  cout<<endl<<arr[2][0].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[0][1].str==arr[1][1].str && arr[1][1].str==arr[2][1].str && arr[0][1].str==arr[2][1].str){
                tag = true;  cout<<endl<<arr[0][1].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[0][2].str==arr[1][2].str && arr[1][2].str==arr[2][2].str && arr[0][2].str==arr[2][2].str){
                tag = true;  cout<<endl<<arr[2][2].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[0][2].str==arr[1][1].str && arr[1][1].str==arr[2][0].str && arr[0][2].str==arr[2][0].str){
                tag = true;  cout<<endl<<arr[2][0].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[1][0].str==arr[1][1].str && arr[1][1].str==arr[1][2].str && arr[1][0].str==arr[1][2].str ){
                tag = true; cout<<endl<<arr[1][2].str<<"  is winner "<<endl; disPlay(); break;}
            else if(arr[2][0].str==arr[2][1].str && arr[2][1].str==arr[2][2].str && arr[2][0].str==arr[2][2].str){
                tag = true; cout<<endl<<arr[2][2].str<<"  is winner "<<endl; disPlay(); break;}


        }
    }


    if(tag==false){
            cout<<"match draw"<<endl;
            disPlay();
    }
    getch();
    closegraph();

return 0;
}
