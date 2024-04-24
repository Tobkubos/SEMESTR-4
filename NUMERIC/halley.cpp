#include <iostream>
#include <cmath>

using namespace std;

double fun(double x) {
    return pow(x, 4) - 9 * pow(x, 3) - 15;
}

double funPrim(double x) {
    return 4 * pow(x, 3) - 27 * pow(x, 2);
}

double funBis(double x) {
    return 12 * pow(x, 2) - 54 * x;
}

int main() {
    double x0 = 6.5;
    double x1 = fun(x0);
    double e = 0.00001;
    int iteracje = 0;
    
    while (abs(fun(x1)) >= e && iteracje < 50) {
        x1 = x0 - (2 * (fun(x0) * funPrim(x0)) / (2 * funPrim(x0) * funPrim(x0) - funBis(x0) * fun(x0)));
        x0 = x1;
        iteracje++;
    }
    cout << "x: " << x1 <<"   i: "<< iteracje << endl;

    return 0;
}