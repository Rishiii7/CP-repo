#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector <int> arr)
{
    /*
    Params :
    arr : Integer vector of size n
    
    Return : Boolean 
    */
    for(int i = 0; i < arr.size() - 1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // initializing variables
    vector <int> arr;
    int n;
    int ele;

    // taking size of vector ffrom user
    cout<<"Enter the size of array : ";
    cin>>n;

    //Taking elements of array
    cout<<"Enter the elements of array : ";
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }

    //function for checking whether array is sorted or not
    if(isSorted(arr))
    {
        cout<<"Array is sorted";
    }
    else
    {
        cout<<"Array is not sorted";
    }

}