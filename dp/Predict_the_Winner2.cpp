#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    static bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        if (len == 1)
             return true;
        
        int sum = 0;
        for(auto item : nums)
        {
            sum += item;
        }

		int maxScores[len][len];
		memset(maxScores, 0, sizeof(int) * len * len);
		bool isMyTurn = len % 2 ? true : false;
		for (int i = 0; i < len; i++)
		{
			maxScores[i][i] = isMyTurn ? nums[i] : 0;
		}

		for (int i = len - 1; i >= 0; i--)
		{
			isMyTurn = len % 2 ? false : true;
			for (int j = i + 1; j < len && i < j; j++)
			{
				if (isMyTurn)
				{
					maxScores[i][j] = (i == j) ? nums[i] : max(maxScores[i+1][j] + nums[i], maxScores[i][j-1] + nums[j]);
				}
				else
				{
					maxScores[i][j] = (i == j) ? 0 : min(maxScores[i+1][j], maxScores[i][j-1]);
				}

				isMyTurn = !isMyTurn;
			}
		}

		cout << "maxScore:" << maxScores[0][len-1] << endl;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				cout << maxScores[j][i] << " ";
				if (maxScores[j][i] < 10)
					cout << " ";
			}
			cout << endl;
		}

        return maxScores[0][len-1]*2 >= sum;
    }

    static int getScore(vector<int>& nums, int i, int j, bool isMyTurn)
    {
        if (i == j)
        {
			//cout << "i=j:" << nums[i] << "isMyTurn:"<< isMyTurn << endl;
            return isMyTurn ? nums[i] : 0;
        }   

        if (isMyTurn)
        {
			int maxNum = max(getScore(nums, i + 1, j, !isMyTurn) + nums[i], getScore(nums, i, j - 1, !isMyTurn) + nums[j]);
			//cout << "i:" << i << endl;
			//cout << "j:" << j << endl;
			//cout << "max, isMyTurn:" << maxNum << endl;
			return maxNum;
        }
        else
        {
            //return nums[i] > nums[j] ? getScore(nums, i + 1, j, !isMyTurn) : getScore(nums, i, j - 1, !isMyTurn);
            return min(getScore(nums, i + 1, j, !isMyTurn) , getScore(nums, i, j - 1, !isMyTurn));
        }
    } 
};

int main()
{
	vector<int> test = {2,4,55,6,8};
	Solution::PredictTheWinner(test);
	return 1;
}
