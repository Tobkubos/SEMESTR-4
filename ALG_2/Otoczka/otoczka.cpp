#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point{
    int x;
    int y;
};

bool compareByY(const Point &a, const Point &b) {
    return a.y < b.y;
}

int main(){

    //LARGE LANTERNS
    int largeLanterns = 0;
    cin>>largeLanterns;
    vector<Point> LL;
    for(int i =0; i<largeLanterns; i++){
        int x,y =0;

        cin>>x>>y;
        Point p = Point();
        p.x = x;
        p.y = y;
        LL.push_back(p);
    }

    //SMALL LANTERNS
    int smallLanterns = 0;
    cin>>smallLanterns;
    vector<Point> SL;
    for(int i =0; i<smallLanterns; i++){
        int x,y =0;

        cin>>x>>y;
        Point p = Point();
        p.x = x;
        p.y = y;
        SL.push_back(p);
    }

    //SORT BY Y
    sort(LL.begin(), LL.end(), compareByY);

    // Print
    for (const Point &p : LL) {
        cout << "Large Lantern: (" << p.x << ", " << p.y << ")\n";
    }

    vector<pair<Point, double>> PointAngle;
     for (int i = 1; i < LL.size(); i++) {
        double dX = LL[0].x - LL[i].x;
        double dY = LL[0].y - LL[i].y;
        double angleInRadians = atan2(dY, dX);
        double angleInDegrees = 180 - abs(angleInRadians * (180.0 / M_PI));
        PointAngle.push_back(make_pair(LL[i], angleInDegrees));
    }
    
    sort(PointAngle.begin(), PointAngle.end(), [](const pair<Point, double> &a, const pair<Point, double> &b) {
        return a.second < b.second;
    });
    //PRINT FIRST ANGLES
    for (const auto &pa : PointAngle) {
        const Point &p = pa.first;
        double angle = pa.second;
        cout << "Large Lantern: (" << p.x << ", " << p.y << ") - Angle: " << angle << " degrees\n";
    }
}