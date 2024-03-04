#include <iostream>
#include <vector>

using namespace std;

void ViewTable(int tab[], int ArraySize){
    for(int i = 0; i < ArraySize; i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
}

void HeapSort(int tab[], int ArraySize){
}

int main(){
    /*
    int ArraySize;
    cin>>ArraySize;

    int *tab = new int[ArraySize];
    */
    int tab[5] = {5,1,8,3,7};
    int ArraySize = 5;
    int i =0;
    ViewTable(tab, ArraySize);


return 0;
}

