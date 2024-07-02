#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

struct Point
{
    double x;
    double y;
    double alpha;
};

bool alphaSorter(const Point &a, const Point &b)
{
    if (a.alpha != b.alpha)
        return a.alpha < b.alpha;
    else
        return a.x < b.x;
}

double CalculateDet(Point p1, Point p2, Point p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

vector<Point> CreateHull(Point *&Bp, int Bpl)
{
    // buduje otoczke
    vector<Point> otk;
    Point miny = Bp[0];
    for (int i = 1; i < Bpl; i++)
    {
        if (Bp[i].y < miny.y)
            miny = Bp[i];
    }

    for (int i = 0; i < Bpl; i++)
    {
        if (Bp[i].x != miny.x || Bp[i].y != miny.y)
        {
            Bp[i].alpha = abs(atan2(Bp[i].y - miny.y, Bp[i].x - miny.x));
        }
        else
        {
            Bp[i].alpha = 0;
        }
    }

    // Sortuje po alfie
    sort(Bp, Bp + Bpl, &alphaSorter);

    otk.push_back(Bp[0]);
    otk.push_back(Bp[1]);

    for (int i = 2; i < Bpl; i++)
    {
        // cout << Bp[i].x << ", " << Bp[i].y << "\t" << Bp[i].alpha << endl;
        while (otk.size() >= 2 && CalculateDet(otk[otk.size() - 2], otk[otk.size() - 1], Bp[i]) < 0)
        {
            otk.pop_back();
        }
        otk.push_back(Bp[i]);
    }

    // for (const auto& o : otk)
    //{
    //	cout << o.x << "\t" << o.y << endl;
    // }
    return otk;
}

int CollectSmallPoints(vector<Point> &hull, Point *&Sp, int Spl)
{
    int result = 0;
    int n = hull.size();

    for (int i = 0; i < Spl; i++)
    {
        bool isInside = true;
        for (int j = 0; j < n; j++)
        {
            if (CalculateDet(hull[j], hull[(j + 1) % n], Sp[i]) < 0)
            {
                isInside = false;
                break;
            }
        }

        if (isInside)
            result++;
    }

    return result;
}

int main()
{
    int bigPointsNum = 0;
    int smallPointsNum = 0;

    cin >> bigPointsNum;
    Point *bigPoints = new Point[bigPointsNum];
    for (int i = 0; i < bigPointsNum; i++)
    {
        double x, y;
        cin >> x;
        cin >> y;
        bigPoints[i].x = x;
        bigPoints[i].y = y;
    }

    cin >> smallPointsNum;
    Point *smallPoints = new Point[smallPointsNum];
    for (int i = 0; i < smallPointsNum; i++)
    {
        double x, y;
        cin >> x;
        cin >> y;
        smallPoints[i].x = x;
        smallPoints[i].y = y;
    }

    vector<Point> hull = CreateHull(bigPoints, bigPointsNum);
    int result = CollectSmallPoints(hull, smallPoints, smallPointsNum);
    cout << result << endl;

    return 0;
}
