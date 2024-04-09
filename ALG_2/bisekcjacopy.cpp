#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 2) - 9 * sin(x);
}

void calc(double& a, double& b, double x1, double e) {
    if (abs(a - b) > e) {
        if (f(a) * f(x1) < 0) {
            b = x1;
            x1 = (a + b) / 2; // Aktualizacja x1
            calc(a, b, x1, e);
        } else {
            if (f(b) * f(x1) < 0) {
                a = x1;
                x1 = (a + b) / 2; // Aktualizacja x1
                calc(a, b, x1, e);
            } else {
                cout << "Brak rozwiązania" << endl;
            }
        }
    } else {
        x1 = (a + b) / 2;
        cout << "x = " << x1 << endl;
    }
}

int main() {
    double a = 1;
    double b = 7;
    double e = 0.0001;

    double x1 = (a + b) / 2;

    // Po podstawieniu x, funkcja == 0
    if (f(x1) == 0) {
        cout << " x = " << x1 << endl;
        return 0;
    } else {
        calc(a, b, x1, e);
    }

    return 0;
}