#include <iostream>
#include <vector>
using namespace std;

/*
problem :
search an element in a sorted and rotated array.

Solution :-
check which half is sorted

Time Complexity :- O(logn)
Aux Space Complexity :- O(1)
*/

int BinraySearchRotatedArray(vector <int> arr, int ele)
{
    /*
    Params :
    arr : Integer Vector
    ele : Integer -- element to be searched in array
    
    Returns : Integer -- Index
    
    Variables :
    n : Integer -- size of array
    low, high : Integer -- range of indexes
    mid : Integer -- index of middle element in certain range
    */
    int n  = arr.size();
    int low = 0;
    int high = n -1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == ele)
        {
            return mid;
        }

        else if ( arr[mid] > arr[low])
        {
            if( ele >= arr[low] && ele < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if( ele <= arr[high] && ele > arr[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    //initialize
    vector <int> arr;
    int n,ele;
    int x;
    //size of array;
    cout<<"Enter size of array : ";
    cin>>n;

    //elements of array
    cout<<"Enter elements if aray : ";
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }
    
    //elememt to be searched
    cout<<"Enter elememt to be searched : ";
    cin>>x;

    cout<<"Element is present in : "<<BinraySearchRotatedArray(arr,x);


}