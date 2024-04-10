#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void viewVec(vector<pair<pair<int,int>,int>> vec){
        for(const auto& element : vec) {
        std::cout <<element.first.first<<" "<<element.first.second << " : " << element.second << endl;
    }
}


bool checkNext(const vector<int>& disjoint, const vector<pair<pair<int,int>,int>>& vec, int i, int j);

void Kruskal(vector<pair<pair<int,int>,int>> &vec) {
    vector<int> Roads;
    vector<pair<int, int>> resultEdges; // Pary wierzchołków dróg w minimalnym drzewie rozpinającym
    vector<int> disjoint(vec.size(), -1); // Inicjalizacja tablicy do zbiorów rozłącznych

    for (int i = 0; i < vec.size(); i++) {
        if (disjoint[vec[i].first.first] == disjoint[vec[i].first.second]) {
            disjoint[vec[i].first.second] += -1;
            disjoint[vec[i].first.first] = vec[i].first.second;
            Roads.push_back(vec[i].second);
            resultEdges.push_back(vec[i].first);
        } else if (disjoint[vec[i].first.first] > 0) {
            int j = -1;
            j = disjoint[vec[i].first.first];
            if (checkNext(disjoint, vec, i, j)) {
                Roads.push_back(vec[i].second);
                resultEdges.push_back(vec[i].first);
            }
        }
    }

    // Wypisywanie minimalnego drzewa rozpinającego
    cout << "Minimalne drzewo rozpinające:" << endl;
    for (int i = 0; i < Roads.size(); i++) {
        cout << "Krawędź: " << resultEdges[i].first << " - " << resultEdges[i].second << ", waga: " << Roads[i] << endl;
    }
}

bool checkNext(const vector<int>& disjoint, const vector<pair<pair<int,int>,int>>& vec, int i, int j) {
    if (disjoint[j] < 0 && disjoint[j] != disjoint[vec[i].first.second]) {
        return true; 
    }
    return false;
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
            //cout<<"DODALEM PIERWSZY ELEMENT"<<endl;
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

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        cout<<endl<<endl;
        viewVec(vec);
        cout<<endl<<endl;
        Kruskal(vec);
    }


    return 0;
}