#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> &disjoint, int node)
{
    if (disjoint[node] != node)
    {
        disjoint[node] = find(disjoint, disjoint[node]); // Path compression
    }
    return disjoint[node];
}

void unionSets(vector<int> &disjoint, int sourceRoot, int destinationRoot)
{
    disjoint[sourceRoot] = destinationRoot; // Union operation
}

void Kruskal(vector<pair<pair<int, int>, int>> &edges, int numCities)
{
    vector<int> disjoint(numCities);
    for (int i = 0; i < numCities; i++)
    {
        disjoint[i] = i; // Each node is its own parent initially
    }

    vector<pair<int, int>> mst; // To store the result edges

    // Sorting edges by weight
    sort(edges.begin(), edges.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    for (auto &edge : edges)
    {
        int src = edge.first.first;
        int dest = edge.first.second;
        int srcRoot = find(disjoint, src);
        int destRoot = find(disjoint, dest);

        if (srcRoot != destRoot)
        {
            mst.push_back({src, dest});
            unionSets(disjoint, srcRoot, destRoot);
        }
    }

    // Outputting the edges of the MST
    for (auto &edge : mst)
    {
        cout << "Edge from " << edge.first << " to " << edge.second << endl;
    }
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int numCities, numRoads;
        cin >> numCities >> numRoads;
        vector<pair<pair<int, int>, int>> edges;

        for (int i = 0; i < numRoads; i++)
        {
            int city1, city2, weight;
            cin >> city1 >> city2 >> weight;
            if (city1 > city2)
            {
                swap(city1, city2);
            }
            edges.push_back({{city1, city2}, weight});
        }

        Kruskal(edges, numCities);
    }
    return 0;
}