#include <iostream>
#include <vector>
#include <fstream>

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
        //cout<<Intersections[i].first<<" "<<Intersections[i].second<<endl;

    }
    return Intersections;
}


int Sumator(vector<pair<int,int>> Intersections, vector<int> vec1, vector<int> vec2){
    int sum = 0;

    int v2 = 0;
    int v1 = 0;
    int start1 = 0;
    int start2 = 0;
    int end1 = 0;
    int end2 = 0;

        //JEZELI BRAK PRZECIECIA TO TUTAJ
        if(Intersections.size()==0){
            v1 =0;
            v2 = 0;

            for(int i = 0; i< vec1.size(); i++){
                v1 += vec1[i];
            }
            for(int i = 0; i< vec2.size(); i++){
                v2 += vec2[i];
            }
            //cout<<v1<<"   "<<v2<<endl;
            if(v1 >= v2){
                sum = v1;
            }
            else{
                sum = v2;
            }
        }

        else{

            //STARTOWE DO PIERWSZEGO PRZECIECIA
            for(int i = 0; i< Intersections[0].first; i++){
                start1 += vec1[i];
            }
            for(int i = 0; i< Intersections[0].second; i++){
                start2 += vec2[i];
            }

            //KOŃCE WSTĘG
            for(int i = Intersections[Intersections.size()-1].first; i < vec1.size(); i++){
                end1 += vec1[i];
            }
            for(int i = Intersections[Intersections.size()-1].second; i < vec2.size(); i++){
                end2 += vec2[i];
            }

            if(start1>=start2){
                sum += start1;
            }
            else{
                sum += start2;
            }


            if(end1>=end2){
                sum += end1;
            }
            else{
                sum += end2;
            }

        //cout<<"start1: "<<start1<<"   start2: "<<start2<<endl;
        //cout<<"end1: "<<end1<<"   end2: "<<end2<<endl;

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
            //cout<<"sciezka1: "<<v1<<"   sciezka2: "<<v2<<endl;
        }
    }


    return sum;
}

int main(){

    ifstream data;
    data.open("helix.txt");

    int vector_size;
    data>>vector_size;
    while(vector_size!=0)
    {
        vector<int> vector1;
        vector<int> vector2;
        int temp;

        for(int it = 0; it<vector_size; it++)
        {
            data>>temp;
            vector1.push_back(temp);
        }

        data>>vector_size;
        for(int it = 0; it<vector_size; it++)
        {
            data>>temp;
            vector2.push_back(temp);
        }

        vector<pair<int,int>> Intersections = CheckIntersectionPoints(vector1, vector2);
        int Sum = Sumator(Intersections, vector1, vector2);
        cout<<Sum<<endl;


        vector1.clear();
        vector2.clear();
        data>>vector_size;
    }
    return 0;
}