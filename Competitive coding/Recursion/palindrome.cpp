#include <iostream>
#include <string.h>
using namespace std;


bool isPalindrome(string s, int start, int end)
{
    if (start >=  end)
    {
        return true;
    }

    return (s[start] == s[end]) && isPalindrome(s,start + 1, end - 1);
}


int main()
{
    string s;
    cout<<"Enter a string : ";
    cin>>s;

    if (isPalindrome(s,0,s.length()-1))
    {
        cout<<"String is Palindrome";
    }
    else
    {
        cout<<"String is not Palindrome";
    }
    
}