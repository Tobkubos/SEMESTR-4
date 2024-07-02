#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

struct Point
{
    double x;
    double y;
    double angle;
};

bool Compare(const Point &a, const Point &b)
{
    if (a.angle != b.angle)
        return a.angle < b.angle;
    else
        return a.x < b.x;
}

double Det(Point p1, Point p2, Point p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

vector<Point> ConvexHull(Point *&LL, int size)
{
    vector<Point> hull;
    Point MinY = LL[0];

    // znajdz min y
    for (int i = 1; i < size; i++)
    {
        if (LL[i].y < MinY.y)
            MinY = LL[i];
    }

    for (int i = 0; i < size; i++)
    {
        if (LL[i].x != MinY.x || LL[i].y != MinY.y)
        {
            LL[i].angle = abs(atan2(LL[i].y - MinY.y, LL[i].x - MinY.x));
        }
        else
        {
            LL[i].angle = 0;
        }
    }

    // posortuj
    sort(LL, LL + size, &Compare);

    hull.push_back(LL[0]);
    hull.push_back(LL[1]);

    // tworz otoczke
    for (int i = 2; i < size; i++)
    {
        while (hull.size() >= 2 && Det(hull[hull.size() - 2], hull[hull.size() - 1], LL[i]) < 0)
        {
            hull.pop_back();
        }
        hull.push_back(LL[i]);
    }
    return hull;
}

int CollectSmallPoints(vector<Point> &hull, Point *&SL, int SLsize)
{
    int result = 0;
    int n = hull.size();

    // ile malych latarni w otoczce?
    for (int i = 0; i < SLsize; i++)
    {
        bool isInside = true;
        for (int j = 0; j < n; j++)
        {
            if (Det(hull[j], hull[(j + 1) % n], SL[i]) < 0)
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

    vector<Point> hull = ConvexHull(bigPoints, bigPointsNum);
    int result = CollectSmallPoints(hull, smallPoints, smallPointsNum);
    cout << result << endl;

    return 0;
}
