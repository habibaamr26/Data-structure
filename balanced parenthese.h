
#include <iostream>
#include<stack>
using namespace std;

bool balanced(string exp)
{
	stack<char>st;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')                  // enter left parenthese in stack
			st.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')            
		{
			if (st.empty() || !(exp[i] == ')' && st.top() == '(' || exp[i] == ']' && st.top() == '[' || exp[i] == '}' && st.top() == '{'))
			{
				return false;
			}
			else
			{
				st.pop();
			}
		}
	}
	return st.empty();

}
