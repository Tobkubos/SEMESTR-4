#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return 1/x;
}

void Milne(double aIn, double bIn)
{
    double h =(bIn-aIn)/4.;

    double x0 = aIn + 1 * h;
    double x1 = aIn + 2 * h;
    double x2 = aIn + 3 * h;

    
    cout<<x0<<" "<<f(x0)<<endl;
    cout<<x1<<" "<<f(x1)<<endl;
    cout<<x2<<" "<<f(x2)<<endl;
    

    double Milne_result = (bIn - aIn)*(f(x0)*(2./3.)+f(x1)*(-1./3.) + f(x2)*(2./3.));

    cout << "wynik Milne: " << Milne_result << endl;
}
void Weddle(double aIn, double bIn)
{
    double a = aIn;
    double b = bIn;
    double inter = (b-a)/6;

    double x0 = a;
    double x1 = a + inter;
    double x2 = a + (2 * inter);
    double x3 = a + (3 * inter);
    double x4 = a + (4 * inter);
    double x5 = a + (5 * inter);
    double x6 = a + (6 * inter);

    cout<<f(x0)<<endl;
    cout<<f(x1)<<endl;
    cout<<f(x2)<<endl;
    cout<<f(x3)<<endl;
    cout<<f(x4)<<endl;
    cout<<f(x5)<<endl;
    cout<<f(x6)<<endl;

    double Weddle_result = (bIn - aIn)*((41./840.)*f(x0) + (216./840.)*f(x1) + (27./840.)*f(x2) + (272./840.)*f(x3) + (27./840.)*f(x4) + (216./840.)*f(x5) + (41./840.)*f(x6));

    cout << "wynik Weddle: " << Weddle_result << endl;
}

int main()
{
    Milne(1,2);
    Weddle(1,2);

    return 0;
}