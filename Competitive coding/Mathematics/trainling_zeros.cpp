#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

/*Trailing zeros function*/
int trailing_zeros(int n)
{
    int sum = 0;
    for (int i = 5 ; i <= n ; i = i*5)
    {
        sum = sum + n/i;
    }

    return sum;
}

int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout<<"Number of zeros in factorila is : "<<trailing_zeros(n);
}