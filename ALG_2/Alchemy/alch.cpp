#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int cases = 0;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        map<int, vector<int>> connectionTable;
        vector<int> priceTable;
        int potions = 0;
        int transmutations = 0;
        cin >> potions >> transmutations;

        for (int k = 0; k < potions; k++)
        {
            int price = 0;
            cin >> price;
            priceTable.push_back(price);
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
            cout << q << " ";
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
    }
    return 0;
}