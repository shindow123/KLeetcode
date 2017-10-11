#include <vector>
using namespace std;

void swap(vector<int>& data, int idx1, int idx2)
{
	// 判断idx1,2合法性
	int temp = data[idx2];
	data[idx2] = data[idx1];
	data[idx1] = temp;
}

int Partition(vector<int>& data, int start, int end) 
{
	if (end == 0)
	{
		return 0;
	}

	int key = data[0];
	int storeIdx = start;
	swap(data, storeIdx, end);
	
	for (int i = start; i < end; i++)
	{
		if (data[i] < key)
		{
			swap(data, storeIdx, i);
			storeIdx++;
		}
	}

	swap(data, storeIdx, end);
	return storeIdx;
}

int Partition(vector<int>& data, int length, int start, int end) 
{
	if (length == 0 || end == 0)
	{
		return 0;
	}

	int i = 1;
	int j = length - 1;
	int key = data[0];

	while (i < j)
	{
		while (i < j)
		{
			if (data[i] > key)
			{
				break;
			}
			i++;
		}

		while (i < j)
		{
			if (data[j] < key)
			{
				break;
			}
			j--;
		}

		if (i < j)
		{
			swap(data, i, j);
			i++;
			j--;
		}
	}
	
	swap(data, 0, j);
	return i - 1;
}
