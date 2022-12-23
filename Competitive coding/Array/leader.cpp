#include <iostream>
#include <vector>
using namespace std;
/*
Problem :
find leaders in array, An element is called the leader of an array
if there is no element greater than it on the right side.;
*/

void Leaders(vector<int> arr)
{
    int len = arr.size();
    int val = arr[len-1];
    cout<<val<<" ";
    for(int i = len - 2 ; i >= 0; i--)
    {
        if(arr[i] > val)
        {
            cout<<arr[i]<<" ";
            val = arr[i];
        }
    }
}
int main()
{
    //initialize
    vector <int> arr;
    int n,ele;

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

    cout<<"Leaders in array are : ";
    Leaders(arr);
}