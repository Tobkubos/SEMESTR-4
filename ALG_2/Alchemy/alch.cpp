#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

void AlchemicStep(int v, map<int, vector<int>> &connectionTable, map<int, bool> &visited, stack<int> &s)
{
    visited[v] = true;
    //
    //
    for (char neighbor : connectionTable[v])
    {
        if (!visited[neighbor])
        {
            AlchemicStep(neighbor, connectionTable, visited, s);
        }
    }
    s.push(v);
}

void Alchemic(map<int, vector<int>> connectionTable, vector<pair<int, int>> priceTable, int potion, int transmutations)
{
    map<int, bool> visited;
    stack<int> s;

    for (auto i : connectionTable)
    {
        visited[i.first] = false;
    }

    AlchemicStep(potion, connectionTable, visited, s);

    //
    /*
    for (auto i : priceTable)
    {
        if (i.first == potion)
        {
            cout << potion << ":::::" << i.second << endl;
        }
    }
    */
    //
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
        cout << " - " << s.top();
        s.pop();
    }
    auto Income_iterator = max_element(Income.begin(), Income.end());
    if (Income_iterator != Income.end())
    {
        int maxIncome = *Income_iterator;
        cout << endl;
        cout << "Przychod: " << maxIncome << endl;
    }
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
        cout << endl;
        for (auto q : priceTable)
        {
            cout << q.first << " / " << q.second << endl;
        }
        cout << endl;
        for (auto x : connectionTable)
        {
            cout << x.first << ": ";
            for (auto y : x.second)
            {
                cout << y << " ";
            }
            cout << endl;
        }

        for (auto i : priceTable)
        {
            Alchemic(connectionTable, priceTable, i.first, transmutations);
        }
    }
    cout << "GIT GUT" << endl;
    return 0;
}