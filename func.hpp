#include"Header.h"
#include"Sequence.hpp"


int compare(int x, int y)
{
	if (x > y)
		return 1;
	else
		if (x < y)
			return -1;
		else
			return 0;
};
int compare(float x, float y)
{
	if (x > y)
		return 1;
	else
		if (x < y)
			return -1;
		else
			return 0;
};
int compare(char x, char y)
{
	if (x > y)
		return 1;
	else
		if (x < y)
			return -1;
		else
			return 0;
};

int compare(std::string x, std::string y)
{
	if (x > y)
		return 1;
	else
		if (x < y)
			return -1;
		else
			return 0;
};