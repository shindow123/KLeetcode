#include <string>
#include <iostream>
using namespace std;

class Solution {
	public:
		static	bool isSubsequence(string s, string t) {
			int lenS = s.length();
			int lenT = t.length();
			
			int sIdx = 0;
			int tIdx = 0;
			int lastIndex = 0;
			int curIndex = 0;
			while (sIdx < lenS)
			{
				curIndex = t.find_first_of(s[sIdx], lastIndex);	
				cout << "curIndex:" << curIndex << ", lastIndex:" << lastIndex << endl;
				if (curIndex == string::npos)
					return false;

				sIdx++;
				lastIndex = curIndex + 1;
			}

			return true;





			//if (!lenS) return true;/*{{{*/
			//if (!lenT && lenS) return false;

			//int sIdx = 0;
			//bool isSubsequence[lenS][lenT];
			//

			//for (int i = 0; i < lenT && sIdx < lenS; i++)
			//{
			//	if (s[sIdx] == t[i])
			//	{
			//		isSubsequence[sIdx][i] = i ? isSubsequence[sIdx][i - 1] : true;
			//		sIdx++;
			//	}
			//	else
			//	{
			//		isSubsequence[sIdx][i] = i ? isSubsequence[sIdx][i - 1] : false;	
			//	}
			//}

			//return ++sIdx == lenS ? true : false;/*}}}*/
		}
};

int main()
{
	string s = "abc";
	string t = "ahbgdc";
	Solution::isSubsequence(s, t);
}
