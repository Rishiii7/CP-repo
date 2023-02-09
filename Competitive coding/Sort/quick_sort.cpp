#include <iostream>
#include <vector>
using namespace std;


void NaivePartition(vector <int> &arr, int l , int r , int pivot)
{
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

    NaivePartition(arr , 0 , n-1 , 3);
    cout<<"Sorted array : ";
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}