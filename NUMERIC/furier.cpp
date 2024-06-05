#include <iostream>
#include <vector>

using namespace std;

int main(){

    double a;
    double b;
    double dx; 
    double x;
    double N;

    double a0 = 2;
    vector<double> an;
    vector<double> bn;

    double result = a0/2;

    for(int i - 0; i<=N; i++){
        result += an[i]*cos(i*x)+bn[i]*sin(i*x);
    }
    cout<<result;
    return 0;
}