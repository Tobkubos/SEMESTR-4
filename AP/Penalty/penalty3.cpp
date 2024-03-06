#include <iostream>

using namespace std;

long long CheckKnockout(){

}

int main() {
    long long Groups = 65535;
    long long Teams = 65535;
    long long advance = 65535;
    long long DirAdvance = 65535;

    long long GroupSum = (Teams * (Teams-1))/2;
    long long GroupStageSum = GroupSum * Groups;
    long long KnockoutPlayers = Groups * advance + DirAdvance;
    cout<<GroupSum<<endl;
    cout<<GroupStageSum<<endl;

    long long CheckKnockout();
    return 0;
}