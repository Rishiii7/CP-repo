#include <iostream>
#include <vector>
using namespace std;

/*
Problem :
Given an infinite sized array, we need to write an efficient solution to search an element.

Time Complexity :- O(log pos)
Aux Space Complexity :- O(1)
*/

int BinarySearch(vector <int> arr, int ele, int low, int high)
{
    /*
    Params :
    arr : Integer array
    ele : Integer -- to be searched
    low, high : Integer -- range of indexes
    
    Return : Integer
    
    Variable : 
    mid : Integer -- middle index of a certain range
    */
    int mid ;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == ele)
        {
            return mid;
        }
        else if ( arr[mid] > ele)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1 ;
        }
    }
    return -1;
}

int InfinteSizedArray(vector <int> arr, int ele)
{
    /*
    Params :
    arr : Integer array
    ele : Integer -- to be searched
    
    Return : Integer
    
    Variable :
    i : Integer -- index of array
    */
    if(arr[0] == ele)
    {
        return 0;
    }

    int i = 1;
    while(arr[i] < ele)
    {
        i = i * 2;
    }

    if(arr[i] == ele)
    {
        return i;
    }

    return BinarySearch(arr, ele, i/2 + 1, i);
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

    cout<<"Enter the element to be searched : ";
    cin>>ele;

    cout<<"Element present at : "<<InfinteSizedArray(arr,ele);
}