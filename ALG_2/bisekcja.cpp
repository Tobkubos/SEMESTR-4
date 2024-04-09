#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 3) - 2 * x - 5;
}

int main(){

    double a = 2;
    double b = 3;
    double e = 0.0001;

    double x1 = (a+b)/2;

    //po podstawieniu x, funkcja == 0
    if(f(x1)==0){
        return 0;    
    }
    else{
        while(abs(a-b)<=e){
            //f(a)*f(x1)<0
            if(f(a)*f(x1)<0){
                b = x1;
            }
            else{
                //f(b)*f(x1)<0
                if(f(b)*f(x1)<0){
                    a = x1;
                }
                else{
                    cout<<"dane nieprawidlowe"<<endl;
                }
            }
        }
        x1 = (a+b)/2;
        cout << "Przyblizenie x = " << x1 << endl;
        return 0;
    }
}