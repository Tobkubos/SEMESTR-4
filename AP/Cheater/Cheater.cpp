#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to convert card value to integer
int convertValue(char value) {
    if (value >= '2' && value <= '9') {
        return value - '0'; // Convert digit char to int
    } else if (value == 'T') {
        return 10;
    } else if (value == 'J') {
        return 11;
    } else if (value == 'Q') {
        return 12;
    } else if (value == 'K') {
        return 13;
    } else if (value == 'A') {
        return 14;
    }
    return 0;
}

// Function to calculate points for Eve given Adam's cards and Eve's cards
void calculatePoints(const vector<pair<char, char>>& adam_cards, const vector<pair<char, char>>& eve_cards) {

}

int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++) {
        int cards;
        cin >> cards;

        //Adam
        vector<pair<char, char>> adam_cards(cards);
        for (int i = 0; i < cards; i++) {
            cin >> adam_cards[i].first >> adam_cards[i].second;
        }

        //Eve
        vector<pair<char, char>> eve_cards(cards);
        for (int i = 0; i < cards; i++) {
            cin >> eve_cards[i].first >> eve_cards[i].second;
        }

        calculatePoints(adam_cards, eve_cards);
    }

    return 0;
}
