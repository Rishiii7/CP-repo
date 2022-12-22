#include <iostream>
using namespace std;

/*
Problem :
There are n people in a circular table 
every k-th person is killed find out the position of
only alive person

Solution :
Find a relation between JosephusProblem(n-1, k) and 
JosephusProblem(n, k) (i.e on line 29)

Time Complexity : O(n)
*/

int JosephusProblem(int n, int k)
{
    /*
    Params:
    n : No of Person
    k : every k-th position to be killed
    
    Returns :
    Position No. of the last remaining person to be alive*/

    if (n == 1)
    {
        return 0;
    }

    return (JosephusProblem(n-1, k) + k ) % n;
}

int main()
{
    int n,k;
    cout<<"Enter No of persons : ";
    cin>>n;
    cout<<"Enter the k-th position to be killed : ";
    cin>>k;

    cout<<"Position of a last alive person : "<<JosephusProblem(n,k);
}