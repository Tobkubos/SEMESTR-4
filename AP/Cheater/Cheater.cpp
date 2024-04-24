#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Converter(vector<pair<int,int>> &cards, char a, char b){

            pair<int,int> card;

            if(a == '2') card.first = 2;
            if(a == '3') card.first = 3;
            if(a == '4') card.first = 4;
            if(a == '5') card.first = 5;
            if(a == '6') card.first = 6;
            if(a == '7') card.first = 7;
            if(a == '8') card.first = 8;
            if(a == '9') card.first = 9;

            if(a == 'T') card.first = 10;
            if(a == 'J') card.first = 11;
            if(a == 'Q') card.first = 12;
            if(a == 'K') card.first = 13;
            if(a == 'A') card.first = 14;

            if(b == 'H') card.second = 3;
            if(b == 'S') card.second = 2;
            if(b == 'D') card.second = 1;
            if(b == 'C') card.second = 0;
            cards.push_back(card);
}

void SetCardsInProperOrder(vector<pair<int,int>> &adam_cards ,vector<pair<int,int>> &eve_cards ){
    for(int i =0; i<adam_cards.size(); i++){
        int iter = 0;
        while(eve_cards[i].first < adam_cards[i].first && iter < adam_cards.size()-1){
            pair<int,int> temp = eve_cards[i];
            eve_cards.erase(eve_cards.begin()+i);
            eve_cards.push_back(temp);
            iter++;
        }
        //TODO: SPRAWDZ GEN KARTY, DAJ +1 JEZELI JEST, JEZELI NIE TO +2 JEZELI NIE TO +3
    }

    for(int i =0; i<adam_cards.size(); i++){
        cout<<adam_cards[i].first<<" "<<adam_cards[i].second<<"  ///  "<<eve_cards[i].first<< " "<<eve_cards[i].second<<endl;
    }
}


int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        int cards;
        cin >> cards;

        //Adam
        vector<pair<int, int>> adam_cards;
        vector<pair<int,int>> eve_cards;
        for (int i = 0; i < cards; i++) {
            char a,b;
            cin>>a>>b;
            Converter(adam_cards, a,b);

        }
        for (int i = 0; i < cards; i++) {
            char c,d;
            cin>>c>>d;
            Converter(eve_cards, c,d);

        }
        sort(adam_cards.begin(), adam_cards.end());
        sort(eve_cards.begin(), eve_cards.end());

        //
        for(int i = 0; i<adam_cards.size(); i++){
            cout<<"KARTA ADAMA "<<adam_cards[i].first<<" : "<<adam_cards[i].second<<endl;
        }

        for(int i = 0; i<eve_cards.size(); i++){
            cout<<"KARTA EVY "<<eve_cards[i].first<<" : "<<eve_cards[i].second<<endl;
        }
        //

        SetCardsInProperOrder(adam_cards,eve_cards);
    }

    return 0;
}
