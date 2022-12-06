#include <iostream>
#include "prime_numbers.cpp"

using namespace std;

/*
Prime factor function :- Efficient Method
Time complexity :- O(n * log(sqrt(n)))
*/

void Efficient_PrimeFactor(int n)
{
    cout<<"\nPrime factors are Efficient method : ";
    for (int i = 2 ; i * i <= n ; i++)
    {
        if (isPrime_MostEfficientMethod(i))
        {
            while (n % i == 0)
            {
                cout<<i<<" ";
                n = n / i;
            }
        }
    }

    if (n > 1)
    {
        cout<< n;
    }
}

/*
Prime factor function :- Naive Method
Time complexity :- O(n^2 * log(n))
*/

void Naive_PrimeFactor(int n)
{
    cout<<"\nPrime factors for Naive method are : ";
    for (int i = 2 ; i <= n ; i++)
    {
        if (isPrime_MostEfficientMethod(i))
        {
            int x = i;
            while (n % x == 0)
            {
                cout<<i<<" ";
                x = x * i;
            }
        }
    }
}

/*
Main function calling
*/

int main()
{
    int n;
    cout<<"Enter a  Number : ";
    cin>>n;

    // calling Naive_PrimeFactor function
    Naive_PrimeFactor(n);

    // Calling Efficient_PrimeFactor function
    Efficient_PrimeFactor(n);
}