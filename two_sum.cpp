#include <vector>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			int index1 = 0;
			int index2 = 0;
			vector<int> result;
			for (auto i : nums)
			{
				index2 = 0;
				for (auto j : nums)
				{
					if (index1 == index2)
					{
						index2++;
						continue;
					}

					if ((i+j) == target)
					{
						result.push_back(index1);
						result.push_back(index2);
						return result;
					}
					index2++;
				}
				index1++;
			}
			
			return result;
		}
};


int main()
{
	vector<int> input = {2,7,11,15};
	Solution s;
	s.twoSum(input, 9);

	return 0;
}
