#include <iostream>
#include <vector>
using namespace std;

/*
Problem : 
Find the count of a given element in an binary array

Solution :
calculate first occurance
calculate last ocuurance
then substract to get the count

Time complexity :- O(logn + k)  -- logn is called 2 time, so 2*logn is same as logn
Aux Space complexity :- O(logn)
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


int LastOccurance_Iterative(vector <int> arr, int ele)
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
            if(mid == n-1 || arr[mid] != arr[mid +1])
            {
                return mid;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    return -1;
}

int CountOccurance(vector <int> arr, int ele)
{
    /*
    Params :
    arr : Integer Vector
    ele : Integer -- element to be searched in array

    Returns : Integer -- Count

    Variable :
    first : Integer -- index of first occurance of element
    */
     int first = FirstOccurance_Iterative(arr,ele);
     if(first == -1)
     {
        return -1;
     }
     else
     {
        return ( LastOccurance_Iterative(arr,ele) - first + 1 );
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

    //counting element
    cout<<"No of element in array : "<<CountOccurance(arr,ele);

}