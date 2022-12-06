#include <iostream>
#include <limits.h>

using namespace std;

/*
compute x^n : Efficient Solution
Time Complexity :- O(logn)
Aux Spcae :- O(1)
*/

int iterative_power(int x, int n)
{
    int res = 1;

    while(n > 0)
    {
        if (n & 1)
        {
            res = res * x;
        }

        n = n >> 1;
        x = x * x;
    }

    return res;
}

/*
Computing power :- Naive Solution
Time Complexity :- O(n)
*/

int ComputingPower_NaiveMethod(int x ,int n)
{
    int res = 1;
    for (int i = 0;i<n;i++)
    {
        res = res * x;
    }

    return res;
}


int main()
{
    int x,n;
    cout<<"\n Enter two numbers : ";
    cin>>x>>n;

    cout<<"\npower is : "<<iterative_power(x,n);
    cout<<"\npower is : "<<ComputingPower_NaiveMethod(x,n);
}