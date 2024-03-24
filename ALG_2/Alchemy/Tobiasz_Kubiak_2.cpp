#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

void AlchemicStep(int v, map<int, vector<int>> &connectionTable, map<int, bool> &visited, stack<int> &s)
{
    visited[v] = true;
    for (char neighbor : connectionTable[v])
    {
        if (!visited[neighbor])
        {
            AlchemicStep(neighbor, connectionTable, visited, s);
        }
    }
    s.push(v);
}

int Alchemic(map<int, vector<int>> connectionTable, vector<pair<int, int>> priceTable, int potion, int transmutations)
{
    map<int, bool> visited;
    stack<int> s;

    for (auto i : connectionTable)
    {
        visited[i.first] = false;
    }

    AlchemicStep(potion, connectionTable, visited, s);

    vector<int> Income;
    while (!s.empty())
    {
        for (auto i : priceTable)
        {
            if (i.first == potion)
            {
                Income.push_back(priceTable[s.top() - 1].second - i.second);
            }
        }
        s.pop();
    }
    auto Income_iterator = max_element(Income.begin(), Income.end());
    if (Income_iterator != Income.end())
    {
        int maxIncome = *Income_iterator;
        return maxIncome;
    }
    return 0;
}

int main()
{
    int cases = 0;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        map<int, vector<int>> connectionTable;
        vector<pair<int, int>> priceTable;
        int potions = 0;
        int transmutations = 0;
        cin >> potions >> transmutations;

        for (int k = 1; k < potions + 1; k++)
        {
            int price = 0;
            cin >> price;
            pair<int, int> KeyValue(k, price);
            priceTable.push_back(KeyValue);
        }
        for (int j = 0; j < transmutations; j++)
        {
            int key = 0;
            int value = 0;
            cin >> key >> value;
            connectionTable[key].push_back(value);
        }

        vector<int> prices;
        for (auto i : priceTable)
        {
            prices.push_back(Alchemic(connectionTable, priceTable, i.first, transmutations));
        }
        auto Income_iterator = max_element(prices.begin(), prices.end());
        if (Income_iterator != prices.end())
        {
            int maxIncome = *Income_iterator;
            cout << maxIncome << endl;
        }
    }
    return 0;
}