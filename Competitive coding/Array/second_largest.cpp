#include <iostream>
#include <vector>
using namespace std;

int PositionOfSeondLargest(vector <int> arr)
{
    /*
    Params : 
    arr : integer vector of dynamic size

    Variable :
    lpos : position of largest element
    slpos : position of second largest element
    
    Return : Integer
    slpos : position of second largest element
    */
    int lpos = 0;
    int slpos = -1;
    
    for(int i = 0; i<arr.size(); i++)
    {
        if(arr[i] > arr[lpos])
        {
            slpos = lpos;
            lpos = i;
        }
        else
        {
            if(slpos == -1)
            {
                if(arr[i] != arr[lpos])
                {
                    slpos = i;
                } 
            }
            else if (arr[i] > arr[slpos] && arr[i] != arr[lpos])
            {
                slpos = i;
            }
        }
    }

    return slpos;

}

int main()
{
    vector <int> arr;
    int n;
    int ele;

    // size of vector
    cout<<"Enter the size of array : ";
    cin>>n;

    // element insertion in vector
    cout<<"Enter elements of array : ";
    for(int i = 0; i < n ; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }

    // finding the positiom of second largest element
    cout<<"Position of second largest element is : "<<PositionOfSeondLargest(arr);

}