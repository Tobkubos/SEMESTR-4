#include <iostream>
#include <vector>
#include <string>

using namespace std;

// PODZIEL INPUT NA TROJKI
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
        if (pattern[i] == pattern[j]) // jest match, przesuwam oba i ustawiam LPS
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1]; // cofam sie
            }
            else
            {
                lps[i] = 0; // brak sufix/prefix
                i++;
            }
        }
    }

    return lps;
}

// KNUTH MORRIS PRATT
bool KMP(const vector<int> &LPS, const string &code, const string &pattern)
{
    int i = 0; // pozycja w code
    int j = 0; // pozycja we wzorcu

    bool found = false; // czy znaleziony 2 razy

    while (i < code.size())
    {
        if (code[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == pattern.size()) // znalazlem
        {
            if (found)
            {
                cout << pattern << endl;
                return true;
            }
            found = true;
            j = LPS[j - 1]; // Przesuń indeks j na koniec poprzedniego wzorca
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
    return false; // Jeśli nie znaleziono 2 wzorcow = false
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
        // cout << "decoded " << endl << decoded << endl;

        // OPERACJA WYWOŁYWANIA KMP
        bool found = false;
        int patternSize = decoded.size() - 1;
        while (patternSize > 0 && !found) // wczesniej 1
        {
            for (int j = 0; j <= decoded.size() - patternSize; j++)
            {
                string pattern = decoded.substr(j, patternSize);
                vector<int> LPS = MakeLPS(pattern);
                if (KMP(LPS, decoded, pattern))
                {
                    found = true;
                    break; // break for
                }
            }
            if (found)
            {
                break; // break while
            }
            patternSize--;
        }
        if (!found)
        {
            cout << "brak" << endl;
        }
    }

    return 0;
}
