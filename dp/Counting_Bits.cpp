#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> countBits(int num) {
			vector<int> returns;	
			if (num < 0)
				return returns;

			returns.push_back(0);
			if (num < 1)
				return returns;

			for (int i = 1; i <= num; i++)
			{
				if (i  % 2 == 0)
				{
					returns.push_back(returns[i / 2]);
				}
				else 
				{
					returns.push_back(returns[i - 1] + 1);
				}
			}

			return returns;
		}
};
