#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

const double EPS0 = 0.0000000001;
const double EPSX = 0.0000000001;

double f(double x)
{
  //return pow(x,3)+4*pow(x,2)-10;
  return pow(x,4)- 9*pow(x,3) - 15;
}
int main()
{

  double x0,x1,x2,f0,f1,f2;
  int i;

  x1 = 5;
  x2 = 10;

  f1 = f(x1); f2 = f(x2); i = 64;
  while(i > 0 && (fabs(x1 - x2) > EPSX))
  {
    if(fabs(f1 - f2) < EPS0)
    {
      cout << "Zle punkty";
      i = 0;
      break;
    }

    x0 = x1 - f1 * (x1 - x2) / (f1 - f2);
    f0 = f(x0);

    if(fabs(f0) < EPS0){ 
        break;
    }
    x2 = x1; f2 = f1;
    x1 = x0; f1 = f0;
    if(!(--i)){
     cout << "Przekroczony limit obiegow";
     cout << "x0 = " << x0 << endl;
    }  
  }
  if(i) cout << "x0 = " << x0 << endl;
  return 0;
}
 