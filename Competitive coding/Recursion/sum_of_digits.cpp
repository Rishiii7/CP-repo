#include <iostream>
using namespace std;

int SumOfDigits(int n)
{
    /*
    condition can also be written as :
    if (n <= 9)
    {return n}
    */
    if (n == 0)
    {
        return 0;
    }

    return n % 10 + SumOfDigits(n/10);
}

int main()
{
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    cout<<"Sum of the Digits is : "<<SumOfDigits(n);
}