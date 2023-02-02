#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> InsertionSort(vector<int> arr)
{
    int n = arr.size();
    int key;
    int j;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
    
    return arr;
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

    //Insertion sort
    arr = InsertionSort(arr);
    cout<<"Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}