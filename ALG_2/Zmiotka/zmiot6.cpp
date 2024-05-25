#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

pair<int, int> FindLowestPoint(pair<int, int> *&cords, int s)
{
    pair<int, int> minYPoint = cords[0];
    for (int i = 0; i < s; i++)
    {
        if (cords[i].second < minYPoint.second)
        {
            minYPoint = cords[i];
        }
    }
    return minYPoint;
}

int FindClosestPointToPoint(pair<int, int> *&tab, int s, pair<int, int> base)
{
    int d = INT_MAX;
    for (int i = 0; i < s; i++)
    {
        if (base.first != tab[i].first || base.second != tab[i].second)
        {
            int dx = abs(base.first - tab[i].first);
            int dy = abs(base.second - tab[i].second);

            if (dx + dy < d)
            {
                d = dx + dy;
            }
        }
    }
    return d;
}

void FindNearestPolicjant(const vector<pair<int, pair<int, int>>> &cords)
{
    int s = cords.size();
    pair<int, int> *allPoints = new pair<int, int>[s];

    for (int i = 0; i < s; i++)
    {
        allPoints[i] = cords[i].second;
    }

    pair<int, int> *orgPoints = new pair<int, int>[s];
    for (int i = 0; i < s; i++)
    {
        orgPoints[i] = allPoints[i];
    }

    sort(allPoints, allPoints + s, compare);

    vector<pair<pair<pair<int, int>, pair<int, int>>, int>> ngh_dst;

    pair<int, int> base = allPoints[0];
    pair<int, int> finalA = base, finalB = base;
    long long int msize = FindClosestPointToPoint(allPoints, s, base);
    int higher = max(1, s - static_cast<int>(msize));
    int cl = msize;

    pair<int, int> currentPoint;
    for (int i = 0; i < s; i++)
    {
        currentPoint = allPoints[i];
        ngh_dst.clear();

        for (int j = 0; j < s; j++)
        {
            if (abs(currentPoint.second - allPoints[j].second) <= msize && (currentPoint.first != allPoints[j].first || currentPoint.second != allPoints[j].second))
            {
                int idl = abs(currentPoint.first - allPoints[j].first) + abs(currentPoint.second - allPoints[j].second);
                ngh_dst.push_back(make_pair(make_pair(currentPoint, allPoints[j]), idl));
            }
        }

        int m = INT_MAX;
        for (int j = 0; j < ngh_dst.size(); j++)
        {
            if (ngh_dst[j].second < m && (currentPoint.first != ngh_dst[j].first.second.first || currentPoint.second != ngh_dst[j].first.second.second))
            {
                m = ngh_dst[j].second;

                if (m < cl)
                {
                    cl = m;
                }
            }
        }

        for (const auto &n : ngh_dst)
        {
            if (n.second == cl)
            {
                finalA = n.first.second;
                finalB = currentPoint;
                break;
            }
        }
    }

    int f1 = 0, f2 = 0;

    for (int i = 0; i < s; i++)
    {
        if (finalA.first == orgPoints[i].first && finalA.second == orgPoints[i].second)
        {
            f1 = i + 1;
            break;
        }
    }

    for (int i = 0; i < s; i++)
    {
        if (finalB.first == orgPoints[i].first && finalB.second == orgPoints[i].second)
        {
            f2 = i + 1;
            break;
        }
    }

    if (f1 < f2)
    {
        cout << f1 << " " << f2 << endl;
    }
    else
    {
        cout << f2 << " " << f1 << endl;
    }

    delete[] allPoints;
    delete[] orgPoints;
}

int main()
{
    int cases = 0;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int objects = 0;
        cin >> objects;
        vector<pair<int, pair<int, int>>> cords;

        for (int j = 0; j < objects; j++)
        {
            int x, y;
            cin >> x >> y;
            cords.push_back(make_pair(j + 1, make_pair(x, y)));
        }

        FindNearestPolicjant(cords);
    }

    return 0;
}