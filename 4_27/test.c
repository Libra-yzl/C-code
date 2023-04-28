#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>

typedef int SLDataType;

struct ListNode
{
	SLDataType val;
	struct ListNode* next;
};

struct ListNode* CreateSLNode(SLDataType* arr, int sz)
{
	struct ListNode* head = NULL;
	struct ListNode* tail = NULL;
	struct ListNode* newnode = NULL;

	for (int i = 0; i < sz; i++)
	{
		newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (!newnode)
		{
			perror("CreateSLNode::malloc");
			exit(-1);
		}
		newnode->val = arr[i];
		newnode->next = NULL;
		if (!head)
		{
			head = tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
	}
	return head;
}

void SLPrint(struct ListNode* phead)
{
	struct ListNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	//fast先走k-1步（走k步时最终结束条件为fast为空）
	//fast和slow一起走
	//当fast->next为空的时候结束 此时slow就在倒数第k个节点的位置
	struct ListNode* fast = pListHead;
	struct ListNode* slow = pListHead;
	slow = fast;
	//fast先走k-1步
	while (--k)
	{
		//k超过了链表的元素个数
		if (!fast)
			return NULL;
		fast = fast->next;
	}
	if (!k && !fast)
		return NULL;
	//fast和slow一起走
	while (fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
//int main()
//{
//	SLDataType arr1[] = { 1,2,3,4,5 };
//	struct ListNode* plist = NULL;
//	plist = CreateSLNode(arr1, (int)(sizeof(arr1) / sizeof(arr1[0])));
//	SLPrint(plist);
//
//	struct ListNode* newnode = FindKthToTail(plist, 6);
//	SLPrint(newnode);
//	return 0;


int main()
{
	int day = 0;
	int month = 0;
	int year = 0;
	scanf("%d %d %d", &year, &month, &day);
	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month >= 2)
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			days[1] += 1;
	}
	for (int i = 0; i < month-1; i++)
	{
		day += days[i];
	}
	printf("%d\n", day);
	return 0;
}