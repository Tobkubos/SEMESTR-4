#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countPairs(const vector<int>& a) {
    unordered_map<int, long long> frequency;
    long long pairs = 0;

    // Liczymy częstotliwość wystąpień każdej liczby w wejściowym ciągu
    for (int num : a) {
        frequency[num]++;
    }

    // Obliczamy liczbę par spełniających warunek
    for (auto& pair : frequency) {
        long long count = pair.second;
        pairs += count * (count - 1); // Dla każdej liczby znajdujemy iloczyn ilości wystąpień, pomniejszony o 1
    }

    return pairs;
}

int main() {
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        int numbers;
        cin >> numbers;

        vector<int> allNumbers(numbers);
        for(int j = 0; j < numbers; j++) {
            cin >> allNumbers[j];
        }
        cout << "wynik " << countPairs(allNumbers) << endl;
    }
    
    return 0;
}