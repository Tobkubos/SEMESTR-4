#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

void AlchemicStep(int v, map<int, vector<int>> &graph, map<int, bool> &visited, stack<int> &s)
{
    visited[v] = true;
    for (char neighbor : graph[v])
    {
        if (!visited[neighbor])
        {
            AlchemicStep(neighbor, graph, visited, s);
        }
    }
    s.push(v);
}

void Alchemic(map<int, vector<int>> connectionTable, vector<pair<int, int>> priceTable)
{
    map<int, bool> visited;
    stack<int> s;
    // TO DO:
    // ZNAJDZ NAJMNIEJSZY INDEX CENY Z VECTORA PRICETABLE;
    int minPriceIndex = 3;
    //
    for (auto i : connectionTable)
    {
        visited[i.first] = false;
    }

    AlchemicStep(minPriceIndex, connectionTable, visited, s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
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

        Alchemic(connectionTable, priceTable);
    }
    return 0;
}