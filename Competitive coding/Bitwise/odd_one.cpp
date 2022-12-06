#include <iostream>
#include <vector>
using namespace std;
/*
Odd one out :- prperty of XOR

x^0 = x
x^y = y^x
x^(y^z) = (x^y)^z
x^x = 0
x^x^x^x^x^...even times = 0
x^x^x^x^x^...odd times = x

Time Complexity :- Theta(n)
Aux Space Complexity :- O(1)*/
int OddOneOut(vector <int> arr)
{
    int res = 0 ;
    for (int i = 0; i < arr.size();i++)
    {
        res = res ^ arr[i];
    }

    return res;
}


int main()
{
    int n;
    cout<<"\n Enter a number : ";
    cin>>n;

    vector <int> arr(n);
    cout<<"\n Enter array elements : ";
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"\n Odd one in the array is : "<<OddOneOut(arr);
}