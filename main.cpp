#include<iostream>
#include<cmath>

using namespace std;

float func(float x){
    return -15/((2-x)*(2-x)*(2-x));
}

int main(){
    int N=1000;
    for (int j=0;j<40;j++){
    double S=0,E,a=3,b=5,x=a;
    double H=(b-a)/N;
    double SPerf=6.666666666666;//Точное значение левой части

    //Левые прямоугольники
/*    for(int i=0;i<N-1;i++){
        S+=func(x)*H;
        x+=H;
    }*/

    //Метод трапеций
/*    S+=H*0.5*(func(a)+func(b));
    for(int r=0;r<N-2;r++){
        x+=H;
        S+=func(x)*H;
    }*/

    //Метод Симпсона
    for(int t=0;t<(N-2)/2;t++){
        x+=2*H;
        S+=2*func(x);
    }
    x=a+H;
    for(int y=0;y<(N-1)/2;y++){
        S+=4*func(x);
        x+=2*H;
    }
    S+=func(a)+func(b);
    S*=H/3.0;


    E=abs(SPerf-S);
    cout<<E<<endl;
    N+=1000;
}
    return 0;
}
