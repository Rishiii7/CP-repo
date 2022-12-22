#include <iostream>
using namespace std;

int sum_of_n(int n)
{
    if ( n == 1 )
    {
        return 1;
    }

    return n + sum_of_n(n-1);
}

int main()
{
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    cout<<"Sum of n natural number is : "<<sum_of_n(n);
}