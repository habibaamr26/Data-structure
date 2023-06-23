
#include <iostream>
#include<stack>
using namespace std;

bool balanced(string exp)
{
	stack<char>x;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			x.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (x.empty() || !(exp[i] == ')' && x.top() == '(' || exp[i] == ']' && x.top() == '[' || exp[i] == '}' && x.top() == '{'))
			{
				return false;
			}
			else
			{
				x.pop();
			}
		}
	}
	return x.empty();

}