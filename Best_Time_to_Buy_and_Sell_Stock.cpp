#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int startIdx = 1;
		for (; startIdx < prices.size() && prices[startIdx] >= prices[startIdx - 1]; startIdx++);
		int maxPro = startIdx  < prices.size() ? prices[startIdx] - prices[startIdx - 1] : 0;

		for (int i = startIdx + 1; i < prices.size(); i++)
		{
			int curPro = prices[i] - prices[startIdx];
			maxPro = max(maxPro, curPro);
			if (curPro < 0)
				startIdx = i;
			
		}

		return maxPro;
    }
};
