#include <iostream>
using namespace std;

/*Factorial function*/
int factorial(int n)
{
    int fact = 1;
    for(int i = 1; i <= n;i++)
    {
        fact  = fact * i;
    }

    return fact;
}

int main()
{
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    if (n == 0)
    {
        cout<<"Factorial of "<<n<<" is : "<<1;
    }
    else
    {
    cout<<"Factorial of "<<n<<" is : "<<factorial(n);
    }
}