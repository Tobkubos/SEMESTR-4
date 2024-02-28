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

int checkKnockout(int KnockoutCountries){
    int check = checkIfPowerOfTwo(KnockoutCountries);
    cout<<"check: "<<check<<endl;
    if(check != 1){
        int temp = 1;
        while(temp < KnockoutCountries){
            temp = temp*2;
        }
        cout<<"Nearest Power of two "<<temp<<endl;
        return temp;
    }
    return KnockoutCountries;
}

int AddTeams(int check, int KnockoutCountries){
    if(check ==0){return 0;}
    else{
    int neededTeamsInKnockout = check - KnockoutCountries;
    cout<<"Needed Teams in Knockout: "<<neededTeamsInKnockout<<endl;
    return neededTeamsInKnockout;
}}

int main(){
    int Groups = 8;
    int TeamsInGroup = 4;
    int Advance = 2;
    int DirectAdv = 1;

    int GroupStageMatches = 0;
    int KnockoutMatches = 0;
    int KnockoutCountries = (Groups*Advance)+DirectAdv;


    //SPRAWDZ CZY KNOCKOUT STAGE jest potęgą 2'jki
    int check = checkKnockout(KnockoutCountries);
    //Ile trzeba dodac do fazy knockout aby turniej mial sens?
    int neeededTeams = AddTeams(check, KnockoutCountries);

    int KC = check;
    GroupStageMatches = Groups * MatchesInGroup(TeamsInGroup);
    while(KC>0){
        KnockoutMatches += KC/2;
        KC = KC/2;
    }



    cout<<"Groups: "<<Groups<<endl;
    cout<<"Advance: "<<Advance<<endl;
    cout<<"Group Matches: "<<GroupStageMatches<<endl;
    cout<<"Knockout Countries: "<<KnockoutCountries<<endl;

    cout<<KnockoutMatches+GroupStageMatches<<"+"<<neeededTeams;

    return 0;
}