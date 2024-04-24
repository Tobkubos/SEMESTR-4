#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib> // do funkcji rand()

using namespace std;

vector<int> generateRandomNumbers(int count) {
    vector<int> numbers;
    for (int i = 0; i < count; ++i) {
        int randomNum = rand() % 2000000 + 1; // losujemy liczby od 1 do 2000000
        numbers.push_back(randomNum);
    }
    return numbers;
}

void saveNumbersToFile(const vector<int>& numbers, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (int num : numbers) {
            outputFile << num << " ";
        }
        outputFile.close();
        cout << "Pomyślnie zapisano liczby do pliku: " << filename << endl;
    } else {
        cout << "Błąd: Nie udało się otworzyć pliku do zapisu." << endl;
    }
}

int main() {
    srand(time(nullptr)); // inicjalizacja generatora liczb pseudolosowych
    int count = 2000000; // liczba liczb do wygenerowania
    vector<int> randomNumbers = generateRandomNumbers(count);
    string filename = "losowe_liczby.txt";
    saveNumbersToFile(randomNumbers, filename);
    return 0;
}