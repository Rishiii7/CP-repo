#include <iostream>
#include <vector>
using namespace std;
/*
Problem :
Find element in an array using Binray Search algorithm

Solution:
1. calculate mid index of array
2. if ele at mid then return mid 
3. if ele > mid then change low to mid+1, this cuts the array to arr[mid+1,high]
4. else change high to mid-1, this cuts the array to arr[low:mid-1]

Iterative & Recursive Sultion ==>
Time Complexity :- O(logn)
Aux Space Complexity :- O(n)
Aux Space Complexity :- O(logn) -- Recursive

*/

int BinarySearch_Iterative(vector <int> arr, int ele)
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
    int n = arr.size();
    int low = 0, high = n-1;

    int mid;

    while( low <= high)
    {
        mid = (low+high)/2;
        if(arr[mid] == ele)
        {
            return mid;
        }
        else if( ele < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}


int BinarySearch_Recursive(vector<int> arr, int ele, int low , int high)
{
    /*
    Params :
    arr : Integer Vector
    ele : Integer -- element to be searched in array
    low, high : Integer -- range of indexes
    

    Returns : Integer -- Index
    
    Variables :
    mid : Integer -- index of middle element in certain range
    */
    if(low > high)
    {
        return -1;
    }

    int mid = ( low + high ) / 2;
    if(arr[mid] == ele)
    {
        return mid;
    }
    else if (ele < arr[mid])
    {
        return BinarySearch_Recursive(arr,ele,low,mid-1);
    }
    else
    {
        return BinarySearch_Recursive(arr,ele,mid+1,high);
    }

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

    //using Iterative algorithm
    cout<<"Element is present at : "<<BinarySearch_Iterative(arr,x)<<endl;

    //using Recursive algorithm
    cout<<"Element is present at (using recursive) : "<<BinarySearch_Recursive(arr,x,0,n-1);
}