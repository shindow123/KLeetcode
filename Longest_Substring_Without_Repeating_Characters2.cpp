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
			int oldIdx = 0;	
			int batchId = 1;
            for (int i = 0; i < len; i++)
            {   
				if (curSubStrs[s[i]] == batchId)
				{
					if (curLen > maxLen)
					{
						maxLen = curLen;
					}
					batchId++;
					curLen = 0;
				}
				
				curSubStrs[s[i]] = batchId;
				curLen++;
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
	S.lengthOfLongestSubstring("aab");
}
