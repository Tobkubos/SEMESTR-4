#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>

//ostatnia krawedz z pierwsza TODO

using namespace std;

struct Point{
    int x;
    int y;
    double angle;
    double dist;
};

bool compare(const Point& a, const Point& b) {
    if (a.angle == b.angle)
        return a.x < b.x;
    return a.angle < b.angle;
}


double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double direction(Point p1, Point p2, Point p3){
    return (p3.y - p2.y)*(p2.x - p1.x) - (p2.y - p1.y)*(p3.x - p2.x);    
}

void ConvexHull(vector<Point> LL, vector<Point> SL){
        //Znajdz punkt z min y
        Point p0 = LL[0];
        for (int i = 1; i<LL.size(); i++){
            if(p0.y > LL[i].y){
                p0 = LL[i];
            }
        }

        //cout<<p0.x<<" "<<p0.y<<endl;

        //Wylicz kąty do osi X
        for(int i =0; i<LL.size(); i++){
            double angle = atan2(LL[i].y - p0.y, LL[i].x - p0.x);
            angle = angle * (180/M_PI);
            LL[i].angle = angle;
        }


        //Wylicz dystans do p0
        for(int i =0; i<LL.size(); i++){
            LL[i].dist = distance(p0, LL[i]);
        }

        //posortuj wzgledem angle i dist
        sort(LL.begin(), LL.end(), compare);
        
        /*
        for(int i =0; i<LL.size(); i++){
            cout<<LL[i].x<<" "<<LL[i].y<<" ::: "<<LL[i].angle<<"  dist: "<<LL[i].dist<<endl;

        }
        */

        vector<Point> hull;
        hull.push_back(LL[0]);
        hull.push_back(LL[1]);
        for(int i =2; i<LL.size(); i++){
            while(hull.size() >=2 && direction(hull[hull.size()-2], hull[hull.size()-1], LL[i]) < 0){
                hull.pop_back();
            }
            hull.push_back(LL[i]);
        }


        //OTOCZKA PUNKTY OTOCZKI
        /*
        cout<<endl<<endl;
        for(int i =0; i<hull.size(); i++){
            cout<<hull[i].x<<" "<<hull[i].y<<" ::: "<<hull[i].angle<<"  dist: "<<hull[i].dist<<endl;

        }
        */

        //ILE MAŁYCH LATARNI W OTOCZCE???
        int counter = 0;
        for(int i = 0; i<SL.size(); i++){
            bool isInside = true;
            for(int j = 0; j<hull.size()-2; j++){
                if(direction(hull[j], hull[j+1], SL[i]) < 0){
                    isInside = false;
                    break;
                }
            }
            if(isInside) counter++;
        }

        cout<<counter<<endl;
}

int main(){
    //LARGE LANTERNS
    int largeLanterns = 0;
    std::cin>>largeLanterns;
    vector<Point> LL;
    for(int i =0; i<largeLanterns; i++){
        int x,y =0;

        std::cin>>x>>y;
        Point p = Point();
        p.x = x;
        p.y = y;
        LL.push_back(p);
    }

    //SMALL LANTERNS
    int smallLanterns = 0;
    std::cin>>smallLanterns;
    vector<Point> SL;
    for(int i =0; i<smallLanterns; i++){
        int x,y =0;

        std::cin>>x>>y;
        Point p = Point();
        p.x = x;
        p.y = y;
        SL.push_back(p);
    }

    ConvexHull(LL, SL);


}