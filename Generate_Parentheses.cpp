#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		vector<string> resVec;
		//generateParenthesisImp(n, n, "", resVec);
		string correctPt;
		int i = 1;
		bool stop = false;
		int leftn = n;
		int rightn = n;
		while (i > 0 && !stop)
		{
			if (i == n)
			{
				resVec.push_back(correctPt);
			}
			else
			{
				correctPt = '(';
				while (--leftn > 0 && rightn > leftn)
				{
					correctPt += '(';
				}

				if (rightn > leftn)
				{
					i = i + 1;
				}
				else
				{
					i = i - 1;
				}

			}
		}

		return resVec;
    }

	void generateParenthesisImp(int leftn, int rightn, string out, vector<string>& res)
	{
		if (!leftn && !rightn) 
		{
			res.push_back(out);
		}
		else if (leftn > rightn)
		{
			return;
		}
		else
		{
			if (leftn > 0)
			{
				generateParenthesisImp(leftn - 1, rightn, out + '(', res);
			}
			if (rightn > 0)
			{
				generateParenthesisImp(leftn , rightn - 1, out + ')', res);
			}
		}

			
	}

};

int main()
{
	Solution s;
	vector<string> v1 = s.generateParenthesis(1);
	cout << "1:" << endl;
	for (auto item : v1)
	{
		cout << item << endl;
	}

	vector<string> v2 = s.generateParenthesis(2);
	cout << "2:" << endl;
	for (auto item : v2)
	{
		cout << item << endl;
	}

	vector<string> v3 = s.generateParenthesis(3);
	cout << "3:" << endl;
	for (auto item : v3)
	{
		cout << item << endl;
	}

	vector<string> v4 = s.generateParenthesis(4);
	cout << "4:" << endl;
	for (auto item : v4)
	{
		cout << item << endl;
	}
};
