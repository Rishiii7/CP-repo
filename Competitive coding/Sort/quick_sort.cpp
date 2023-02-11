#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Problem : 
Sort  array using Quick Sort

Different Types of Partition method :
1. Naive Partition ==>
    Time complexity :- O(n)
    Aux Space complrxity :- O(n)
    Require 3 O(n) traversal

2. Lomuto Partition ==>
    Time commplexity :- O(n)
    Aux Space complexity :- O(1)
    Require 1 O(n) traversal
 
*/

int LomutoPartition(vector <int> &arr, int l, int h, int pivot)
{
    /*
    Args ::
    arr : Integer Vector
    l ,h : Integer -- indices of array where sorting is performed
    pivot : Integer -- index element which get sorted
    
    Parameters ::
    pivot_ele : Integer -- element of pivot index
    i : Integer -- indicate the size of element smaller than pivot
    
    Returns ::
    Integer -- index of pivot after sorting
    */
    int pivot_ele = arr[pivot];
    swap(arr[h], pivot_ele);
    int i = l-1;
    for (int j = l; j < h; j++)
    {
        if (arr[j] < pivot_ele)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i+1], arr[pivot]);
    return i+1;
}


void NaivePartition(vector <int> &arr, int l , int r , int pivot)
{
    /*
    Args :: 
    arr : Integer vector
    l,r,pivot : Integer -- Indices of array

    Parameters ::
    temp : Intger vector -- created temporary array

    Return :: None (changes are made into original array)
    */
    vector <int> temp ;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] <= arr[pivot] && i != pivot)
        {
            temp.push_back(arr[i]);
        }
    }
    temp.push_back(arr[pivot]);

    for (int i = l; i <= r; i++)
    {
        if (arr[i] > arr[pivot])
        {
            temp.push_back(arr[i]);
        }
        
    }

    for (int i = l; i <=r ; i++)
    {
        arr[i] = temp[i-l];
    }
  
}

int main()
{
    // Initialization
    int n, ele;
    vector <int> arr;

    // Siz e of vector
    cout<<"Enter size of array : ";
    cin>>n;

    // Array storing
    cout<<"Enter elements : ";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }

    // Only partition function
    /*NaivePartition(arr , 0 , n-1 , 3);
    cout<<"Sorted array : ";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }*/

    //Lamouto partition function
    cout<<"Index at pivot : "<<LomutoPartition(arr, 0, n-1, n-1);
    cout<<"Sorted array : ";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}