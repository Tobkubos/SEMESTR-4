#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int base = 11;

void ShowAll(vector<vector<string>> a, string code, string decoded)
{
    for (const auto &element : a)
    {
        for (const auto &element2 : element)
        {
            cout << element2 << " ";
        }
        cout << endl;
    }
    cout << "code    " << code << endl;
    cout << "decoded " << decoded << endl;
}
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

// KARP RABIN
long long int GetHash(string pattern)
{
    long long int Hash = 0;
    for (int j = 0; j < pattern.size(); j++)
    {
        Hash += static_cast<int>(pattern[j]) + pow(base, pattern.size() - j - 1);
    }
    return Hash;
}

int RollHash(long long int hash, string match, int idx)
{
    return hash - (static_cast<int>(match[idx - match.size()]) * pow(base, match.size() - 1)) * 255 + static_cast<int>(match[idx]);
}

string KarpRabin(string text, string pattern)
{
    int patternHash = GetHash(pattern);
    int matchHash = GetHash(text);

    cout << "Pattern Hash value " << patternHash << endl;
    int count = 0;

    for (int i = 0; i < text.size() - pattern.size() + 1; i++)
    {
        string check = text.substr(i, pattern.size());

        int checkHash = 0;

        for (int j = 0; j < check.size(); j++)
        {
            checkHash += check[j] * (j + 1);
        }

        bool isGood = true;
        if (patternHash == checkHash)
        {
            for (int j = 0; j < pattern.size(); j++)
            {
                if (pattern[j] != check[j])
                {
                    isGood = false;
                }
            }
            if (isGood)
            {
                cout << "Znaleziono w " << i << endl;
                count++;
                if (count == 2)
                    return pattern;
            }
        }
    }
    return "brak";
}

int main()
{
    string match = "GHHG";
    long long int hash = GetHash("GHH");
    long long int hash2 = GetHash("HHG");
    cout << hash << endl;
    cout << hash2 << endl;
    long long int Rollhash = RollHash(hash, match, 3);
    cout << RollHash << endl;

    /*
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
        ShowAll(AllCodes, code, decoded);

        int index = decoded.size() / 2;

        while (index > 1)
        {
            for (int j = 0; j < decoded.size() - index + 1; j++)
            {
                string pattern = decoded.substr(j, index);
                cout << KarpRabin(decoded, pattern) << endl;
            }
            index--;
        }
    }
    */
    return 0;
}