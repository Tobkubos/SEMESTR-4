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
    // printMatrix(matrix, numOfPrices);
    vector<double> GoldToSmthElse;
    for (int i = 0; i < numOfPrices; i++)
    {
        double ConversionCost = 0;
        if (matrix[0][i] != 0 && matrix[i][0] != 0)
        {
            // SPRAWDZ TO
            ConversionCost = matrix[0][i] + (0.5 * PriceTable[i]) + matrix[i][0];
            GoldToSmthElse.push_back(ConversionCost);
        }
    }
    // Znajdz najlepsza cene na przywóz

    for (int i = 0; i < GoldToSmthElse.size(); i++)
    {
        cout << GoldToSmthElse[i] << " ";
    }
    cout << endl;

    double BestPriceToEnter = 0;
    if (GoldToSmthElse.size() != 0)
    {
        BestPriceToEnter = GoldToSmthElse[0];
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
        cout << PriceTable[0] * 0.5;
    }
}

void FloydWarshall(vector<vector<double>> &matrix, int numOfPrices, vector<double> &PriceTable)
{
    // printMatrix(matrix, numOfPrices);
    for (int k = 0; k < numOfPrices; k++)
    {
        for (int i = 0; i < numOfPrices; i++)
        {
            for (int j = 0; j < numOfPrices; j++)
            {
                if ((matrix[i][k] * matrix[k][j] != 0) && (i != j))
                {
                    if ((matrix[i][k] + matrix[k][j] < matrix[i][j]) || (matrix[i][j] == 0))
                    {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }
    /*
    for (int k = 0; k < numOfPrices; k++)
    {
        for (int i = 0; i < numOfPrices; i++)
        {
            if (matrix[k][i] >= INT_MAX)
            {
                matrix[k][i] = 0;
            }
        }
    }
    */
    // printMatrix(matrix, numOfPrices);
    //  printMatrix(matrix, numOfPrices);
    CalculateBestConversion(matrix, numOfPrices, PriceTable);
}

int main()
{
    int cases = 0;
    std::cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        vector<double> VEC_price; // WEKTOR CEN
        int numOfPrices = 0;      // ILOŚĆ CEN

        std::cin >> numOfPrices;

        for (int j = 0; j < numOfPrices; j++)
        {
            double price = 0;
            std::cin >> price;
            VEC_price.push_back(price);
        }
        for (int j = 0; j < numOfPrices; j++)
        {
            cout << VEC_price[j] << " ";
        }
        cout << endl;
        //
        //
        int transformations = 0; // ILOSC TRANSFORMACJI
        std::cin >> transformations;
        //
        //
        //
        // INICJALIZACJA MACIERZY KOSZTÓW PRZEJŚĆ

        vector<vector<double>> CostTable;
        for (int j = 0; j < numOfPrices; j++)
        {
            vector<double> row;
            for (int k = 0; k < numOfPrices; k++)
            {
                row.push_back(INT_MAX);
            }
            CostTable.push_back(row);
        }

        for (int j = 0; j < numOfPrices; j++)
        {
            for (int k = 0; k < numOfPrices; k++)
            {
                if (j == k)
                {
                    CostTable[j][k] = 0;
                }
            }
        }

        for (int j = 0; j < transformations; j++)
        {
            int source = 0;          // START
            int destination = 0;     // META
            int conversionPrice = 0; // CENA ZA KONWERSJE
            std::cin >> source >> destination >> conversionPrice;
            CostTable[source - 1][destination - 1] = conversionPrice;
        }

        FloydWarshall(CostTable, numOfPrices, VEC_price);
    }

    return 0;
}