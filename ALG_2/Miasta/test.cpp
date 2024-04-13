#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void viewVec(vector<pair<pair<int, int>, int>> vec)
{
    for (const auto &element : vec)
    {
        std::cout << element.first.first << " " << element.first.second << " : " << element.second << endl;
    }
}

bool checkNext(vector<int> &disjoint, int source, int destination);

void Kruskal(vector<pair<pair<int, int>, int>> &vec, int numCities)
{
    if (numCities == 1)
    {
        cout << vec[numCities - 1].second << endl; // Brak dróg
        return;
    }
    else if (numCities == 2)
    {
        if (vec.empty())
        {
            cout << "Brak dróg" << endl;
            return;
        }
        else
        {
            cout << vec[0].second << endl; // Dla dwóch miast tylko jedna droga
            return;
        }
    }

    sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    vector<int> disjoint(numCities, -1);

    vector<pair<int, int>> resultEdges; // Pary wierzcholkow drog w MST
    vector<int> Roads;

    for (const auto &edge : vec)
    {
        if (checkNext(disjoint, edge.first.first, edge.first.second))
        {
            disjoint[edge.first.first] = edge.first.second;
            Roads.push_back(edge.second);
            resultEdges.push_back(edge.first);
        }
    }

    // Wypisywanie minimalnego drzewa rozpinajacego
    int maxRoad = *max_element(Roads.begin(), Roads.end());
    cout << maxRoad << endl;
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
            /*
            if (firstAdd)
            {
                vec.push_back(connection);
                firstAdd = false;
                connectionExists = true;
                // cout<<"DODALEM PIERWSZY ELEMENT"<<endl;
            }
            */

            for (auto &element : vec)
            {
                if (element.first.first == connection.first.first && element.first.second == connection.first.second)
                {
                    connectionExists = true;
                    if (element.second > connection.second)
                    {
                        // cout<<"JEST LEPSZA SCIEZKA!"<<endl;
                        element.second = connection.second;
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

        cout << endl
             << endl;
        viewVec(vec);
        cout << endl
             << endl;
        Kruskal(vec, cities);
    }

    return 0;
}