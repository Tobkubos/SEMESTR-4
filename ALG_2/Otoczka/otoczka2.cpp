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

bool Compare(const Point &a, const Point &b) {
    return a.y < b.y;
}

double Det(const Point &p1, const Point &p2, const Point &p3){
    return (p1.x * p2.y) + (p2.x * p3.y) + (p1.y * p3.x)    -   ((p2.y * p3.x) + (p1.y * p2.x) + (p1.x * p3.y));
}

void ConvexHull(vector<Point> LL){

    vector<pair<Point,double>> tablica;
    for(int i = 0; i<LL.size(); i++){

        double d = abs(LL[i].x) + abs(LL[i].y);
        double y = LL[i].y;
        double alpha = 0;

        if(LL[i].x >= 0 && LL[i].y >= 0){
            alpha = y/d;   
        }
        
        else if(LL[i].x < 0 && LL[i].y > 0){
            alpha = 2 - (y/d);
        }

         else if(LL[i].x <= 0 && LL[i].y <= 0){
            alpha = 2 + (abs(y)/d);
        }

        else if(LL[i].x > 0 && LL[i].y < 0){
            alpha = 4 - (abs(y)/d);
        }

        tablica.push_back(make_pair(LL[i], alpha)); 
    }

    sort(tablica.begin(), tablica.end(), [](const pair<Point, double>& a, const pair<Point, double>& b) {
        return a.second < b.second;
    });

    for(int i = 0; i<tablica.size(); i++){
        cout<<"[ "<<tablica[i].first.x << " " <<tablica[i].first.y <<" ] alpha: "<<tablica[i].second<<endl;
    }

    sort(tablica.begin(), tablica.end(), Compare);

    vector<Point> Hull;
    Hull.push_back(tablica[0].first);
    Hull.push_back(tablica[1].first);

    for(int i = 2; i<tablica.size(); i++){
        double hs = Hull.size();
        double det = Det(Hull[hs - 2], Hull[hs - 1], tablica[i].first);

        cout<<"p1 "<<Hull[hs-2].x<<" "<<Hull[hs-2].y<<endl;
        cout<<"p2 "<<Hull[hs-1].x<<" "<<Hull[hs-1].y<<endl;
        cout<<"p3 "<<tablica[i].first.x<<" "<<tablica[i].first.y<<endl;
        cout<<"det "<<det<<endl<<endl;

        if(det > 0){
            Hull.pop_back();
        }
        Hull.push_back(tablica[i].first);
    }

    for(int i = 0; i<Hull.size(); i++){
        cout<<Hull[i].x<< " "<<Hull[i].y<<endl;
    }
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

    ConvexHull(LL);


}