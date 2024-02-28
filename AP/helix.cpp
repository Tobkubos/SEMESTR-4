#include <iostream>
#include <vector>   

using namespace std;

vector<pair<int,int>> CheckIntersectionPoints(const vector<int>& vector1, const vector<int>& vector2){

    int v1s = vector1.size();
    int v2s = vector2.size();
    
    vector<pair<int,int>> Intersections;

    for(int i=0; i<v1s; i++){
        for(int j = 0; j < v2s; j++){
            if(vector1[i] == vector2[j]){
                Intersections.push_back(make_pair(i,j));
            }
        }
    }

    for(int i = 0; i<Intersections.size(); i++){
        cout<<Intersections[i].first<<" "<<Intersections[i].second<<endl;

    }
    return Intersections;
}

int main(){


    vector<int> vector1;
    vector<int> vector2;

    vector1.push_back(1);   //0
    vector1.push_back(3);   //1
    vector1.push_back(12);  //2
    vector1.push_back(26);  //3
    vector1.push_back(40);  //4



    vector2.push_back(0);   //0
    vector2.push_back(2);   //1
    vector2.push_back(12);  //2
    vector2.push_back(13);  //3
    vector2.push_back(14);  //4
    vector2.push_back(15);  //5
    vector2.push_back(16);  //6
    vector2.push_back(26);  //7
    vector2.push_back(30);  //8
    vector2.push_back(40);  //9
    CheckIntersectionPoints(vector1, vector2);
    
    return 0;
}