
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <stack>

using namespace std;

void Cipher(vector<string> tab)
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

    for (auto para : pairs)
    {
        cout << para.first << "-->" << para.second << endl;
        graf[para.first].push_back(para.second);
    }

    cout << endl
         << endl;

    for (auto key : graf)
    {
        cout << key.first << " ";
        for (auto neighbours : key.second)
        {
            cout << neighbours << " ";
        }
        cout << endl;
    }
}

int main()
{
    int cases;

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
        Cipher(tab);
    }

    return 0;
}