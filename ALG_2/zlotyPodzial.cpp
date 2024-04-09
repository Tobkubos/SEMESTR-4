#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(double x) {
    return pow(x,2)-9*sin(x);
}

void calc(int iteration, vector<double> &aTab, vector<double> &bTab, vector<double> &xLtab, vector<double> &xRtab, double k, double e) {
    if (f(xLtab[iteration]) > f(xRtab[iteration])) {
        aTab.push_back(xLtab[iteration]);
        bTab.push_back(bTab[iteration]);
        xLtab.push_back(xRtab[iteration]);
        xRtab.push_back(aTab[iteration + 1] + ((bTab[iteration + 1]) - aTab[iteration + 1]) * k);
        iteration++;
    }
    if (f(xLtab[iteration]) < f(xRtab[iteration])) {
        aTab.push_back(aTab[iteration]);
        bTab.push_back(xRtab[iteration]);
        xLtab.push_back(bTab[iteration + 1] + ((bTab[iteration + 1]) - aTab[iteration + 1]) * k);
        xRtab.push_back(xLtab[iteration]);
        iteration++;
    }
    if ((xRtab[iteration] - xLtab[iteration]) <= e) {
        double min = (aTab[iteration] + bTab[iteration]) / 2.0;
        cout << "Znalezione minimum: " << min << endl;
    } else {
        calc(iteration, aTab, bTab, xLtab, xRtab, k, e);
    }
}

int main() {
    double a = 0;
    double b = 2;
    double e = 0.0001;
    double k = 0.61803;

    vector<double> aTab;
    vector<double> bTab;
    aTab.push_back(a);
    bTab.push_back(b);

    double xL = b - (b - a) * k;
    double xR = a + (b - a) * k;
    vector<double> xLtab;
    vector<double> xRtab;
    xLtab.push_back(xL);
    xRtab.push_back(xR);

    int iteration = 0;

    if (bTab[iteration] - aTab[iteration] <= e) {
        return 0;
    } else {
        calc(iteration, aTab, bTab, xLtab, xRtab, k, e);
    }
}