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

bool checkIfPowerOfTwo(int GroupStage){
    return 0;
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


    while(KnockoutCountries>0){
        KnockoutMatches += KnockoutCountries/2;
        KnockoutCountries = KnockoutCountries/2;
    }

    cout<<"Groups: "<<Groups<<endl;
    cout<<"Advance: "<<Advance<<endl;
    cout<<"Group Matches: "<<GroupStageSum<<endl;
    cout<<"Knockout Countries: "<<KC<<endl;

    cout<<KnockoutMatches+GroupStageSum<<"+";

    return 0;
}