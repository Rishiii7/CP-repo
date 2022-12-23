#include <iostream>
#include <vector>
#include <utility>
using namespace std;


void MoveZeroToEnd(vector <int> &arr)
{
    int count = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        /*
        alternate best method
        if(arr[i] != 0)
        {
            swap(arr[i], arr[count])
            count ++;
        }
        */
       if (arr[i] == 0)
       {
        count ++ ;
       }
       else
       {
        swap(arr[i], arr[i-count]);
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

    //calling move function
    MoveZeroToEnd(arr);
    //orint the output
    cout<<"Array after : ";
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i] << " ";
    }
}