#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

pair<long, pair<int, int>> closestPair(vector<pair<int, pair<int, int>>> cords, int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({cords[i].second.first, cords[i].second.second});

    sort(v.begin(), v.end());

    long d = LONG_MAX;
    set<pair<int, int>> st;
    st.insert({v[0].first, v[0].second});

    pair<int, int> closestPairIndices = {cords[0].first, cords[0].first};

    for (int i = 1; i < n; i++)
    {
        auto l = st.lower_bound({v[i].first - d, v[i].second - d});
        auto r = st.upper_bound({v[i].first, v[i].second + d});
        if (l == st.end())
            continue;

        for (auto p = l; p != r; p++)
        {
            pair<int, int> val = *p;
            long dis = abs(long(v[i].first) - val.first) + abs(long(v[i].second) - val.second);
            if (d > dis)
            {
                d = dis;
                closestPairIndices = {cords[i].first, cords[distance(v.begin(), find(v.begin(), v.end(), val))].first};
            }
        }
        st.insert({v[i].first, v[i].second});
    }

    return {d, closestPairIndices};
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

        auto result = closestPair(cords, cords.size());
        long distance = result.first;
        auto indices = result.second;

        cout << "The smallest distance is: " << distance << " between points " << indices.first << " and " << indices.second << endl;
    }

    return 0;
}