#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

/*
Printing Divisor of a Number : Naive Method
Time complexity :- o(n)
*/

void Divisor_NaiveMethod(int n)
{
    for (int i = 1 ; i<= n ; i ++)
    {
        if (n % i == 0)
        {
            cout<< i << " ";
        }
    }
}

/*
Printing Divisor of a Number : efficient Method
Time complexity :- o(sqrt(n))
*/

void Divisor_EfficientMethod(int n)
{
    for (int i = 1 ; i * i < n ;i++)
    {
        if(n % i == 0)
        {
            cout<<i<<" ";
        }
    }

    for (int i = sqrt(n) ; i>=1;i--)
    {
        if(n%i == 0)
        {
            cout<<n/i<<" ";
        }
    }
}


/*
Main Function
*/

int main()
{
    int a ;
    cout<<"\nEnter a Number : ";
    cin>>a;

    // Naive solution
    cout<<"\nDivisors using Naive Method are: ";
    Divisor_NaiveMethod(a);

    // Efficient solution
    cout<<"\nDivisors using Efficient Method are: ";
    Divisor_EfficientMethod(a);
}