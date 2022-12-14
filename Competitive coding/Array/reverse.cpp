#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
Problem : 
Reverse the array

Note :
swap function is called from utility header file
alternative method can be =>
temp = b
b = a
a = temp
*/

vector<int> ReverseArrayAlt(vector <int> arr)
{
    /*
    Params :
    arr : Integer Vector
    
    Returns :
    Interger Vector

    Variables :
    start : Integer index of array
    end : Integer index of array
    */
    int start  = 0;
    int end = arr.size() - 1;

    while(start < end)
    {
        swap(arr[start] , arr[end]);
        start ++;
        end --;
    }

    return arr;
}

vector <int> ReverseArray(vector <int> arr)
{
    /*
    Params :
    arr : Integer Vector
    
    Returns :
    Interger Vector
    */

    for(int i = 0 ; i < (arr.size() / 2 ); i++)
    {
        swap(arr[i] , arr[arr.size() - i - 1]);
    }

    return arr;
}

int main()
{
    // Initialization of variables
    vector <int> arr;
    int n;
    int ele;

    // Size of array
    cout<<"Enter size of Array : ";
    cin>>n;

    //Elements of array
    cout<<"Enter elemnts of array : ";
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }

    //reversing the array
    arr = ReverseArray(arr);

    //Printing the output
    cout<<"Array after reversing : ";
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }

    //reversing the array using alternate method
    arr = ReverseArrayAlt(arr);

    //Printing the output
    cout<<"\nArray after reversing using alternate method : ";
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
}