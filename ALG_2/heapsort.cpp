#include <iostream>

using namespace std;


int main(){
    int ArraySize;
    cin>>ArraySize;

    int *tab = new int[ArraySize];
    for(int i = 0; i< ArraySize; i++){
        cin>>tab[i];
    }

    for(int i = 0; i<ArraySize; i++){
        cout<<tab[i]<<" ";
    }

return 0;
}