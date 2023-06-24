
#include <iostream>
#include <stack>
using namespace std;


int Priority(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '^')
		return 3;
	else return 0;
}


void convert(string exp,string &postfix)
{
	stack <char>st;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
			postfix += exp[i];
		else if(exp[i]=='(')
			st.push(exp[i]);
		else if (exp[i] == ')')
		{
			while (st.top() != '(')
			{
				postfix += st.top();
				st.pop();
			}
			st.pop();
		}
		else
		{
			while (!st.empty() && Priority(exp[i]) <= Priority(st.top()))
			{
				postfix += st.top();
				st.pop();
			}
			st.push(exp[i]);
		}

	}


	while (!st.empty())
	{
		postfix += st.top();
		st.pop();
	}
}
