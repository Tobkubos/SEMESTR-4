#include <iostream>
#include <cmath>

using namespace std;

double fun(double x) {
    return pow(x, 4) - 9 * pow(x, 3) - 15;
}

double funPrim(double x) {
    return 4 * pow(x, 3) - 27 * pow(x, 2);
}

int main() {
    double x0 = 7;
    double e = 0.00001;
    double x1 = 0;
    int iteracje = 0;

    if(abs(fun(x0))<e){
        cout<<x0;
    }

    x1 = x0 - (fun(x0) / funPrim(x0));

    while(fun(x1)>= e && iteracje < 50){
        x0 = x1;
        x1 = x0 - (fun(x0) / funPrim(x0));
        iteracje++;
    }
    cout<<x1<<" "<<iteracje;

    return 0;
}