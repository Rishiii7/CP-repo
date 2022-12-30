#include <iostream>
#include <vector>
using namespace std;
/*
Problem :
Given a binary array, we need to find the minimum of number
of group flips to make all array elements same

Time Complexity :- O(n)
Aux Space Complexity :- O(1)
*/
void MinimumConsecutiveFlips(vector <int> arr)
{
    /*
    Params:
    arr : Integer Vector

    Returns:
    None

    Variable :
    flip_one, flip_zero : Integer -- No of flips required
    n : Integer -- size of array
    ele : Integer -- Which bit is to be flipped
    */
    int n = arr.size();
    int flip_zero = 0;
    int flip_one = 0;
    int ele = 0;

    //Counting flip for each bits
    for(int i = 1 ; i < n ; i++)
    {
        if (arr[i] != arr[i-1])
        {
            if(arr[i-1] == 1)
            {
                flip_one ++;
            }
            else
            {
                flip_zero ++;
            }
        }
    }

    if(arr[n-1] == 1)
    {
        flip_one ++;
    }
    else
    {
        flip_zero ++ ;
    }
    
    // if either of flips are zero than no need to change, 
    //it is already equal
    if (flip_one == 0 || flip_zero == 0)
    {
        cout<<"No need of flipping";
    }

    //if flips are grater than zero and equal then you can change
    //either of its bits to make array same
    else if (flip_one == flip_zero)
    {
        cout<<"Can flip either of bits -- No of flips required : "<<flip_one;
    }

    //minimum of the flip is needed to make the array same
    else
    {
        if (flip_one < flip_zero)
        {
            ele = 1;
            cout<<"Flip all ones -- No of flips  required: "<<flip_one;
        }
        else
        {
            cout<<"Flip all zeros -- No of flips required : "<<flip_zero;
        }

        // printing indexes to be flipped
        cout<<"\n Index to be flipped : ";
        for(int i = 0 ;i < n ;i++)
        {
            if(ele == arr[i])
            {
                cout<< i << " ";
            }
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

    //calling function
    MinimumConsecutiveFlips(arr);
}