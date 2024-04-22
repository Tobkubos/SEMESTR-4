#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void FindTempTable(int m, int n, vector<int>& a, vector<int>& tempT, vector<vector<int>>& finT)
{
    int pickedI = -1;
    for(int i=0; i<n; i++)
    {
        if(m-a[i]>=0)
        {
            pickedI = i;
            tempT.push_back(i);
            FindTempTable(m-a[i],n,a,tempT,finT);
            tempT.pop_back();
        }      
    }

    finT.push_back(tempT);
}

int findMax(vector<vector<int>>& finT, vector<int>& b, int m)
{
    vector<int> suma;
    for (const auto& innerVector : finT) 
    {
        int sum = m;
        for (int element : innerVector) 
        {
            sum += b[element];
        }
        suma.push_back(sum);
    }

    auto maxElementIterator = max_element(suma.begin(), suma.end());
    return *maxElementIterator;
}

int main()
{
    int cases = 0;
    cin >> cases;
    for(int i = 0; i<cases;i++){
        double money = 0;
        double years = 0;
        cin>>money>>years;
        double obli = 0;
        cin>>obli;
        vector<int> price;
        vector<int> income;
        for(int j =0; j<obli; j++){
            int obli_price = 0;
            int obli_income = 0;
            cin>>obli_price>>obli_income;
            price.push_back(obli_price);
            income.push_back(obli_income);
        }


        vector<int> tempTable;
        vector<vector<int>> finalTable;

        for(int i=0; i<years; i++)
        {
            FindTempTable(money,price.size(),price,tempTable,finalTable);
            money = findMax(finalTable,income,money);
        }

        cout << money<<endl;   
    }


    return 0;
}