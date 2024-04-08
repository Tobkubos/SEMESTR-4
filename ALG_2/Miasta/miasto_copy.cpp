#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void viewVec(vector<pair<pair<int,int>,int>> vec){
        for(const auto& element : vec) {
        cout <<element.first.first<<" "<<element.first.second << " : " << element.second << endl;
    }
}


void Kruskal(vector<pair<pair<int,int>,int>> &vec){
    vector<set<int>> Groups;
    set<int> idx;

    for(int i = 0; i < vec.size(); i++) {
        bool added = false;

        cout<<"SPRAWDZANA KRAWEDZ: "<<vec[i].first.first<<" "<<vec[i].first.second<<endl;

        if(i==0){
            set<int>Group;
            Group.insert(vec[0].first.first);
            Group.insert(vec[0].first.second);
            idx.insert(vec[0].first.first);
            idx.insert(vec[0].first.second);
            Groups.push_back(Group);
        }
        // Przechodzimy przez istniejące grupy
        // TU JEST ZJEBANA LOGIKA
        for(auto& element : idx){
            if(vec[i].first.first == element || vec[i].first.second == element) {
                // Jeden lub oba wierzchołki krawędzi należą do istniejącej grupy

                for(auto& group : Groups){
                    if(group.find(vec[i].first.first) != group.end()){
                        group.insert(vec[i].first.first);
                        group.insert(vec[i].first.second);
                    }
                }    
                //sprawdz czy first.first i first.second nie sa juz gdzies w różnych grupach
                //cout << "KRAWEDZ: " << vec[i].first.first << " " << vec[i].first.second << " dopisujemy do istniejacej grupy" << endl;
                idx.insert(vec[i].first.first);
                idx.insert(vec[i].first.second);
                added = true;
                }
            }
        

        if (!added) {
            // Żaden wierzchołek krawędzi nie należy do istniejącej grupy, więc tworzymy nową grupę
            set<int> Group;
            Group.insert(vec[i].first.first);
            Group.insert(vec[i].first.second);
            idx.insert(vec[i].first.first);
            idx.insert(vec[i].first.second);
            Groups.push_back(Group);
        }
    }


    
    for(int i = 0; i < Groups.size(); i++) {
        cout << "GRUPA " << i << ": ";
        for(auto element : Groups[i]) {
            cout << element << " ";
        }
        cout << endl;
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