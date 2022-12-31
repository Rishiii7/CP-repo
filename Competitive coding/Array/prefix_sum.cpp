#include <iostream>
#include <vector>
using namespace std;

/*
Problem :
Given a fixed array and multiple range sum, how to answer the queries efficiently

NOTE :- our aim is to reduce the time comp (TC) of PrefixSum() function
so we need to do pre-processing in our main function to reduce TC.
In many problem (competitve problem )it is better to pre-process the array first and then run 
any query rather than running the pre-process of whole code query by query

Time Complexity :- O(1)
Aux Space Complexity :- O(1) -- of PrefixSum() function
*/


int PrefixSum(vector <int> arr, int s, int e)
{
    /*
    Params:
    arr : Integer Vector
    s, e : Integer -- indexed of array

    Returns:
    Integer
    */
    if (s == 0)
    {
        return arr[e];
    }
    
    return arr[e] - arr[s-1];

}


int main()
{
    //initialize
    vector <int> arr;
    vector <int> sum_arr;
    int n, ele, t;
    int sum = 0;

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

    // pre-processing the sum of the given array
    for(int i = 0; i < n ; i++)
    {
        sum += arr[i];
        sum_arr.push_back(sum);
    }
    

   /*   if you want weighted sum uncomment this line

   //preprocessing weighted sum of given array
   for(int i = 0; i < n ; i++)
   {
        sum += ( (i+1) * arr[i] );
        sum_arr.push_back(sum);
   }
   */


    
    cout<<"Enter test case : ";
    cin>>t;
    //calling function
    while (t -- )
    {
        //queries
        int s,e;
        cout<<"Enter starting and ending index : ";
        cin>>s>>e;
        cout<<"Sum of the given indexed array is : "<<PrefixSum(sum_arr,s,e)<<endl;
    }
    
}