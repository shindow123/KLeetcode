/*
 * 输出一个字符串所有排列。注意有重复字符。
 */
#include <iostream>
#include <string>
#include <vector>

int idx = 1;

void genStrArrange(std::vector<char>& s, std::string prefix)
{
	if (s.empty()) 
	{
		std::cout << idx++ << ": "<<prefix<<std::endl;
		return ;
	}

	std::string lastChar = "";
	for (auto i : s)
	{
		std::string curChar;
		curChar += i;
		if (curChar == lastChar)
		{
			continue;
		}

		std::string tmpPrefix = prefix + i; 
		std::vector<char> s2 = s;
		// 这里可以改为二分查找 或者 用KEY_VALUE存储
		for (std::vector<char>::iterator j=s2.begin(); j != s2.end(); j++)
		{
			if (*j == i)
			{
				std::vector<char>::iterator delItr = j;
				j++;
				s2.erase(delItr);
				break;
			}
		}
		genStrArrange(s2, tmpPrefix);
		lastChar = i;
	}
	return;
}

int main()
{
	std::vector<char> s = {'a','b','c','c'};
	genStrArrange(s, "");
	return 0;
}

