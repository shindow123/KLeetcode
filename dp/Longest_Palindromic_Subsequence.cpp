#include <string>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

class Solution {
public:
	int longestPalindromeSubseq(string s) {
        int len = s.length();
        if (len < 2)
            return len;

        int dp[len][len];
        for (int i = len - 1; i >= 0; i--)
        {
			dp[i][i] = 1;
			cout << "db[" << i << "][" << i << "] = " << dp[i][i] << endl; 
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = (i + 1 == j) ? 2 : dp[i+1][j-1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
				cout << "db[" << i << "][" << j << "] = " << dp[i][j] << endl; 
            }
        }
        return dp[0][len-1];
	}
};

int main()
{
	Solution s;
	s.longestPalindromeSubseq("bbbab");
	return 0;
}
