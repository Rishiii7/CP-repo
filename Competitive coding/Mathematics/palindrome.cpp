#include <iostream>
using namespace std;

bool isPalindromeNumber(int num)
{
    int res = 0;
    int temp = num;
    while(temp > 0)
    {
        res = res * 10 + temp%10 ;
        temp = temp / 10 ;
    }

    return (res==num);
}


/*Main Function*/
int main()
{
    int number;
    cout<<"Enter a Number : ";
    cin>>number;
    cout<<isPalindromeNumber(number); /*Calling palindrome function*/

}