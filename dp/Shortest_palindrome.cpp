#include <string>
using namespace std;

class Solution {
	public:
		string shortestPalindrome(string s) {
            int len = s.length();
            bool dp[len][len];
            int max = 1;
            int start_idx = 0;
            for (int i = len - 1; i >= 0; i--)
            {
                for (int j = i; j < len; j++)
                {
                    int substring_len = j - i + 1;
                    dp[i][j] = (s[i] == s[j]) && ((substring_len < 4) || dp[i+1][j-1]);
                    if (dp[i][j] && (substring_len >= max))
                    {
                        max = substring_len;
                        start_idx = i;
                    }
                }
            }

			int mid_idx = (start_idx + max) / 2;
            //return s.substr(start_idx, max);
			
		}
};
