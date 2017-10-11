#include "partition.h"
#include <stdio.h>

int main()
{
	std::vector<int> data = {3,5,7,8,7,2,1,1,4,9,1,6};
	//std::vector<int> data = {};
	int key = Partition(data, 0, data.size()-1);	
	printf("key:%d\n", key);
	for (auto i : data)
	{
		printf("data:%d\t", i);
	}
	printf("\n");
	return 0;
}
