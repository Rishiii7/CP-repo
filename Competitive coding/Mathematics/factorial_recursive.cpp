#include <iostream>
#include <limits.h>

/*Factorial function*/
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * factorial(n-1);
}


using namespace std;
int main()
{
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    if (n == 0)
    {
        cout<<1;
    }
    else
    {
        cout<<factorial(n);
    }
} // namespace std;
