#include <iostream>
#include <vector>

using namespace std;

// Funkcja rekurencyjna do generowania kombinacji
void generate_combinations(vector<int> &prices, int total, vector<int> &current_combination, vector<vector<int>> &combinations)
{
    if (total == 0)
    {
        combinations.push_back(current_combination);
        return;
    }

    for (int i = 0; i < prices.size(); ++i)
    {
        if (total - prices[i] >= 0)
        {
            current_combination.push_back(prices[i]);
            generate_combinations(prices, total - prices[i], current_combination, combinations);
            current_combination.pop_back();
        }
    }
}

int main()
{
    // Dostępna pula i ceny elementów
    int total = 10000;
    vector<int> prices = {400, 300, 200};

    // Wektor do przechowywania wszystkich kombinacji
    vector<vector<int>> combinations;

    // Wygeneruj wszystkie kombinacje
    vector<int> current_combination;
    generate_combinations(prices, total, current_combination, combinations);

    // Wyświetl wszystkie kombinacje
    for (const auto &combination : combinations)
    {
        for (int price : combination)
        {
            cout << price << " ";
        }
        cout << endl;
    }

    return 0;
}