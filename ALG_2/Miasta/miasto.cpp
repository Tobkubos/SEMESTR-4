#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool checkNext(vector<int> &disjoint, int source, int destination);

void Kruskal(vector<pair<pair<int, int>, int>> &vec)
{
    vector<int> Roads;
    vector<pair<int, int>> resultEdges;   // Pary wierzcholkow drog w MST
    vector<int> disjoint(vec.size(), -1); // Inicjalizacja tablicy laczen

    for (int i = 0; i < vec.size(); i++)
    {
        if (checkNext(disjoint, vec[i].first.first, vec[i].first.second))
        {
            disjoint[vec[i].first.first] = vec[i].first.second;
            Roads.push_back(vec[i].second);
            resultEdges.push_back(vec[i].first);
        }
    }

    // Wypisywanie minimalnego drzewa rozpinajacego
    int maxRoad = *max_element(Roads.begin(), Roads.end());
    std::cout << maxRoad << std::endl;
}

bool checkNext(vector<int> &disjoint, int source, int destination)
{
    int sourceRoot = source;
    while (disjoint[sourceRoot] != -1)
    {
        sourceRoot = disjoint[sourceRoot];
    }

    int destinationRoot = destination;
    while (disjoint[destinationRoot] != -1)
    {
        destinationRoot = disjoint[destinationRoot];
    }

    if (sourceRoot == destinationRoot)
    {
        return false; // Tworzy cykl
    }

    disjoint[sourceRoot] = destinationRoot; // Unia zbiorow
    return true;
}

int main()
{

    int cases = 0;

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        vector<pair<pair<int, int>, int>> vec;

        int cities = 0;
        int roads = 0;
        bool firstAdd = true;
        cin >> cities >> roads;

        for (int j = 0; j < roads; j++)
        {
            int city1 = 0;
            int city2 = 0;
            int roadVal = 0;
            bool connectionExists = false;

            cin >> city1 >> city2 >> roadVal;

            pair<pair<int, int>, int> connection;

            // uloz miasta tak aby index byl rosnacy
            if (city1 > city2)
            {
                swap(city1, city2);
            }
            connection.first.first = city1;
            connection.first.second = city2;
            connection.second = roadVal;

            if (firstAdd)
            {
                vec.push_back(connection);
                firstAdd = false;
                connectionExists = true;
                // cout<<"DODALEM PIERWSZY ELEMENT"<<endl;
            }

            for (auto &element : vec)
            {
                if (element.first.first == connection.first.first && element.first.second == connection.first.second)
                {
                    if (element.second <= connection.second)
                    {
                        // cout<<"JEST LEPSZA SCIEZKA!"<<endl;
                        connectionExists = true;
                        connection.second = element.second;
                    }
                }
            }

            if (!connectionExists)
            {
                vec.push_back(connection);
            }
        }

        sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
             { return a.second < b.second; });
        Kruskal(vec);
    }

    return 0;
}