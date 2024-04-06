#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

void addToSet(int i, int j, set<pair<int, int>> &pairs)
{
    pair<int, int> temp = {i, j};
    pair<int, int> temp2 = {j, i};

    auto it1 = pairs.find(temp);
    auto it2 = pairs.find(temp2);

    if (it1 != pairs.end() || it2 != pairs.end())
    {
        cout << temp.first << " " << temp.second << "juz jest" << endl;
    }
    else
    {
        pairs.insert(temp);
    }
}

int Calculate(vector<int> vec)
{
    set<pair<int, int>> pairs;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[i] != vec[j])
            {
                // Sprawdź czy można skrócić ułamek vec[i]/vec[j] do najprostszej postaci
                int gcd_val = __gcd(vec[i], vec[j]);

                int temp_num1 = vec[i] / gcd_val;
                int temp_num2 = vec[j] / gcd_val;

                if (vec[j] == 5 || vec[j] == 2)
                {
                    addToSet(vec[i], vec[j], pairs);
                }

                if (gcd_val != 1)
                {
                    if (temp_num2 % 5 == 0 || temp_num2 % 2 == 0)
                    {
                        addToSet(vec[i], vec[j], pairs);
                    }
                }
            }
        }
    }

    for (const auto &pair : pairs)
    {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
}

int main()
{
    int cases = 0;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int numOfNumbers = 0;
        cin >> numOfNumbers;
        vector<int> vec;
        for (int j = 0; j < numOfNumbers; j++)
        {
            int num = 0;
            cin >> num;
            vec.push_back(num);
        }
        Calculate(vec);
    }

    return 0;
}