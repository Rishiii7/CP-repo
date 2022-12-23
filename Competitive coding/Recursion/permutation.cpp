#include <iostream>
#include <string.h>
#include <utility>
using namespace std;

/*
Problem :
Print all the permuation of given string


*/

void Permutation(string s , int i = 0)
{
    /*
    Params :
    s : String
    i : index 
    
    Returns :
    None
    */
    if (i == s.length() -1)
    {
        cout<<s<<" ";
    }

    for(int j = i ; j < s.length() ; j ++ )
    {
        swap(s[i] , s[j]);
        Permutation(s, i + 1);
        swap(s[i] , s[j]);
    }

}

int main()
{
    string s;
    cout<<"Enter String : ";
    cin>>s;
    cout<<"Permutation of the given string is : ";
    Permutation(s);
}