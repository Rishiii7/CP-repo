#include<iostream>
#include <vector>
using namespace std;

/*
two numbers occuring odd times
*/

void TwoOddOcurring(vector <int> arr)
{
    int res = arr[0];
    for (int i = 1 ; i< arr.size() ; i++)
    {
        res = res ^ arr[i];
    }

    int k = res & (~ (res - 1));
    int res1 = 0;
    int res2 = 0;
    for (int i = 0 ; i <arr.size() ; i++)
    {
        if ( (k & arr[i]) != 0 )
        {
            res1 = res1 ^ arr[i];
        }
        else
        {
            res2 = res2 ^ arr[i];
        }
    }

    cout<<res1 <<" "<<res2;
}


int main()
{
    int n;
    cout<<"\n Enter a number : ";
    cin>>n;

    vector <int> arr(n);
    cout<<"\n Enter the elements of array : ";
    for (int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    TwoOddOcurring(arr);
}