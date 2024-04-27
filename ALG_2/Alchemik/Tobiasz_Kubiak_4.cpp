#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const double INF = 1e18; // Wartość reprezentująca nieskończoność

void printMatrix(vector<vector<double>> &matrix, int numOfPrices)
{
    for (int i = 0; i < numOfPrices; i++)
    {
        for (int j = 0; j < numOfPrices; j++)
        {
            if (matrix[i][j] == INF)
            {
                cout << "INF\t";
            }
            else
            {
                cout << matrix[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << endl
         << endl
         << endl;
}
void CalculateBestConversion(vector<vector<double>> &matrix, int numOfPrices, vector<double> &PriceTable)
{
    // printMatrix(matrix, numOfPrices);
    vector<int> GoldToSmthElse;
    for (int i = 0; i < numOfPrices; i++)
    {
        int ConversionCost = 0;
        if (matrix[0][i] != 0 && matrix[i][0] != 0 && matrix[0][i] != INF && matrix[i][0] != INF)
        {
            ConversionCost = matrix[0][i] + (0.5 * PriceTable[i]) + matrix[i][0];
            GoldToSmthElse.push_back(ConversionCost);
        }
    }
    // Znajdz najlepsza cene na przywóz
    /*
    for (int i = 0; i < GoldToSmthElse.size(); i++)
    {
        cout << GoldToSmthElse[i] << " ";
    }
    cout << endl;
    */
    int BestPriceToEnter = 0;
    if (GoldToSmthElse.size() != 0)
    {
        BestPriceToEnter = PriceTable[0] / 2;
        for (int i = 0; i < GoldToSmthElse.size(); i++)
        {
            if (GoldToSmthElse[i] < BestPriceToEnter)
            {
                BestPriceToEnter = GoldToSmthElse[i];
            }
        }
        cout << BestPriceToEnter << endl;
    }
    else
    {
        cout << PriceTable[0] * 0.5 << endl;
    }
}
void FloydWarshall(vector<vector<double>> &matrix, int numOfPrices, vector<double> VEC_price)
{
    for (int k = 0; k < numOfPrices; k++)
    {
        for (int i = 0; i < numOfPrices; i++)
        {
            for (int j = 0; j < numOfPrices; j++)
            {
                if (matrix[i][k] < INF && matrix[k][j] < INF)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
    // printMatrix(matrix, numOfPrices);
    CalculateBestConversion(matrix, numOfPrices, VEC_price);
}

int main()
{
    int cases = 0;
    std::cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        vector<double> VEC_price;
        int numOfPrices = 0;
        std::cin >> numOfPrices;

        for (int j = 0; j < numOfPrices; j++)
        {
            double price = 0;
            std::cin >> price;
            VEC_price.push_back(price);
        }

        int transformations = 0;
        std::cin >> transformations;

        vector<vector<double>> CostTable(numOfPrices, vector<double>(numOfPrices, INF));

        for (int j = 0; j < numOfPrices; j++)
        {
            CostTable[j][j] = 0; // Koszt przejścia między tym samym punktem wynosi 0
        }

        for (int j = 0; j < transformations; j++)
        {
            int source = 0;
            int destination = 0;
            int conversionPrice = 0;
            std::cin >> source >> destination >> conversionPrice;
            CostTable[source - 1][destination - 1] = conversionPrice;
        }

        FloydWarshall(CostTable, numOfPrices, VEC_price);
    }

    return 0;
}
