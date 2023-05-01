#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>


typedef int SLTDataType;

struct ListNode
{
    int val;
    struct ListNode* next;
};


struct ListNode* CreateSLTNode(SLTDataType* arr, int n)
{
    struct ListNode* phead = NULL;
    struct ListNode* ptail = NULL;

    for (int i = 0; i < n; i++)
    {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (!newnode)
        {
            perror("CreateSLTNode::malloc");
            exit(-1);
        }
        else
        {
            newnode->val = arr[i];
            newnode->next = NULL;
        }
        if (phead == NULL)
        {
            phead = ptail = newnode;
        }
        else
        {
            ptail->next = newnode;
            ptail = newnode;
        }
    }
    return phead;
}

SLTPrint(struct ListNode* phead)
{
    struct ListNode* cur = phead;
    while (cur)
    {
        printf("%d->", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");
}


int main()
{
    struct ListNode* plist = NULL;
    SLTDataType arr[] = { 1,8,9,7,2,4,6 };
    plist = CreateSLTNode(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    SLTPrint(plist);

    SLTPrint(plist);
    return 0;
}