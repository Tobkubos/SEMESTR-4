
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>

using namespace std;

void topologicalSortStep(char v, map<char, vector<char>> &graph, map<char, bool> &visited, stack<char> &s)
{
    // cout << v << " ";
    visited[v] = true;
    for (char neighbor : graph[v])
    {
        if (!visited[neighbor])
        {
            topologicalSortStep(neighbor, graph, visited, s);
        }
    }
    s.push(v);
}

void topologicalSort(map<char, vector<char>> &graph, int sizeOfTheAlphabet, vector<char> alphabet, string message)
{
    map<char, bool> visited;
    stack<char> s;
    //////////
    // TEST
    set<char> start1;
    set<char> start2;
    for (auto i : graph)
    {
        start1.insert(i.first);
        for (auto j : i.second)
        {
            start2.insert(j);
        }
    }
    /*
        for (auto i : start1)
        {
            cout << i << " ";
        }

        cout << endl;

        for (auto k : start2)
        {
            cout << k << " ";
        }
        cout << endl;
    */
    // ZNAJDUJE WIERZCHOLEK BEZ RODZICOW
    set<char> notIn;

    for (auto i : start1)
    {
        bool found = false;
        for (auto j : start2)
        {
            if (i == j)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            notIn.insert(i);
        }
    }
    /*
        for (auto i : notIn)
        {
            cout << i << " ";
        }
        */

    if (notIn.size() == 1)
    {

        for (auto i : graph)
        {
            visited[i.first] = false;
        }

        for (auto i : graph)
        {

            for (auto j : notIn)
            {
                if (!visited[i.first])
                {
                    topologicalSortStep(j, graph, visited, s);
                }
            }
        }

        if (s.size() == sizeOfTheAlphabet)
        {
            // WYPISUJE KOLEJNOSC ALFABETU

            /*
            while (!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
            */
            map<char, char> DescryptedAlphabet;
            int i = 0;
            while (!s.empty())
            {
                DescryptedAlphabet[s.top()] = alphabet[i];
                i++;
                s.pop();
            }
            /*
            for (auto da : DescryptedAlphabet)
            {
                cout << da.first << " " << da.second << endl;
            }
            */

            for (int i = 0; i < message.size(); i++)
            {
                cout << DescryptedAlphabet[message[i]];
            }
            cout << endl;
        }
        else
        {
            cout << "Message cannot be decrypted" << endl;
        }
    }
    if (notIn.size() != 1)
    {
        cout << "Message cannot be decrypted" << endl;
    }
}

void Cipher(vector<string> tab, int sizeOfTheAlphabet, vector<char> alphabet, string message)
{
    set<pair<char, char>> pairs;
    map<char, vector<char>> graf;

    // ZALEZNOSCI
    for (int i = 1; i < tab.size(); i++)
    {
        //
        int sizeOfWord1 = tab[i - 1].size();
        int sizeOfWord2 = tab[i].size();
        int SmallestOfPair = 0;
        // cout << sizeOfWord1 << " " << sizeOfWord2 << endl;
        //
        if (sizeOfWord1 >= sizeOfWord2)
        {
            SmallestOfPair = sizeOfWord2;
        }
        else
        {
            SmallestOfPair = sizeOfWord1;
        }

        for (int j = 0; j < SmallestOfPair; j++)
        {
            if (tab[i - 1][j] != tab[i][j])
            {
                pairs.insert(pair<char, char>(tab[i - 1][j], tab[i][j]));
                break;
            }
        }
    }

    ///////////////

    // ZALEZNOSCI W GRAFIE
    for (auto para : pairs)
    {
        // cout << para.first << "-->" << para.second << endl;
        graf[para.first].push_back(para.second);
    }
    /*
    // WYPIS SASIADOW
    for (auto key : graf)
    {
        cout << key.first << ": ";
        for (auto neighbours : key.second)
        {
            cout << neighbours << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl
         << endl;
    */
    // SORTOWANIE
    topologicalSort(graf, sizeOfTheAlphabet, alphabet, message);
}

int main()
{
    int cases;
    vector<char> alphabet = {
        'A',
        'B',
        'C',
        'D',
        'E',
        'F',
        'G'};

    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int SizeOfAlphabet;
        cin >> SizeOfAlphabet;

        int EncryptedWords;
        cin >> EncryptedWords;
        vector<string> tab;

        for (int j = 0; j < EncryptedWords; j++)
        {
            string word;
            cin >> word;
            tab.push_back(word);
        }
        string message;
        cin >> message;
        Cipher(tab, SizeOfAlphabet, alphabet, message);
    }

    return 0;
}