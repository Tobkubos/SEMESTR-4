#include <iostream>
#include <vector>

using namespace std;


int main(){
    unsigned long long cases = 0;
    cin>>cases;

    for(int i =0; i<cases; i++){
        long long a=0;
        long long b=0;

        cin>>a>>b;

        string tempA = to_string(a);
        string tempB = to_string(b);
        long long intA = stoi(string(tempA.rbegin(), tempA.rend()));
        long long intB = stoi(string(tempB.rbegin(), tempB.rend()));
        long long intC = intA + intB;

        string tempC = to_string(intC);
        long long intSUM = stoi(string(tempC.rbegin(), tempC.rend()));
        cout<<intSUM<<endl;
    } 
    return 0;
}