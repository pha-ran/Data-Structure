#include "List.h"
#include <stdio.h>

class CTest
{
public:
	CTest(int i, int j) : _i(i), _j(j) { printf("생성자\n"); }
	~CTest() { printf("소멸자\n"); }

	int _i;
	int _j;
};

List<CTest> my;

void Print(void)
{
	for (List<CTest>::Iterator it = my.begin(); it != my.end(); ++it)
	{
		printf("(%d,%d) ", (*it)._i, (*it)._j);
	}

	printf("\nempty %d | size %d\n\n", my.empty(), my.size());
}

void Test(void)
{
	my.emplace(my.end(), 1, 2);
	Print();

	my.emplace(my.end(), 2, 3);
	Print();

	my.emplace(my.end(), 3, 4);
	Print();

	my.emplace(my.end(), 4, 5);
	Print();

	List<CTest>::Iterator it = my.erase(++my.begin());
	Print();

	my.erase(--my.end());
	Print();
}

int main(void)
{
	Test();

	return 0;
}
