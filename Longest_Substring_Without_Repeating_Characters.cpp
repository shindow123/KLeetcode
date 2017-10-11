#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> curSubStrs;
            int sLen = s.size();
            int curLen = 0;
            int maxLen = 0; 
			int startIdx = 1;
			s = " " + s;
            for (int i = 1; i <= sLen; i++)
            {   
				char curChar = s[i];
				if (curSubStrs[curChar] >= startIdx)
				{
					if (curLen > maxLen)
					{
						maxLen = curLen;
					}
					curLen = i - curSubStrs[curChar];
					startIdx = curSubStrs[curChar] + 1;
				}
				else
				{
					curLen++;
				}
				
				curSubStrs[s[i]] = i;
            }   
        
            if (curLen > maxLen)
            {   
                maxLen = curLen;
            }
            
            return maxLen;
		}
};

int main()
{
	Solution S;
	int S.lengthOfLongestSubstring("aab");
}
