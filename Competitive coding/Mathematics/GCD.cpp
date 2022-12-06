#include <iostream>
#include <limits.h>


using namespace std;

/*
Naive method 
Time complexity :-  O(min(a,b)) 
*/

int Naive_GCD(int a, int b)
{
    int res = min(a,b);

    while (res > 0)
    {
        if ( (a % res == 0) && (b%res == 0) ) 
        {
            return res;
        }

        else 
        {
            res -- ;
        }
    }
}

/*
Efficient method :- Eculid's method
Time Complexity :- O(log(min(a,b)))
*/

int efficient_GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return efficient_GCD(b , a%b);
    }
}

/*
Main Function
*/
/*int main()
{
    int a, b;
    cout<<"Enter Two Numbers : ";
    cin>>a>>b;

    cout<<"Inefficient Method : "<< Naive_GCD(a,b);

    cout<<"\nEculid's method : "<< efficient_GCD(a,b);

    return 0;
}*/