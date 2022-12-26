#include <iostream>
#include <vector>
using namespace std;
/*
Problem :
solution to the Stock Buy and Sell Problem, so that we can have maximum profit.

Solution :
We are only intereseted in bottom price if price next day is greater than price
today we sell 

Note :- This problem is very different from leetcode's
Buy and sell stock problem : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Time Complexity :- theta(n)
Aux Space Complexity :- O(1)
*/
int BuySellStock(vector <int> arr)
{
    /*
    Params :
    arr : integer vector
    
    Returns :
    profit : Integer containing profit
    
    Variables :
    profit : Integer 
    len : Integer -- length of array
    */
    int profit = 0;
    int len = arr.size();
    for(int i = 1 ; i < len ; i ++)
    {
       if(arr[i] > arr[i-1])
       {
        profit += (arr[i] - arr[i-1]);
       }
    }
    return profit;
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
    cout<<"Porfit is : "<<BuySellStock(arr);
}