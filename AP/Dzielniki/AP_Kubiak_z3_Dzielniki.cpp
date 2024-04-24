#include <iostream>
#include <vector>
#include <map>
using namespace std;

void divide(const map<int, int> &numMap)
{
    int result = 0;
    for(auto mapIt1 = numMap.begin(); mapIt1 != numMap.end(); mapIt1++)
    {
        auto mapIt2 = numMap.begin();
        while(mapIt2 != mapIt1)
        {
            if (mapIt1->first % mapIt2->first == 0)
            {
                result =result+(mapIt2->second*mapIt1->second);
            }
            mapIt2++;
        }
    }

    for(auto mapIt1 : numMap)
    {
        result += mapIt1.second * (mapIt1.second - 1);
    }
    cout << result << endl;
}

int main()
{

    int cases = 0;
    cin >> cases;
    for(int i =0; i< cases; i++)
    {
        int numbers = 0;
        cin >> numbers;

        map<int, int> numMap;
        for(int j  = 0; j<numbers; j++)
        {
            int temp = 0;
            cin>>temp;
            numMap[temp]++;
        }
        divide(numMap);
    }

    return 0;
}