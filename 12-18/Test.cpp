////#include "Hash.h"
//#include "UnorderedSet.h"
//#include "UnorderedMap.h"
//
//
//int main()
//{
//	//yzl::HashTable_test1();
//	//yzl::HashTable_test2();
//	//yzl::HashTable_test3();
//	//yzl::unorderset_test1();
//	yzl::unordermap_test1();
//
//	return 0;
//}
#include <stdio.h>
#include "arrange.h"

int main()
{
	// int a[] = { 1,-6,5,2,-3,0,0,-10,18,-15,0,-12,3,8 }; 
	//int a[] = { 0,0,0,0,0,-1,-2,-3,-4,-5,-6 };
	//int a[] = { 1,2,3,4,5,0,0,0,0,0 };
	int a[] = { 1,2,3,-1,-2,-3,5,-6,8,-10,8,23,490,-105,-58,-812 };
	int size = sizeof a / sizeof a[0];
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	func(a, size);

	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}