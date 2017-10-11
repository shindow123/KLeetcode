#include <vector>
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

        int maxScore = max(getScore(nums, 1, len - 1, false) + nums[0], getScore(nums, 0, len -2, false) + nums[len - 1]);

		//cout << "maxScore:" << maxScore << endl;
        return maxScore*2 >= sum;
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
