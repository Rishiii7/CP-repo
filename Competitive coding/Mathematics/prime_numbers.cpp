#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

/*
Prime function :- Efficient method
Time complexity :- 3x faster than O(sqrt(n))
*/

bool isPrime_MostEfficientMethod(int n)
{
    if ( n == 1 || n == 2 || n == 3)
    {
        return true;
    }

    if ( n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    for (int i = 5 ; i * i <= n ; i = i + 6)
    {
        if ( n % i == 0 || n % (i+2) == 0)
        {
            return false;
        }
    }

    return true;
}


/*
Prime function :- Efficient method
Time complexity :- O(sqrt(n))
*/

bool isPrime_EfficientMethod(int a)
{
    if (a == 1)
    {
        return false;
    }

    for (int i = 2 ; i<= sqrt(a) ; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;
}

/*
Prime function :- Naive Method
Time complexity :- O(n)
*/

bool isPrime_NaiveMethod(int a)
{
    if (a == 1)
    {
        return true;
    }
    
    for (int i = 2 ; i<a ;i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;
}

/*
Main Function
*/

/*
int main()
{
    int a;
    cout<<"Enter a Number : ";
    cin>>a;
    
    //Naive code function

    if (isPrime_NaiveMethod(a))
    {
        cout<<a<<" is prime\n";
    }

    else
    {
        cout<<a<<" is not prime\n";

    }

    //Efficient Code function
    
    if (isPrime_EfficientMethod(a))
    {
        cout<<a<<" is prime\n";
    }

    else
    {
        cout<<a<<" is not prime\n";

    }

    //further optimization for efficient code function

    if (isPrime_MostEfficientMethod(a))
    {
        cout<<a<<" is prime\n";
    }

    else
    {
        cout<<a<<" is not prime\n";

    }
}*/