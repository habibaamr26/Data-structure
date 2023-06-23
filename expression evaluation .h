
#include <iostream>
#include <stack>
using namespace std;
template<class t>
t Evaluation(string exp)
{
	stack<char>st;
	t pop1, pop2;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
			st.push(exp[i]-'0');
		else
		{
			pop1 = st.top();
			st.pop();
			pop2 = st.top();
			st.pop();
			if (exp[i] == '+')
				st.push(pop1 + pop2);
			else if (exp[i] == '/')
				st.push(pop2 / pop1);
			else if (exp[i] == '*')
				st.push(pop2 * pop1);
			else if (exp[i] == '-')
				st.push(pop2 - pop1);
			else if (exp[i] == '^')
				st.push(pow(pop2 , pop1));
		}
	}
	return st.top();
}
