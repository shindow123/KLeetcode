/*
 * 输入一个字符串，输出长型整数。
 */
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <ctype.h>
#include <stdio.h>

long atol(char* str)
{
	//const char* fst = str.front().c_str();
	char* p = str;
	int mark = 1;
	if (*p == '-')
	{
		mark = -1;
		p++;
	}

	long result = 0;
	long m = 1;
	while (isdigit(*p))
	{
		result += (*p - '0') * m;
		m *= 10;
		p++;
	}

	std::cout << "*p:" << *p << " r:" << result <<std::endl;

	if (*p == 0)
	{
		return result*mark;
	}

	return -99999999;
}

int main()
{
	std::cout << atol("21312321") << std::endl;
	std::cout << atol("-21312321") << std::endl;
	std::cout << atol("a-21312321") << std::endl;
	return 0;
}
