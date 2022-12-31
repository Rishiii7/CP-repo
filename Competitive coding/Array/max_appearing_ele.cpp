#include <iostream>
#include <vector>
#define MAX 100
using namespace std;
/*
Problem :
Given 2 array left and right where,
0 <= left[i] <= right[i] < 100
find the element that appears maximum

Case :-
left = [1,2]
right = [5, 4]

there will be two array :- 
[1,2,3,4,5] and [2,3,4] -- same as -- [left[0] to right[0]] and 
                                      [left[1] to right[1]]
i.e left array act as a staring element and right array 
act as a ending element

2,3,4 are maximum appearing element
Hence, 2 is output, since 2 is appearing first

Time Complexity :- O(n + MAX)
Aux Space Complexity :- O(MAX)
*/

int MaximumAppearingElement(vector <int> l , vector <int> r)
{
    /*
    Params:
    left, right : Integer Vector

    Returns:
    Integer

    Variable :
    freq: Integer  Vector -- Initialized by zero
    n : Integer -- size of array
    res : Integer -- element that appears most
    */

    vector <int> freq (MAX , 0);
    int n = l.size(); // same as r.size()
    int res = 0;

    //assigning start as 1 and end as -1
    for(int i = 0 ; i < n ; i++)
    {
        freq[ l[i] ] = 1;
        freq[ r[i] + 1 ] = -1;
    }

    // main logic
    for(int i = 0 ; i < MAX ; i++)
    {
        freq[i] = freq[i-1] + freq[i];
        if(freq[i] > freq[res])
        {
            res = i;
        }
    }

    return res;
}


int main()
{
    //initialize
    vector <int> left;
    vector <int> right;
    int n,ele;

    //size of array;
    cout<<"Enter size of array : ";
    cin>>n;

    //elements of left array
    cout<<"Enter elements if left array : ";
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        left.push_back(ele);
    }

    //elements of right array
    cout<<"Enter elements if left array : ";
    for(int i = 0; i < n; i++)
    {
        cin>>ele;
        right.push_back(ele);
    }

    //calling function
    cout<<"Maximum element is : "<<MaximumAppearingElement(left, right);
}