#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

void printMatrix(vector<vector<double>> &matrix, int numOfPrices)
{
    for (int i = 0; i < numOfPrices; i++)
    {
        for (int j = 0; j < numOfPrices; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl
         << endl
         << endl;
}

void CalculateBestConversion(vector<vector<double>> &matrix, int numOfPrices, vector<double> &PriceTable)
{
    vector<double> GoldToSmthElse;
    for (int i = 0; i < numOfPrices; i++)
    {
        double ConversionCost = 0;
        if (matrix[0][i] > 0 && matrix[i][0] > 0)
        {
            ConversionCost = matrix[0][i] + (0.5 * PriceTable[i]) + matrix[i][0];
            GoldToSmthElse.push_back(ConversionCost);
        }
    }

    double BestPriceToEnter = 0;
    if (!GoldToSmthElse.empty())
    {
        BestPriceToEnter = *min_element(GoldToSmthElse.begin(), GoldToSmthElse.end());
    }
    cout << BestPriceToEnter << endl;
}

void FloydWarshall(vector<vector<double>> &matrix, int numOfPrices, vector<double> &PriceTable)
{
    for (int k = 0; k < numOfPrices; k++)
    {
        for (int i = 0; i < numOfPrices; i++)
        {
            for (int j = 0; j < numOfPrices; j++)
            {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j] && matrix[i][k] > 0 && matrix[k][j] > 0)
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }
    }
    CalculateBestConversion(matrix, numOfPrices, PriceTable);
}

int main()
{
    int cases = 0;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        vector<double> VEC_price; // WEKTOR CEN
        int numOfPrices = 0;      // ILOŚĆ CEN

        cin >> numOfPrices;

        for (int j = 0; j < numOfPrices; j++)
        {
            double price = 0;
            cin >> price;
            VEC_price.push_back(price);
        }

        int transformations = 0; // ILOSC TRANSFORMACJI
        cin >> transformations;

        // INICJALIZACJA MACIERZY KOSZTÓW PRZEJŚĆ
        vector<vector<double>> CostTable(numOfPrices, vector<double>(numOfPrices, 0));

        for (int j = 0; j < transformations; j++)
        {
            int source = 0;          // START
            int destination = 0;     // META
            int conversionPrice = 0; // CENA ZA KONWERSJE
            cin >> source >> destination >> conversionPrice;
            CostTable[source - 1][destination - 1] = conversionPrice;
        }

        FloydWarshall(CostTable, numOfPrices, VEC_price);
    }

    return 0;
}
