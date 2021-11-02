#include <iostream>
#include <cassert>
#include <iomanip>
#include "stackADT.cpp"
using namespace std;
 


int main()
{    
     string s;
     int b = 0;
	double input = 0;
	double output;
	bool found;
     cout << "Give me a positive integer or a positive decimal number: ";
     cin >> s;
	stackType<char> inputStack;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i]== '.')
		{
			found = true;
			break;
		} 
		b++;
		input = (10.0 * input) + (s[i] - '0'); 
	}
	if (found)
	{
		b++;
		for (int i = b; i < s.length(); i++)
		{
			if (s[i] != '.')
			{
				inputStack.push(s[i] - '0');
			}
			

		}
		// b--;
		double dec = 0;
		// int num = 0;
		// int exp = (s.length() - b) * -1;
		while (!inputStack.isEmptyStack())
		{
			// cout << exp << endl;
			// // exp++;
			// num = inputStack.top();
			
			dec = (dec + inputStack.top()) / 10.00;
			inputStack.pop();
			
			cout << dec << endl;
			// dec = (num * pow(10,exp)) + dec;
			
		}
		output = dec + input;

		cout << "Numeric format is: " << output << setprecision(8) << endl;

	} else
	{
		cout << "Numeric format is : " << input << setprecision(8) << endl;
	}
	
	return 0;
}