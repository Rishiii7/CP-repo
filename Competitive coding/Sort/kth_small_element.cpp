#include <iostream>
#include <vector>
using namespace std;


int LPartition(vector <int> &arr, int l ,int r)
{
    int pivot = l;
    int pivot_ele = arr[pivot];
    int i = l-1;

    for (int j = l; j < r ; j++)
    {
        if (arr[j] < pivot_ele)
        {
            i++ ;
            swap(arr[i] , arr[j]);
        }
    }
    
    swap(arr[i+1], arr[pivot]);
    return i+1;
    
    
}

int KthSmallestElement(vector <int> arr,  int l , int r)
{
    if (l < r)
    {
        int pivot = LPartition(arr , l , r);

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
}