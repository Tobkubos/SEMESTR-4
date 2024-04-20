#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<pair<int, double>> CalculateEfficiency(vector<pair<double, double>> bonds)
{
    vector<pair<int, double>> BondsEfficiency;

    for (int i = 0; i < bonds.size(); i++)
    {
        pair<int, double> bondEff;
        bondEff.first = bonds[i].first;
        bondEff.second = bonds[i].second / bonds[i].first;
        BondsEfficiency.push_back(bondEff);
    }

    for (int i = 0; i < BondsEfficiency.size(); i++)
    {
        cout << BondsEfficiency[i].first << " " << BondsEfficiency[i].second << endl;
    }

    auto compareSecond = [](const pair<int, double> &a, const pair<int, double> &b)
    {
        return a.second > b.second;
    };

    sort(BondsEfficiency.begin(), BondsEfficiency.end(), compareSecond);
    return BondsEfficiency;
}

void Investment(vector<pair<double, double>> bonds, vector<pair<int, double>> efficiency, int years, int Capital)
{
    for (int i = 0; i < years; i++)
    {
        // buy
        bool canBuy = true;
        vector<pair<int, double>> bought;
        while (canBuy)
        {
            for (int j = 0; j < efficiency.size(); j++)
            {
                if (Capital >= efficiency[i].first)
                {
                    Capital -= efficiency[i].first;
                    bought.push_back(efficiency[i]);
                }
                else
                {
                    canBuy = false;
                    break;
                }
            }
            // wypis kontrolny
            for (int i = 0; i < bought.size(); i++)
            {
                cout << i << " " << bought[i].first << " " << bought[i].second << endl;
            }
        }
        // gain

        // sell
    }
}

int main()
{

    int cases = 0;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        double Capital = 0;
        double years = 0;
        double numOfBonds = 0;
        vector<pair<double, double>> Bonds;
        cin >> Capital;
        cin >> years;
        cin >> numOfBonds;
        for (int j = 0; j < numOfBonds; j++)
        {
            pair<double, double> Bond;
            int money = 0;
            int profit = 0;
            cin >> money >> profit;
            Bond.first = money;
            Bond.second = profit;
            Bonds.push_back(Bond);
        }
        vector<pair<int, double>> eff = CalculateEfficiency(Bonds);
        Investment(Bonds, eff, years, Capital);
    }

    return 0;
}