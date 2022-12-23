#include <iostream>
#include <vector>
using namespace std;

/*
Problem : Find position of largest element

Time complexity : O(n)
*/

int PositionOfLargest(vector <int> arr)
{
    /*
    Params :
    arr : vector of size n
    
    Returns : integer
    pos : position of largest element
    */
    int pos = 0;
    for(int i = 1 ; i < arr.size(); i++)
    {
        if (arr[i] > arr[pos])
        {
            pos = i;
        }
    }
    return pos;
}

int main()
{
    vector <int> arr;
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int ele;
    cout<<"Enter the elements : ";
    for (int i = 0 ;i <n ;i ++)
    {
        cin>>ele;
        arr.push_back(ele);
    }

    cout<<"Position of largest element : "<<PositionOfLargest(arr);
}