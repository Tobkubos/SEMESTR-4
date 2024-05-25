#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Point
{
    int x;
    int y;
};

bool compare(const Point &a, const Point &b)
{
    return a.y < b.y;
}

Point FindLowestPoint(Point *&tab, int s)
{
    Point minYPoint = tab[0];
    for (int i = 0; i < s; i++)
    {
        if (tab[i].y < minYPoint.y)
        {
            minYPoint = tab[i];
        }
    }
    return minYPoint;
}

int FindClosestPointToPoint(Point *&tab, int s, Point base)
{
    int d = INT_MAX;
    for (int i = 0; i < s; i++)
    {
        if (base.x != tab[i].x || base.y != tab[i].y)
        {
            int dx = abs(base.x - tab[i].x);
            int dy = abs(base.y - tab[i].y);

            if (dx + dy < d)
            {
                d = dx + dy;
            }
            // cout << d << endl;
        }
    }
    return d;
}

Point findPointByDst(vector<pair<Point, int>> &tab, int dst)
{
    for (const auto &t : tab)
    {
        if (t.second == dst)
        {
            return t.first;
        }
    }

    return tab[0].first;
}

void FindNearestPolicjant()
{
    // vector<pair<int, pair<int, int>>> allPoints;
    int s = 0;
    cin >> s;
    Point *allPoints = new Point[s];

    for (int i = 0; i < s; i++)
    {
        cin >> allPoints[i].x;
        cin >> allPoints[i].y;
    }

    Point *orgPoints = new Point[s];
    for (int i = 0; i < s; i++)
    {
        orgPoints[i] = allPoints[i];
    }

    sort(allPoints, allPoints + s, compare);

    // vector<Point> ngh;
    vector<pair<pair<Point, Point>, int>> ngh_dst;

    Point base = allPoints[0];
    Point finalA = base, finalB = base;
    long long int msize = FindClosestPointToPoint(allPoints, s, base);
    int higher = (s - msize) <= 0 ? 1 : (s - msize);
    int cl = msize;

    Point currentPoint;
    for (int i = 0; i < s; i++)
    {
        currentPoint = allPoints[i];
        // cout << "current: " << currentPoint.x << ", " << currentPoint.y << endl;
        ngh_dst.clear();

        // cout << "current: " << currentPoint.x << ", " << currentPoint.y << endl;
        for (int j = 0; j < s; j++)
        {
            if (abs(currentPoint.y - allPoints[j].y) <= msize && (currentPoint.x != allPoints[j].x || currentPoint.y != allPoints[j].y))
            {
                int idl = abs(currentPoint.x - allPoints[j].x) + abs(currentPoint.y - allPoints[j].y);
                ngh_dst.push_back(make_pair(make_pair(currentPoint, allPoints[j]), idl));
            }
        }

        // for (const auto& n : ngh_dst)
        //     cout << n.first.second.x << ", " << n.first.second.y << "; odl: " << n.second << endl;
        // cout << endl;

        int m = INT_MAX;
        for (int j = 0; j < ngh_dst.size(); j++)
        {
            if (ngh_dst[j].second < m && currentPoint.x != ngh_dst[j].first.second.x || currentPoint.y != ngh_dst[j].first.second.y)
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
            // cout << "NAJMNIEJSZA: " << n.first.second.x << ", " << n.first.second.y << "; odl: " << n.second << endl;
        }
    }

    int f1 = 0, f2 = 0;

    for (int i = 0; i < s; i++)
    {
        // cout << "f1: " << orgPoints[i].x << ", " << orgPoints[i].y << endl;
        if (finalA.x == orgPoints[i].x && finalA.y == orgPoints[i].y)
        {
            // cout << i+1 << " ";
            f1 = i + 1;
            break;
        }
    }

    for (int i = 0; i < s; i++)
    {
        // cout << "f2: " << orgPoints[i].x << ", " << orgPoints[i].y << endl;
        if (finalB.x == orgPoints[i].x && finalB.y == orgPoints[i].y)
        {
            // cout << i+1 << endl;
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
}

int main()
{
    int tests = 0;
    cin >> tests;

    for (int i = 0; i < tests; i++)
    {
        FindNearestPolicjant();
    }
}
