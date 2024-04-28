#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    return 1 / x * 3 * x * 12 * x;
}

void Milne()
{
    double a = 1;
    double b = 2;
    double h = (b - a) / 4;

    double x0 = a;
    double x1 = a + h;
    double x2 = a + 2 * h;
    double x3 = a + 3 * h;
    double x4 = a + 4 * h;

    double Milne_result = (2 * h / 45) * (7 * f(x0) + 32 * f(x1) + 12 * f(x2) + 32 * f(x3) + 7 * f(x4));

    cout << "a " << a << endl;
    cout << "b " << b << endl;
    cout << "x0 " << x0 << endl;
    cout << "x1 " << x1 << endl;
    cout << "x2 " << x2 << endl;
    cout << "x3 " << x3 << endl;
    cout << "x4 " << x4 << endl;

    cout << "wynik Milne: " << Milne_result << endl;
}
void Weddle()
{
    double a = 1;
    double b = 2;
    double h = (b - a) / 6;

    double x0 = a;
    double x1 = a + h;
    double x2 = a + 2 * h;
    double x3 = a + 3 * h;
    double x4 = a + 4 * h;
    double x5 = a + 5 * h;
    double x6 = a + 6 * h;

    double Weddle_result = (3 * h / 10) * (f(x0) + 5 * f(x1) + f(x2) + 6 * f(x3) + f(x4) + 5 * f(x5) + f(x6));

    cout << "a " << a << endl;
    cout << "b " << b << endl;
    cout << "x0 " << x0 << endl;
    cout << "x1 " << x1 << endl;
    cout << "x2 " << x2 << endl;
    cout << "x3 " << x3 << endl;
    cout << "x4 " << x4 << endl;
    cout << "x5 " << x5 << endl;
    cout << "x6 " << x6 << endl;

    cout << "wynik Weddle: " << Weddle_result << endl;
}
int main()
{
    Milne();
    Weddle();

    return 0;
}