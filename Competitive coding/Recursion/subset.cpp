#include <iostream>
#include <string.h>
using namespace std;

/*
Problem :
Generate the subset or subsequence of the given string

Solution :
We are using 2 recursive call, 
1st is keeping string as it is,
while 2nd one is adding element to the given string
*/

void Subset(string curr, string s, int index)
{
    /* 
    Params :
    curr : Initally an empty String.
    s : User given string.
    index : iterating over each element in the string.

    Returns :
    Nothing
    */
    if (index == s.length()) 
    {
        //Printing the 
        cout<<curr<<endl;
        return;
    }

    Subset(curr, s, index + 1);
    Subset(curr + s[index] , s, index + 1 );
}

int main()
{
    string s;
    cout<<"Enter string : ";
    cin>>s;
    cout<<"Subset of string are : \n ";
    Subset(" ", s, 0);
}