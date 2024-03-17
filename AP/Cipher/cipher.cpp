// CIPHER - SZYFROWANIE
// 1. szyfr podstawieniowy - jeden znak zastepujemy innym
// wazne jest to co jest aflfabetem
// A -znaków - pierwsze znaki alfabetu, tylko małe litery
// od (a do - N'tej literki)
// abcde
// nieszyfrowane - prz. leksykograficzny
// cebdbac
// cac
// ecd
// dca
// aba
// bac
//
// zaszyfrowane - cedab
//
// pierwsze jest slowo na c wiec usawiany c w tablicy na pierwsza pozycje, itd az do utrworzenia alfabetu
// c nie musi byc pierwsze, ale ogolnie musi byc, co jest wczesniej co jest pozniej
// K co najmniej rowne A+1
//
//
// robimy rownania liter jak z alfabetu
// np. d < c
// potem sprawdzamy ktorej litery nie ma po prawej stronie
// i tej której nie ma zapisujemy do tablicy
//
// GRAF SKIEROWANY i sortowanie topologiczne - EZ WIN
// Algorytm Kanna
//
// brak odpowiedzi gdy w grafie nie ma wsyzstkich znakow
// lub wystepuje cykl
//
//
//
//
//
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>

using namespace std;

void topologicalSortStep(char v, unordered_map<char, vector<char>> &graph, unordered_map<char, bool> &visited, stack<char> &s)
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

void topologicalSort(unordered_map<char, vector<char>> &graph, int sizeOfTheAlphabet, vector<string> alphabet)
{
    unordered_map<char, bool> visited;
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

    for (auto i : notIn)
    {
        cout << i << " ";
    }
    //
    //
    //
    //
    //
    //
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
            cout << endl
                 << "KOLEJKA" << endl;
            /*
            while (!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
            */
            for (int i = 0; i < s.size(); i++)
            {
                cout << alphabet[i];
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

void Cipher(vector<string> tab, int sizeOfTheAlphabet, vector<string> alphabet)
{
    set<pair<char, char>> pairs;
    unordered_map<char, vector<char>> graf;
    ///////////////

    // SPRAWDZANIE

    int longestSize = 0;
    for (int i = 0; i < tab.size(); i++)
    {
        int temp = 0;
        temp = tab[i].size();
        if (temp > longestSize)
        {
            longestSize = temp;
        }
    }

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

    for (auto para : pairs)
    {
        cout << para.first << "-->" << para.second << endl;
        graf[para.first].push_back(para.second);
    }

    cout << endl
         << endl
         << endl;

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

    topologicalSort(graf, sizeOfTheAlphabet, alphabet);
}

int main()
{
    int cases;
    vector<string> alphabet = {
        "A",
        "B",
        "C",
        "D",
        "E",
        "F",
        "G",
        "H",
        "I",
        "J",
        "K",
        "L",
        "M",
        "N",
        "O",
        "P",
        "R",
        "S",
    };

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
        Cipher(tab, SizeOfAlphabet, alphabet);
    }

    return 0;
}