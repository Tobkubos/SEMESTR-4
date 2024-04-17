#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
  //return pow(x,3)+4*pow(x,2)-10;
  return pow(x,4)- 9*pow(x,3) - 15;
}

double epsy = 1e-14; // Dokładność y
double a    = 2;  // Początek 
double b    = 10;  // Koniec
int n       = 64;    

int main()
{
    double fa,fb,fx,x0;
    bool result = false;
    fa = f(a);
    fb = f(b);

    if(fa * fb > 0) cout << "Funkcja nie ma różnych znaków na krańcach przedziału";
    else
    {
        result = true;

        while(true)
        {

            x0 = (fa * b - fb * a) / (fa - fb);

            if(!n) {
                break;
            }
            else{ 
                n--;
            }

            fx = f(x0);

            if(fabs(fx) < epsy) break;

            if(fa * fx < 0)
            {
                b = x0;
                fb = fx;
            }
            else
            {
                a = x0;
                fa = fx;
            }
        }
    }

    if(result){
        cout << "x = " << x0 << " iteracja = " << 64 - n <<endl;
    } 

    return 0;
} 