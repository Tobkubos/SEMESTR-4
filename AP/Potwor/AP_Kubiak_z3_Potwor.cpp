#include <iostream>
#include <cctype>
#include <string>

using namespace std;
void FindFactorial();
bool CheckNumbers1(int,int,string);
bool CheckNumbers2(int,int,string);

int main()
{
    int tests = 0;
    cin >> tests;

    for(int i=0; i<tests; i++)
    {
        FindFactorial();
    }
    
    return 0;
}

void FindFactorial()
{
    long int factor;
    cin >> factor;
    string digits;
    cin >> digits;

    int a = -1, b = -1;

    for(int i=0; i<10; i++)
    {
        a++;
        for(int j=0; j<10; j++)
        {
            b++;
            if(CheckNumbers1(a,b,digits) && CheckNumbers2(a,b,digits))
            {
                cout << a << " " << b << endl;
                return;
            }
        }
        b=-1;
    }
}

bool CheckNumbers1(int a,int b,string digits)
{
    long int sum = 0;
    for (int i=0; i<digits.length(); i++) 
    {
        if (isdigit(digits[i])) 
        { 
            sum += digits[i] - '0'; 
        }
        else if(digits[i] == 'a')
        {
            sum += a;
        }
        else if(digits[i] == 'b')
        {
            sum += b;
        }
    }

    if(sum%3 == 0)
    {
        return true;
    }

    return false;
}

bool CheckNumbers2(int a,int b,string digits)
{
    long int sum1 = 0, sum2 = 0;
    for(int i=0; i<digits.length(); i+=2)
    {
        if (isdigit(digits[i])) 
        { 
            sum1 += digits[i] - '0'; 
        }
        else if(digits[i] == 'a')
        {
            sum1 += a;
        }
        else if(digits[i] == 'b')
        {
            sum1 += b;
        }
    }

    for(int i=1; i<digits.length(); i+=2)
    {
        if (isdigit(digits[i])) 
        { 
            sum2 += digits[i] - '0'; 
        }
        else if(digits[i] == 'a')
        {
            sum2 += a;
        }
        else if(digits[i] == 'b')
        {
            sum2 += b;
        }
    }

    if((sum1-sum2) % 11 == 0)
    {
        return true;
    }

    return false;
}