#include <iostream>
#include <vector>
using namespace std;
/*
Probelm :
sort array using merge sort

Time Complexity :- O(nlogn)
Aux Space complexity :- O(1)
*/

void MergeTwoArray(vector <int> &arr, int low, int mid,int high)
{
    /*
    Args : 
    arr : Integer array -- refrenced array
    low,mid,high : Integer -- indices of array
    
    Variables :
    n1,n2 : Integer -- sizes of two array
    l_arr,r_arr : Integer -- newly created array
    i,j,k : Integer -- indecies of array used while merging

    Returns : None (arr is refrenced)
    */
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector <int> l_arr;
    vector <int> r_arr;

    //cpoying into left array
    for (int i = 0; i < n1; i++)
    {
        l_arr.push_back(arr[low+i]);
    }

    //cpoying into right array
    for (int i = 0; i <n2; i++)
    {
        r_arr.push_back(arr[mid+i+1]);
    }

    // merging two arrays
    int i = 0 , j = 0 , k = low;
    while (i < n1 &&  j < n2)
    {
        if (l_arr[i] < r_arr[j])
        {
            arr[k] = l_arr[i];
            i++;
        }
        else
        {
            arr[k] = r_arr[j];
            j++;
        }

        k++;
    }
    
    // copying left array
    while (i < n1)
    {
        arr[k] = l_arr[i];
        i++;
        k++;
    }

    // copying right array
    while (j < n2)
    {
        arr[k] = r_arr[j];
        j++;
        k++;
    }

}


void mergeSort(vector<int> &arr, int low, int high)
{
    /*
    Args : 
    arr : Integer Array -- refrenced
    low, high : Integer -- indices of arr array
    
    Variables :
    mid : Integer -- middle index ofarray
    
    Returns : None
    */
    int mid;

    if(low < high)
    {
        mid = low + (high - low) / 2 ;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        MergeTwoArray(arr, low, mid, high);
    }
}

int main()
{
    int n,ele;
    vector <int> arr;

    //size of array
    cout<<"Enter size fof array : ";
    cin>>n;

    cout<<"Enter elements : ";
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }

    mergeSort(arr, 0, n-1);
    cout<<"Merged array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
}