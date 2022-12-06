#include <iostream>
#include <stdlib.h>
#include "GCD.cpp"

using namespace std;

int main()
{
    int a, b ;
    cout<<"Enter Two Numbers: ";
    cin>>a>>b;
    cout<<"LCM of two numbers is : "<< (a * b ) / efficient_GCD(a,b);
}