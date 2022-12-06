#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

/*
Check if Number is prime :- Shorter implementation of efficient method
Time complexity :- O(nloglog(n))
*/

void SieveofEratosthenes_ShorterEfficientMethod(int n)
{
    vector <bool> is_prime (n+1, true);

    for (int i = 2 ; i <= n ; i++)
    {
        if (is_prime[i])
        {
            cout<<i<<" ";

            for(int j = i * i ; j<= n; j = j + i)
            {
                is_prime[j] = false;
            }
        }
    }
}

bool isPrime(int n)
{
    if(n == 1)
    {
        return false;
    }

    else if (n == 2 || n == 3)
    {
        /* code */
        return true;
    }

    else if (n%2 == 0 || n%3 == 0)
    {
        /* code */
        return false;
    }
    
    else
    {
        for(int i = 5 ; i * i <= n ;i = i+6)
        {
            if( n%i == 0 || n%(i+2) == 0)
            {
                return false;
            }
        }

        return true;
    }
}

/*
Sieve of Eratosthenes :- Efficient method
Time complexity :- O(n * sqrt(n))
*/

void SieveofEratosthenes_EfficientMethod(int n)
{
    vector <bool> is_prime(n+1, true);
    for (int i = 2 ; i * i <= n ; i++)
    {
        if (is_prime[i])
        {
            for (int j = 2 * i ; j <= n ; j = j + i)
            {
                is_prime[j] = false;
            }
        }
    }

    for(int i = 2 ; i <= n ; i ++)
    {
        if (is_prime[i])
        {
            cout<<i<<" ";
        }
    }

}


/*
Sieve of Eratosthenes :- Naive method
Time complexity :- O(n * sqrt(n))
*/

void SieveofEratosthenes_NaiveMethod(int n)
{
    for (int i = 2; i< n ;i++)
    {
        if(isPrime(i))
        {
            cout<<i<<" ";
        }
    }
}

//
int main()
{
    int n;
    cout<<"\n Enter a number : ";
    cin>>n;

    /* //
    cout<<"\n Prime Numbers using Naive method are : ";
    SieveofEratosthenes_NaiveMethod(n);
    
    //
    cout<<"\n Prime Numbers using Efficient method are : ";
    SieveofEratosthenes_EfficientMethod(n);
    */
   
    //shorter implementation of seive of Eratosthenes
    cout<<"\n Prime Numbers using shorter implementation of Efficient method are : ";
    SieveofEratosthenes_ShorterEfficientMethod(n);

}