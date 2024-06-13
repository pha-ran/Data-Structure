#include "List.h"
#include <stdio.h>

void Test(void)
{
	List<int> my;
	List<int>::Iterator b = my.begin();
	List<int>::Iterator e = my.end();

	printf("empty %d | size %d\n", my.empty(), my.size());
	printf("data %d\n", *b);
	printf("== %d | != %d\n", b == e, b != e);

	++e;
}

int main(void)
{
	Test();

	return 0;
}
