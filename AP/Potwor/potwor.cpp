#include <iostream>
#include <vector>

class BigInt
{
private:
    std::vector<int> digits;

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

    friend std::ostream &operator<<(std::ostream &os, const BigInt &bigint)
    {
        for (auto it = bigint.digits.rbegin(); it != bigint.digits.rend(); ++it)
        {
            os << *it;
        }
        return os;
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
    int n = 10000;
    BigInt result = calculator.calculate(n);
    std::cout << n << "! = " << result << std::endl;
    return 0;
}