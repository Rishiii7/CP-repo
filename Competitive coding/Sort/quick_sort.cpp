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

3. Hoare Partition ==>
    Time commplexity :- O(n)
    Aux Space complexity :- O(1)
    Require 1 O(n) traversal and less comparison than Lomuto.
*/

int HoarePartition(vector <int> &arr, int l, int h)
{
    /*
    Args ::
    arr : Integer Vector
    l ,h : Integer -- indices of array where sorting is performed
    pivot : Integer -- index element which get sorted

    Parameters ::
    pivot_ele : Integer -- element of pivot index
    i, j : Integer -- indices of array 

    Return ::
    j : Integer -- arr[l:j+1] < arr[j+1:h] in short left and rigt array are sorted
    */
    int pivot = l;
    //swap(arr[l], arr[pivot]);
    int pivot_ele = arr[l];

    int i = l-1, j = h+1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot_ele);

        do
        {
            j--;
        } while (arr[j] > pivot_ele);

        if (i >= j)
        {
            return j;
        }

        swap(arr[i], arr[j]);   
    }
    return j;
    
}

void QuickSortHoarePartition(vector <int> &arr, int l , int h)
{
    /*
    Args ::
    arr : Integer vector
    l,h : Integer -- index range of array
    
    Parameters ::
    pivot : Integer -- index at which left and right array is sorted

    Returns ::
    None -- but array is sorted.
    */
    if (l < h)
    {
        int pivot = HoarePartition(arr, l , h);
        QuickSortHoarePartition(arr, l , pivot);
        QuickSortHoarePartition(arr, pivot+1, h);
    }
    
}


int LomutoPartition(vector <int> &arr, int l, int h)
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
    int pivot = h;
    //swap(arr[h], arr[pivot]);
    int pivot_ele = arr[pivot];
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

void QuickSortLomutoPartition(vector <int> &arr, int l, int h)
{
    /*
    Args ::
    arr : Integer vector
    l,h : Integer -- index range of array
    
    Parameters ::
    pivot : Integer -- index at which element is sorted

    Returns ::
    None -- but array is sorted.
    */
    if (l<h)
    {
        int pivot = LomutoPartition(arr, l ,h);
        QuickSortLomutoPartition(arr, l, pivot - 1);
        QuickSortLomutoPartition(arr, pivot+1, h);
    }
    
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
    //NaivePartition(arr , 0 , n-1 , 3);

    //Lamouto partition function
    //cout<<"Index at pivot : "<<LomutoPartition(arr, 0, n-1, n-1);
    

    // Hoare partition function
    //cout<<"Index at which array is sorted : "<<HoarePartition(arr, 0, n-1, 0    )<<endl;

    // quick using lomuto partition
    //QuickSortLomutoPartition(arr, 0 , n-1);

    //quick using hoare partition
    QuickSortHoarePartition(arr, 0 , n-1);
    cout<<"Soted array : ";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}