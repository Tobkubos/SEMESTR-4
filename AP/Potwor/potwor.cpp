#include <iostream>
#include <vector>

using namespace std;

class BigInt
{
private:
    vector<int> digits;

public:
    BigInt(int initialValue = 0)
    {
        if (initialValue == 0)
        {
            digits.push_back(0);
        }
        else
        {
            while (initialValue != 0)
            {
                digits.push_back(initialValue % 10);
                initialValue /= 10;
            }
        }
    }

    void multiply(int factor)
    {
        int carry = 0;
        for (size_t i = 0; i < digits.size(); ++i)
        {
            int product = digits[i] * factor + carry;
            digits[i] = product % 10;
            carry = product / 10;
        }
        while (carry != 0)
        {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    friend ostream &operator<<(ostream &os, const BigInt &bigint)
    {
        for (auto it = bigint.digits.rbegin(); it != bigint.digits.rend(); ++it)
        {
            os << *it;
        }
        return os;
    }

    string getStringRepresentation() const
    {
        string resultString;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it)
        {
            resultString += to_string(*it);
        }
        return resultString;
    }
};

class FactorialCalculator
{
public:
    BigInt calculate(int n)
    {
        BigInt result(1);
        for (int i = 2; i <= n; ++i)
        {
            result.multiply(i);
        }
        return result;
    }
};

int main()
{
    FactorialCalculator calculator;

    int cases = 0;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        int n = 0;
        cin >> n;
        //string missing = "";
        //cin >> missing;
        BigInt result = calculator.calculate(n);
        string resultString = result.getStringRepresentation();
        cout<<resultString;
    }
    return 0;
}