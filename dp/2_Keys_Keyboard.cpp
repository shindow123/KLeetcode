#include <math.h>
#include <iostream>
#include <string.h>

using namespace std;

class Solution {
	public:
	static	int minSteps(int n) {
			int factor = 2;
			int sumSteps = 0;
			while (n > 1 && factor < n)
			{
				if (n % factor == 0)
				{
					n /= factor;
					sumSteps += factor;
				}
				else
				{
					factor++;
				}
			}
			return sumSteps;
		}
};

int main()
{
}
