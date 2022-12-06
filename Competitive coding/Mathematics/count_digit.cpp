#include <iostream>
using namespace std;

int countDigits(int x)
{
	int res = 0;

	while(x > 0)
	{
			x = x / 10;

			res++;
	}	

	return res;
}

int main() {
    
    	int number;
		cout<<"\n Enter the Number : ";
        cin>>number;
    	
    	cout<<"No of Digits is :"<<countDigits(number);
}