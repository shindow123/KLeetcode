#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
		int beginIdx = 0;
		int endIdx = height.size() - 1;        
		if (endIdx < 0) return 0;

		int maxWater = 0;
		int leftH = height[beginIdx];
		int rightH = height[endIdx];
		while (beginIdx < endIdx && height[beginIdx] <= height[beginIdx + 1]) 
		{ 
			leftH = height[beginIdx];
			beginIdx++;
		}
		while (beginIdx < endIdx && height[endIdx] <= height[endIdx - 1]) 
		{
			rightH = height[endIdx];
			endIdx--; 
		}

		while (beginIdx < endIdx)
		{
           if (leftH <= rightH)
            {
                if (leftH > height[beginIdx + 1])
                { 
                    maxWater += leftH - height[++beginIdx];  
                } 
                else
                { 
                    leftH = height[++beginIdx]; 
                } 
            }
            else
            {
                if (rightH > height[endIdx - 1])
                { 
                    maxWater += rightH - height[--endIdx];  
                } 
                else
                { 
                    rightH = height[--endIdx];  
                }
            }
		}

		return maxWater;
    }
};
