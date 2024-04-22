#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void Watchdog(vector<pair<int, int>> hatch, int size)
{
    vector<pair<int, int>> GoodCordsVector;
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            int dist_x = min(x, size - 1 - x);

            int dist_y = min(y, size - 1 - y);

            int min_dist = min(dist_x, dist_y);
            bool IsEveryGood = true;
            for (int i = 0; i < hatch.size(); i++)
            {
                int dx = abs(x - hatch[i].first);
                int dy = abs(y - hatch[i].second);
                if ((dx == 0 && dy == 0) || (dx * dx + dy * dy > min_dist * min_dist))
                {
                    IsEveryGood = false;
                }
            }

            if (IsEveryGood == true)
            {
                GoodCordsVector.push_back(pair<int, int>(x, y));
                sort(GoodCordsVector.begin(), GoodCordsVector.end(),
                     [](pair<int, int> a, pair<int, int> b)
                     {if(a.first == b.first) return a.second < b.second;
                     else return a.first < b.first; });

                // std::cout
                //     << "x:" << x << " y:" << y << "   ";
                IsEveryGood = false;
            }

            // std::cout << min_dist << " ";
        }
        // std::cout << endl;
    }
    if (GoodCordsVector.size() != 0)
    {
        std::cout << GoodCordsVector[0].first << " " << GoodCordsVector[0].second << endl;
    }
    if (GoodCordsVector.size() == 0)
    {
        std::cout << "impossible" << endl;
    }
}

int main()
{
    int cases = 0;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int size = 0;
        int numofhatches = 0;
        vector<pair<int, int>> hatch;
        cin >> size;
        cin >> numofhatches;

        for (int j = 0; j < numofhatches; j++)
        {
            pair<int, int> hatchCordinates;
            int x = 0, y = 0;
            cin >> x;
            cin >> y;
            hatchCordinates.first = x;
            hatchCordinates.second = y;
            hatch.push_back(hatchCordinates);
        }

        Watchdog(hatch, size);
        // std::cout << endl
        //          << endl
        //          << endl;
    }

    return 0;
}