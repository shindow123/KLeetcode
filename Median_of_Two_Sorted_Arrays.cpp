#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int len1 = nums1.size();
			int len2 = nums2.size();
			if ((len1 + len2) % 2)
			{
				return findKthDigit(nums1, len1, 0, nums2, len2, 0, (len1 + len2) / 2);
			}
			else
			{
				return (findKthDigit(nums1, len1, 0, nums2, len2, 0, (len1 + len2) / 2)  + findKthDigit(nums1, len1, 0, nums2, len2, 0, (len1 + len2) / 2 - 1)) / 2.0f;
			}
		}

		double findKthDigit(vector<int>& nums1, int m, int start1, vector<int>& nums2, int n, int start2, int k)
		{
			cout << "m:" << m << ", start1:" << start1 << ", n:" << n << ", start2:" << start2 << ", k:" << k << endl;
			if (m == 0)
			{
				return nums2[k];
			}

			if (n == 0)
			{
				return nums1[k];
			}

			if (k == 0)
			{
				return min(nums1[start1], nums2[start2]);
			}

			int mid1Idx = start1 + min((k + 1)/2, m);
			int mid2Idx = start2 + k - mid1Idx + 1;

			if (nums1[mid1Idx - 1] < nums2[mid2Idx - 1])
			{
				//return findKthDigit(nums1, m - (mid1Idx - start1 + 1), mid1Idx + 1, nums2, n, start2, k - (mid1Idx - start1 + 1));
				return findKthDigit(nums1, m, mid1Idx, nums2, n, start2, k - (mid1Idx - start1));
			}
			else if(nums1[mid1Idx - 1] > nums2[mid2Idx - 1])
			{
				//return findKthDigit(nums1, m, start1, nums2, n - (mid2Idx - start2 + 1), mid2Idx + 1, k - (mid2Idx - start2 + 1));
				return findKthDigit(nums1, m, start1, nums2, n, mid2Idx, k - (mid2Idx - start2));
			}
			else 
			{
				return nums1[mid1Idx - 1];
			}
		}
};

int main()
{
	vector<int> n1 = {1,3,5};
	vector<int> n2 = {2,4,6};

	Solution s;
	cout << "return:" << s.findMedianSortedArrays(n1, n2) << endl;
}
