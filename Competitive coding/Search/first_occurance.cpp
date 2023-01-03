#include <iostream>
#include <vector>
using namespace std;

/*
Problem :
Find first occurance element in an array using Binray Search algorithm

Solution:
1. calculate mid index of array
2. if ele > mid then change low to mid+1, this cuts the array to arr[mid+1,high]
3. if ele < mid change high to mid-1, this cuts the array to arr[low:mid-1]
4. if found decrement the high

Iterative & Recursive Sultion ==>
Time Complexity :- O(logn)
Aux Space Complexity :- O(1)
Aux Space Complexity :- O(logn) -- Recursive

For last Ocurrance 

1. Iterative ==>
if(mid == n-1 || arr[mid] != arr[mid +1])
{
    return mid;
}
else
{
    low = mid + 1;
}

2. Recursive ==>

if(mid == n-1 || arr[mid+1] != arr[mid])
{
    return mid;
}

else
{
    return FirstOccurance_Recursive(arr,ele,mid+1 ,high);
}
*/


int FirstOccurance_Iterative(vector <int> arr, int ele)
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
        if( ele < arr[mid])
        {
            high = mid - 1;
        }
        else if(ele > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            if(mid == 0 || arr[mid] != arr[mid -1])
            {
                return mid;
            }
            else
            {
                high = mid -1;
            }
        }
    }

    return -1;
}

int FirstOccurance_Recursive(vector <int> arr, int ele , int low , int high)
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

    int mid = (low + high) / 2;
    if(ele < arr[mid])
    {
        return FirstOccurance_Recursive(arr,ele,low,mid-1);
    }
    else if (ele > arr[mid])
    {
        return FirstOccurance_Recursive(arr,ele,mid+1,high);
    }
    else
    {
        if(mid == 0 || arr[mid-1] != arr[mid])
        {
            return mid;
        }

        else
        {
            return FirstOccurance_Recursive(arr,ele,low ,mid-1);
        }
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

    //Recursive algorith
    cout<<"Element present at : "<<FirstOccurance_Recursive(arr,x,0,n-1)<<endl;
    //Iterative algorithm
    cout<<"Element present at : "<<FirstOccurance_Iterative(arr,x);
}