#include <iostream>
using namespace std;

/*
Power of two :-
*/
bool isPowerOfTwo(int n)
{
    if (n == 0)
    {
        return false;
    }
    else
    {
        if ( (n & (n-1) ) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}


int main()
{
    int n;
    cout<<"\n Enter a Number : ";
    cin>>n;

    cout<<endl<<isPowerOfTwo(n);
}