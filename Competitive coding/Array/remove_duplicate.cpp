#include <iostream>
#include <vector>
using namespace  std;

int RemoveDuplicateElements(vector <int>& arr)
{
    int index = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != arr[i+1])
        {
            index ++;
            arr[index] = arr[i+1];
        }
    }

    return index;
}


int main()
{
    // initialization
    vector <int> arr;
    int n;
    int ele;

    //size of array
    cout<<"enter sixe of array : ";
    cin>>n;

    //elements of array
    cout<<"Enter elements in array : ";
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }

    //function calling
    int size = RemoveDuplicateElements(arr);
    cout<<"Size of new array is : "<<size<<endl;
    //print output
    cout<<"New array is : ";
    for(int i = 0 ; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
} // namespace  std;

