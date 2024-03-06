#include <iostream>

using namespace std;

long long IfPowerOfTwo(long long KP){
    while(KP%2 == 0){
        KP = KP / 2;

    }
    return KP;
}

long long checkKnockout(long long KnockoutCountries){
    long long check = IfPowerOfTwo(KnockoutCountries);
    //cout<<"check: "<<check<<endl;
    if(check != 1){
        long long temp = 1;
        while(temp < KnockoutCountries){
            temp = temp*2;
        }
        //cout<<"Nearest Power of two "<<temp<<endl;
        return temp;
    }
    return KnockoutCountries;
}

long long AddTeams(long long check, long long KnockoutCountries){
    if(check ==0){return 0;}
    else{
    long long neededTeamsInKnockout = check - KnockoutCountries;
    //cout<<"Needed Teams in Knockout: "<<neededTeamsInKnockout<<endl;
    return neededTeamsInKnockout;
}}

int main() {

    long long Groups;
    long long Teams;
    long long advance;
    long long DirAdvance;

    while(!cin.eof()){
    cin>>Groups>>Teams>>advance>>DirAdvance;

    if(Groups>0 && Teams >0 && advance >0 && advance<=Teams && DirAdvance >=0){
    long long GroupSum = (Teams * (Teams-1))/2;
    long long GroupStageSum = GroupSum * Groups;
    long long KnockoutCountries = Groups * advance + DirAdvance;
    long long KnockoutMatches = 0;


    //cout<<GroupSum<<endl;
    //cout<<GroupStageSum<<endl;

    long long check = checkKnockout(KnockoutCountries);
    //cout<<check<<endl;

    long long neeededTeams = AddTeams(check, KnockoutCountries);

        long long KC = check;
        while(KC>0){
            KnockoutMatches += KC/2;
            KC = KC/2;
        }

    cout<<Groups<<"*"<<advance<<"/"<<Teams<<"+"<<DirAdvance<<"="<<KnockoutMatches+GroupStageSum<<"+"<<neeededTeams<<endl;
    }}
    return 0;
}