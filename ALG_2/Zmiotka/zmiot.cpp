#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void Zmiot(vector<pair<int, pair<int, int>>> cords)
{
    int minY1 = INT_MAX;
    int minY2 = INT_MAX;

    for (const auto &cord : cords)
    {
        int y = cord.second.second;
        if (y < minY1)
        {
            minY2 = minY1;
            minY1 = y;
        }
        else if (y < minY2 && y != minY1)
        {
            minY2 = y;
        }
    }
    cout << "Minimum y values: " << minY1 << " and " << minY2 << endl;

    int BroomHeight = (minY2 - minY1) * 2;
    cout << "first broom Height: " << BroomHeight << endl;

    /////////////////
    // algorythm
    //-- --
    vector<pair<int, pair<int, int>>> base;
    vector<pair<int, pair<int, int>>> patrol;
    int minDist = 0;

    for (const auto &cord : cords)
    {
        if (cord.second.second == minY1)
        {
            base.push_back(cord);
            cout << "BASE :" << "(" << cord.first << ", (" << cord.second.first << ", " << cord.second.second << ")) " << endl;
        }

        else if (cord.second.second < minY1 + BroomHeight)
        {
            patrol.push_back(cord);
            cout << "PATROL :" << "(" << cord.first << ", (" << cord.second.first << ", " << cord.second.second << ")) " << endl;
        }
    }
    for (const auto &b : base)
    {
        for (const auto &c : patrol)
        {
            int minDist = abs(b.second.second - c.second.second) + abs(b.second.first - c.second.first);
            cout << minDist << " ";
        }
        cout << endl;
    }
    base.clear();
    patrol.clear();

    cout << endl;
    cout << endl;
}

int main()
{
    int cases = 0;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        vector<pair<int, pair<int, int>>> cords;
        int objects = 0;
        cin >> objects;

        for (int j = 0; j < objects; j++)
        {
            int x, y;
            cin >> x >> y;
            cords.push_back(make_pair(j + 1, make_pair(x, y)));
        }

        // view
        for (const auto &cord : cords)
        {
            cout << "[" << cord.first << ", (" << cord.second.first << ", " << cord.second.second << ")]     ";
        }
        cout << endl;

        Zmiot(cords);
    }

    return 0;
}