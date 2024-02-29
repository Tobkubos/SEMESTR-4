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


int Sumator(vector<pair<int,int>> Intersections, vector<int> vec1, vector<int> vec2){
    int sum = 0;

    int v2;
    int v1;
    int start1 = 0; 
    int start2 = 0;
    int end1 = 0;
    int end2 = 0;


        //STARTOWE DO PIERWSZEGO PRZECIECIA
        for(int q = 0; q< Intersections[0].first; q++){
            start1 += vec1[q];
        }
        for(int w = 0; w< Intersections[0].second; w++){
            start2 += vec2[w];
        }

        //KOŃCE WSTĘG
        for(int e = Intersections[Intersections.size()-1].first; e < vec1.size(); e++){
            end1 += vec1[e];
        }
        for(int r = Intersections[Intersections.size()-1].second; r < vec2.size(); r++){
            end2 += vec2[r];
        }
        
        if(start1>start2){
            sum += start1;
        }
        else{
            sum += start2;
        }


        if(end1>end2){
            sum += end1;
        }
        else{
            sum += end2;
        }

    cout<<"start1: "<<start1<<"   start2: "<<start2<<endl;
    cout<<"end1: "<<end1<<"   end2: "<<end2<<endl;

    //MIEDZY PUNKTAMI PRZECIECIA
    for(int i=0; i<Intersections.size()-1; i++){
        v1 = 0;
        v2 = 0;

        for(int j=Intersections[i].first; j<Intersections[i+1].first; j++){
            v1 += vec1[j];
        }
        for(int k=Intersections[i].second; k<Intersections[i+1].second; k++){
            v2 += vec2[k];
        }

        if(v1>v2){
            sum+=v1;
        }
        else{
            sum+=v2;
        }
        cout<<"sciezka1: "<<v1<<"   sciezka2: "<<v2<<endl;
    
    }


    return sum;
}

int main(){


    vector<int> vector1 = {3,5,7,9,20,25,30,40,55,56,57,60,62};
    vector<int> vector2 = {1,4,7,11,14,25,44,47,55,57,100};


    vector<int>vector3 = {-5,100,1000,1005};
    vector<int>vector4 = {-12,1000,1001};

    vector<pair<int,int>> Intersections = CheckIntersectionPoints(vector3, vector4);
    int Sum = Sumator(Intersections, vector3, vector4);
    cout<<Sum<<endl;   
    return 0;
}