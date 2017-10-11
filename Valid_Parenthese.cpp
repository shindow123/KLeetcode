#include <string>
#include <stack>
using namespace std;

class Solution {
	public:
		bool isValid(string s) {
			stack<char>	parentheseStack;
			for (int i = 0; i < s.length(); i++)
			{
				char topE = parentheseStack.empty() ? ' ' : parentheseStack.top();
				switch (s[i])
				{
					case ']' :
						if (topE != '[') return false;
						else parentheseStack.pop();
						break;
					case ')' :
						if (topE != '(') return false;
						else parentheseStack.pop();
						break;
					case '}' :
						if (topE != '{') return false;
						else parentheseStack.pop();
						break;
					default:
						parentheseStack.push(s[i]);
				}
			}

			if (parentheseStack.empty())
				return true;
			else 
				return false;
		}
};
