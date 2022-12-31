#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
/*
Problem :
An euilibrium point is where the left sum is euqal to right sum
at that index

Time Complexity :- O(n)
Aux Space Complexity :- O(1)
*/

bool EquilibriumPoint(vector <int> arr)
{
    /*
    Params:
    arr : Integer Vector

    Returns:
    Boolen value

    Variable :
    n : Integer -- size of array
    l_sum, r_sum : Integer -- storing sum of left array and right array
                              excluding the index
    */
    int n = arr.size();
    int l_sum = 0;

    //sum of an array
    int r_sum = accumulate(arr.begin() , arr.end(), 0);

    for(int i = 0 ; i < n ; i++)
    {
        r_sum = r_sum - arr[i];

        if (l_sum == r_sum )
        {
            return true;
        }

        l_sum += arr[i];
    }

    return false;
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
    if( EquilibriumPoint(arr))
    {
        cout<<"There is an euilibrium point";
    }
    else
    {
        cout<<"There is no euilibrium point";
    }
}