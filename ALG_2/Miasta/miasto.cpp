#include <iostream>
#include <vector>

using namespace std;

void viewVec(vector<pair<pair<int,int>,int>> vec){
        for(const auto& element : vec) {
        cout <<element.first.first<<" "<<element.first.second << " : " << element.second << endl;
    }
}

int main(){

    int cases =0;

    cin>>cases;

    for(int i =0; i<cases; i++){
        vector<pair<pair<int,int>,int>> vec;

        int cities = 0;
        int roads = 0;
        bool firstAdd = true;
        cin>>cities>>roads;

        for(int j = 0; j<roads; j++){
            int city1   = 0;
            int city2   = 0;
            int roadVal = 0;
            bool connectionExists = false;

            cin>>city1>>city2>>roadVal;
            
            pair<pair<int,int>,int> connection; 

            //uloz miasta tak aby index byl rosnacy
            if (city1 > city2){
                swap(city1, city2);
            }
            connection.first.first = city1;
            connection.first.second = city2;
            connection.second = roadVal;

            if(firstAdd){
            vec.push_back(connection);
            firstAdd = false;
            connectionExists = true;
            cout<<"DODALEM PIERWSZY ELEMENT"<<endl;
            }


            for(auto& element : vec){
                if(element.first.first == connection.first.first && element.first.second == connection.first.second){
                    if(element.second <= connection.second){
                        //cout<<"JEST LEPSZA SCIEZKA!"<<endl;
                        connectionExists = true;
                        connection.second = element.second;
                    }
                }
            }

            if(!connectionExists){
                vec.push_back(connection);
            }
        }
        viewVec(vec);
    }


    return 0;
}