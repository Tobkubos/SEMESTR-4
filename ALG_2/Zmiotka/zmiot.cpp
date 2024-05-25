#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void Zmiot(vector<pair<int, pair<int, int>>> cords)
{

    // Find closest point to first point in array
    int dx = INT_MAX;
    int dxtemp = 0;
    int finalIdx1 = 0, finalIdx2 = 0;
    const pair<int, int> &first_point = cords[0].second;

    for (int i = 1; i < cords.size(); ++i)
    {
        const pair<int, int> &current_point = cords[i].second;
        if (current_point != first_point)
        {
            int dxtemp = abs(first_point.second - current_point.second) + abs(first_point.first - current_point.first);
            dx = min(dx, dxtemp);
        }
    }
    // calculate broom size
    int BroomHeight = dx;
    cout << "broom Height: " << BroomHeight << endl;
    //
    //
    //
    //
    //
    //
    //
    //
    //
    // start brooming
    pair<int, pair<int, int>> currentPoint;

    // idx, x, y, dst
    // neighbours.first = point
    // neighbours.first.first = idx
    // neighbours.first.second.first = x;
    // neighbours.first.second.second = y;

    // neighbours.second = distance

    int cl = BroomHeight;
    vector<pair<pair<int, pair<int, int>>, int>> neighbours;
    for (int i = 0; i < cords.size(); i++)
    {
        currentPoint = cords[i];
        neighbours.clear();
        // cout << "current point " << currentPoint.second.first << " " << currentPoint.second.second << endl;

        for (int j = 0; j < cords.size(); j++)
        {
            if (abs(currentPoint.second.second - cords[j].second.second <= BroomHeight) &&
                (currentPoint != cords[j]))
            {
                int len = abs(currentPoint.second.first - cords[j].second.first) + abs(currentPoint.second.second - cords[j].second.second);
                neighbours.push_back(make_pair(cords[j], len));
            }
        }

        for (const auto &e : neighbours)
        {
            // cout << e.first.second.first << " " << e.first.second.second << " " << e.second << endl;
        }

        int t = INT_MAX;
        for (int j = 0; j < neighbours.size(); j++)
        {
            if (neighbours[j].second < t && (currentPoint != neighbours[j].first))
            {
                t = neighbours[j].second;
                if (t < cl)
                {
                    cl = t;
                }
            }
        }
        for (const auto &n : neighbours)
        {
            if (n.second == cl)
            {
                finalIdx1 = currentPoint.first;
                finalIdx2 = n.first.first;
                break;
            }
        }
    }
    cout << "DUPA: " << finalIdx1 << " " << finalIdx2 << endl;
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

        sort(cords.begin(), cords.end(), [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
             { return a.second.second < b.second.second; });

        // view
        for (const auto &cord : cords)
        {
            // cout << "[" << cord.first << ", (" << cord.second.first << ", " << cord.second.second << ")]     ";
        }
        // cout << endl;

        Zmiot(cords);
    }

    return 0;
}