#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int CalcTime(int h, int m, int s, int u){
    return h*360000 + 6000*m + 100*s + u;
}

void CalcArea(int time1, int time2, float radius){
    int diff = time2 - time1;
    int DeltaMax = 12 * 360000; 
    float angle = (static_cast<float>(diff) / DeltaMax) * 2 * M_PI;
    float area = (angle / 2) * (radius * radius); 
    // cout<<"ANGLE: "<<angle<<"\n";
    // cout<<"AREA: "<<area<<"\n";
    cout<<fixed<<setprecision(3)<<area<<"\n";
}

int main(){
    int h1;
    int m1;
    int s1;
    int u1;

    int h2;
    int m2;
    int s2;
    int u2;

    float radius;

    cout<<"Insert data"<<endl;
    cin>>h1>>m1>>s1>>u1;
    cin>>h2>>m2>>s2>>u2;
    cin>>radius;
        if(radius > 0 && radius < 10000){
            int time1 = CalcTime(h1,m1,s1,u1);
            int time2 = CalcTime(h2,m2,s2,u2);
            CalcArea(time1, time2, radius);
        }
        else{
            cout<<"too big radius";
        }
}














//kat miedzy dwoma wskazowkami zegara
// u = 10^-6 ale nie w tym przypadku 


//CO ZROBIC?:
//policzyc roznice czasu miedzy zegarami
//3600 * h + 60 * m + s + u/100
//360000 * h + 6000 * m + 100s + u

//t1 = ten czas co wyzej liczymy
//t2 --//--

//roznica czasu = t2-t1

//kat = ((t2 - t1) / deltaTmax ) *2pi

//pole wycinka
//POLE =  pi * r^2 * kąt/2pi = kat/2 * r^2 

//wynik do trzech liczb znaczacych
