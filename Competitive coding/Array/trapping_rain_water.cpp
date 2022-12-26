#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Problem :
Total amount of water can be stored in an bar of array

Solution :
calculating left and right max heigth of each point 
then taking min of two hieghts and sub from given height

Note: 
Difference is when are we going to calculating left and right max.
In Efficient Solution : we calulated everything before storing rain water code (i.e line 61)
In Naive Solution : we calculated max heights at the time of storing rain water (i.e line 103).

Efficient Solution :
Time Complexity :- thetha(n)
Aux Space Complexity :- O(n)

Naive Solution :
Time Complexity :- O(n^2)
Aux Space Complexity :- O(1)
*/

int TrappingRainWater_EfficientSolution(vector <int> arr)
{
    /*
    Params:
    arr : Integer Vector

    Returns:
    rain : Integer

    Variable :
    rain : Integer -- for string the output value
    len : Integer -- lenght of array
    lmax, rmax -- Integer Vector -- for storing left and right max height at given point
    */
    int rain = 0;
    int len = arr.size();
    vector <int> lmax(len);
    vector <int> rmax(len);

    //calculating lmax array
    lmax[0] = arr[0];
    for(int i = 0; i < len-1; i++)
    {
        lmax[i] = max(lmax[i-1], arr[i]);
    }

    //calculating rmax array
    rmax[len-1] = arr[len-1];
    for(int i = len - 2; i>=0; i--)
    {
        rmax[i] = max(arr[i], rmax[i+1]);
    }

    //calculating total rain water that can be stored
    for(int i = 1 ; i< len - 1; i++)
    {
        rain += ( min(lmax[i],rmax[i]) - arr[i] );
    }

    return rain;
}

int TrappingRainWater_NaiveSolution(vector <int> arr)
{
    /*
    Params:
    arr : Integer Vector

    Returns:
    rain : Integer

    Variable :
    rain : Integer -- for string the output value
    len : Integer -- lenght of array
    lmax, rmax : Integer -- for storing left and right max height at given point
    */
    int rain = 0;
    int lmax, rmax;
    int len = arr.size();
    for(int i = 1; i < len - 1; i++)
    {
        //calculating lmax 
        lmax = arr[i];
        for(int j = 0; j < i; j++)
        {
            lmax = max(lmax,arr[j]);
        }

        //calculating rmax 
        rmax = arr[i];
        for(int j = i + 1; j < len ; j++)
        {
            rmax = max(rmax, arr[j]);
        }

        //calculating total rain water that can be stored
        rain += ( min(rmax,lmax) - arr[i]);

    }

    return rain;
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
    //cout<<"Total rain water trapped is : "<<TrappingRainWater_NaiveSolution(arr);

    cout<<"Total rain water trapped is : "<<TrappingRainWater_EfficientSolution(arr);
}