#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int CalcTime(int h, int m, int s, int u){
    return h*360000 + 6000*m + 100*s + u;
}

void CalcArea(int time1, int time2, float radius, int num, int DeltaMax){
    int diff = time2 - time1;
    float angle = (static_cast<float>(diff) / DeltaMax) * 2 * M_PI;
    float area = (angle / 2) * (radius * radius);
    cout<<fixed<<setprecision(3)<<num+1<<". "<<area<<"\n";
}

int main(){
    int q;

    int h1;
    int m1;
    int s1;
    int u1;

    int h2;
    int m2;
    int s2;
    int u2;

    int DeltaMax = 12 * 360000;

    float radius;

    cin>>q;

    for(int i = 0; i<q; i++){
        cin>>h1>>m1>>s1>>u1;
        cin>>h2>>m2>>s2>>u2;
        cin>>radius;
            if(radius > 0 && radius <= 10000){
                if((h1 >= 0 && h1 <12) && (m1 >=0 && m1 < 60) && (s1 >=0 && s1 < 60) && (u1 >=0 && u1 <100) &&
                (   h2 >= 0 && h2 <12) && (m2 >=0 && m2 < 60) && (s2 >=0 && s2 < 60) && (u2 >=0 && u2 <100)){
                int time1 = CalcTime(h1,m1,s1,u1);
                int time2 = CalcTime(h2,m2,s2,u2);
                if(time1 < time2){
                CalcArea(time1, time2, radius, i, DeltaMax);
            }}
        }
    }
}
