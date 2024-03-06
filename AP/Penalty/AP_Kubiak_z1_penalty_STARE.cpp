#include <iostream>
#include <cmath>

using namespace std;

long MatchesInGroup(long teams){
    long GroupSum = (teams * (teams-1))/2;
    return GroupSum;
}

long checkIfPowerOfTwo(long x){
    while(x%2==0){
        x = x/2;
    }
    return x;
}

long checkKnockout(long KnockoutCountries){
    long check = checkIfPowerOfTwo(KnockoutCountries);
    //cout<<"check: "<<check<<endl;
    if(check != 1){
        long temp = 1;
        while(temp < KnockoutCountries){
            temp = temp*2;
        }
        //cout<<"Nearest Power of two "<<temp<<endl;
        return temp;
    }
    return KnockoutCountries;
}

long AddTeams(long check, long KnockoutCountries){
    if(check ==0){return 0;}
    else{
    long neededTeamsInKnockout = check - KnockoutCountries;
    //cout<<"Needed Teams in Knockout: "<<neededTeamsInKnockout<<endl;
    return neededTeamsInKnockout;
}}

int main(){
    long Groups;
    long TeamsInGroup;
    long Advance;
    long DirectAdv;

    while(!cin.eof()){
        cin>>Groups>>TeamsInGroup>>Advance>>DirectAdv;

        long long GroupStageMatches = 0;
        long KnockoutMatches = 0;
        long KnockoutCountries = (Groups*Advance)+DirectAdv;

        

        if(Groups>0 && 
           TeamsInGroup > 0 && 
           Advance > 0 && 
           DirectAdv >= 0 && 
           Advance <= TeamsInGroup){
        //SPRAWDZ CZY KNOCKOUT STAGE jest potęgą 2'jki
        long check = checkKnockout(KnockoutCountries);
        //Ile trzeba dodac do fazy knockout aby turniej mial sens?
        long neeededTeams = AddTeams(check, KnockoutCountries);

        long KC = check;
        GroupStageMatches = Groups * MatchesInGroup(TeamsInGroup);
        while(KC>0){
            KnockoutMatches += KC/2;
            KC = KC/2;
        }


        /*
        cout<<"Groups: "<<Groups<<endl;
        cout<<"Advance: "<<Advance<<endl;
        cout<<"Group Matches: "<<GroupStageMatches<<endl;
        cout<<"Knockout Countries: "<<KnockoutCountries<<endl;
        //65536 65536 65536 0
        */

        cout<<Groups<<"*"<<Advance<<"/"<<TeamsInGroup<<"+"<<DirectAdv<<"="<<KnockoutMatches+GroupStageMatches<<"+"<<neeededTeams<<endl;

        }
    }
    return 0;
}
