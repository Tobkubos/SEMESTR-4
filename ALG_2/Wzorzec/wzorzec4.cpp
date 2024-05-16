#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

const int base = 256; // wartość podstawy
const int MOD = 101;

int GetHash(string pattern)
{
    int Hash = 0;
    for (int j = 0; j < pattern.size(); j++)
    {
        Hash = (Hash * base + static_cast<int>(pattern[j])) % MOD;
    }
    return Hash;
}

int RollHash(int hash, string match, int idx)
{
    hash = (hash - (static_cast<int>(match[idx - match.size()]) * static_cast<int>(pow(base, match.size() - 1)))) % MOD;
    hash = (hash * base) % MOD;
    hash = (hash + static_cast<int>(match[idx])) % MOD;
    return hash;
}

int main()
{
    string match = "GHHG";
    int hash = GetHash("GHH");
    int hash2 = GetHash("HHG");
    cout << hash << endl;
    cout << hash2 << endl;
    int rollhash = RollHash(hash, match, 3);
    cout << rollhash << endl;

    return 0;
}