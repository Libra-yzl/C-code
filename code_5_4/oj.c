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


struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode* newhead = NULL;
    struct ListNode* newtail = NULL;
    if (m == n)
        return head;
    if (head == NULL || head->next == NULL)
        return head;
    newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (newhead == NULL)
    {
        perror("error");
        exit(-1);
    }
    newhead->next = head;

    //�ҵ���ת����ǰһ���ڵ�
    struct ListNode* cur = newhead;
    struct ListNode* revHead = newhead;
    while (m--)
    {
        if (1 == m)
            revHead = cur->next;
        cur = cur->next;
    }
    //�ҵ�Ҫ��ת�����ͷ�ڵ�
    struct ListNode* phead = cur;
    //�ҷ�ת����ĺ�һ���ڵ�
    struct ListNode* revTail = NULL;
    cur = newhead;
    while (n--)
    {
        if (0 == n)
            revTail = cur->next;
        cur = cur->next;
    }
    revTail = cur->next;
    //��ת��������
    cur = phead;
    struct ListNode* curHead = NULL;
    struct ListNode* ptail = phead;//��ת�����β�ڵ�
    while (cur != revTail)
    {
        struct ListNode* nextnode = cur->next;
        cur->next = curHead;
        curHead = cur;
        cur = nextnode;
    }

    //���ӽڵ�
    ptail->next = revTail;
    revHead->next = curHead;


    //�ͷ��ڱ�λͷ�ڵ�
    head = newhead->next;
    free(newhead);
    return head;
}

int main()
{
    struct ListNode* plist = NULL;
    SLTDataType arr[] = { 1,2,3,4,5 };
    plist = CreateSLTNode(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    SLTPrint(plist);

    plist = reverseBetween(plist, 2, 4);

    SLTPrint(plist);
    return 0;
}