#include <iostream>
#include <cmath>

using namespace std;

int Factorial(int a){
    int sum = 1;
    for(int i = 0; i<=a; i++){
        sum *= a;
        a--;
    }
    return sum;
}

int MatchesInGroup(int teams){
    int GroupSum = 0;
    GroupSum = (Factorial(teams)) / (Factorial(2) * Factorial(teams - 2));
    return GroupSum;
}

int checkIfPowerOfTwo(int x){
    while(x%2==0){
        x = x/2;
    }
    return x;
}

int main(){
    int Groups = 8;
    int TeamsInGroup = 4;
    int Advance = 2;
    int DirectAdv = 0;

    int GroupStageSum = 0;
    int KnockoutCountries = (Groups*Advance)+DirectAdv;
    int KC = KnockoutCountries;
    int KnockoutMatches = 0;


    for(int i = 0; i<Groups; i++){
        GroupStageSum += MatchesInGroup(4);
    }


    while(KC>0){
        KnockoutMatches += KC/2;
        KC = KC/2;
    }

    int check = checkIfPowerOfTwo(KnockoutCountries);
    if(check != 1){
        int minKnockoutCountries = 1;
        int temp = 2;
        while(minKnockoutCountries<KnockoutCountries){
            minKnockoutCountries = minKnockoutCountries * 2;
        }
        cout<<minKnockoutCountries;
    }



    cout<<"Groups: "<<Groups<<endl;
    cout<<"Advance: "<<Advance<<endl;
    cout<<"Group Matches: "<<GroupStageSum<<endl;
    cout<<"Knockout Countries: "<<KnockoutCountries<<endl;

    cout<<KnockoutMatches+GroupStageSum<<"+";

    return 0;
}