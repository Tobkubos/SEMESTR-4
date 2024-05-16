#include <iostream>
#include <vector>
#include <string>

using namespace std;

// PODZIEL INPUT NA TRÓJKI
vector<string> Convert(string a)
{

    vector<string> code;
    string l = a.substr(0, 1);
    code.push_back(l);

    int size = a.size();

    for (int i = 2; i < size - 2; i += 4)
    {
        string part = a.substr(i, 3);
        code.push_back(part);
    }
    return code;
}

// ZAMIEN NA GLOWNE LITERY TROJEK
string Decode(vector<vector<string>> codes, string code)
{
    int size = code.size();
    string Decoded;
    for (int i = 0; i < size - 2; i += 3)
    {
        string d = code.substr(i, 3);
        for (const auto &element : codes)
        {
            for (const auto &element2 : element)
            {
                if (d == element2)
                {
                    Decoded.push_back(element[0][0]);
                }
            }
        }
    }
    return Decoded;
}

// STWORZ TABLICE SUFIX + PREFIX
vector<int> MakeLPS(const string &pattern)
{
    int length = pattern.length();
    vector<int> lps(length, 0);

    int j = 0;
    int i = 1;

    while (i < length)
    {
        if (pattern[i] == pattern[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KNUTH MORRIS PRATT
bool KMP(const vector<int> &LPS, const string &code, const string &pattern)
{
    int i = 0; // pozycja code
    int j = 0; // pozycja wzorzec

    while (i < code.size())
    {
        if (code[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == pattern.size()) // znalezione
        {
            cout << "String " << pattern << "found " << endl;
            return true;
        }

        if (i < code.size() && code[i] != pattern[j])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    cout << "NONE" << endl;
    return false;
}

int main()
{
    int cases = 0;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        int amino = 0;
        cin >> amino;
        vector<vector<string>> AllCodes;

        for (int j = 0; j < amino; j++)
        {
            string aminoacid;
            getline(cin >> ws, aminoacid);
            vector<string> vec = Convert(aminoacid);
            AllCodes.push_back(vec);
        }
        string code;
        cin >> code;
        string decoded = Decode(AllCodes, code);
        cout << "DECODED " << endl
             << decoded << endl;
    }

    return 0;
}
