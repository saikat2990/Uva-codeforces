#include<bits/stdc++.h>

using namespace std;

#define Max  99999.00

struct Point{

    int x,y;
};

int compareX( const void *a,const void *b){

    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    return (p1->x-p2->x);
}

int compareY( const void *a,const void *b){

    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    return (p1->y-p2->y);
}

float distance(Point P1,Point P2){
    return sqrt((P1.x-P2.x)*(P1.x-P2.x)+(P1.y-P2.y)*(P1.y-P2.y));
}

float bruteForse(Point P[],int n){

    float Min = (float)Max;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(distance(P[i],P[j])<Min)
                Min = distance(P[i],P[j]);
        }
    }

    return Min;
}

float sclose(Point temp[],int size,float Min){

    qsort(temp,size,sizeof(Point),compareY);
    for(int k=0;k<size;k++){
        for(int i=k+1;i<size && ((temp[k].y-temp[i].y)<Min);i++){
            if(distance(temp[k],temp[i])<Min){
                Min = distance(temp[k],temp[i]);
            }
        }
    }
    return Min;
}

float closestPair(Point P[],int n){

    if(n<=3){
        return bruteForse(P,n);
    }

    int mid = n/2;
    Point midPoint = P[mid];
    float dl = closestPair(P,mid);
    float dr = closestPair(P+mid,n-mid);
    float Min = min(dl,dr);
    int j=0;
    Point temp[n];

    for(int i=0;i<n;i++){
        if(abs(P[i].x-midPoint.x)<Min){
            temp[j]=P[i];
            j++;
        }
    }

    return min(Min,sclose(temp,j,Min));
}

int main(){

    Point P[] ={{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P)/sizeof(P[0]);
    // cout<<n<<endl;
    qsort(P,n,sizeof(Point),compareX);

    for(int i=0;i<n;i++){

        cout<<P[i].x<<" "<<P[i].y<<endl;
    }
    cout<< closestPair(P,n)<<endl;


return 0;
}

