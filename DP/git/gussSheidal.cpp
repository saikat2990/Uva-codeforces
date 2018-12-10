#include<iostream>
#include<math.h>

using namespace std;

double fx(double y,double z){

    return ((8-2*y+2*z)/8);
}

double fy(double x,double z){

    return ((4+x+3*z)/8);
}

double fz(double x,double y){

    return ((12-2*x-y)/9);
}


int main(){

    double x0=0,y0=0,z0=0,x,y,z,eps=1.0e-6;

    while(1){

        x=fx(x0,y0);
        y=fy(x,z0);
        z=fz(x,y);

        /*
            x=fx(x0,y0);
            y=fy(x,z0);
            z=fz(x,y);
        */

        if(fabs(x-x0)<eps&&fabs(y-y0)<eps&&fabs(z-z0)<eps){
            cout<<"ans is "<<x<<","<<y<<","<<z<<endl;
            break;
        }
        else{

            x0=x;
            y0=y;
            z0=z;
        }


    }


}
