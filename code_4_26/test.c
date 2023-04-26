#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef int SLTDataType;

// Definition for singly-linked list.
struct ListNode 
{     
	int val;
	struct ListNode *next;
};


//struct ListNode* BuySLTNode(SLTDataType n)
//{
//    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
//    if (!newnode)
//    {
//        perror("BuySLTNode::malloc");
//        exit(-1);
//    }
//    newnode->val = n;
//    newnode->next = NULL;
//    return newnode;
//}
//
//struct ListNode* CreateSLTNode(SLTDataType* arr, int n)
//{
//    struct ListNode* newnode = BuySLTNode(arr[0]);
//    struct ListNode* head = newnode;
//    struct ListNode* tail = newnode;
//    for (int i = 1; i < n; i++)
//    {
//        newnode = BuySLTNode(arr[i]);
//        tail->next = newnode;
//        tail = newnode;
//    }
//    return head;
//}

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
        if (!phead)
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

struct ListNode* removeElements1(struct ListNode* head, int val) 
{
    struct ListNode* newhead = head;
    struct ListNode* nextnode = NULL;
    //struct ListNode* cur = newhead;
    if (newhead == NULL)
        return NULL;
    struct ListNode* cur = newhead;
    while (cur)
    {
        if (cur->val == val)
        {
            nextnode = cur->next;
            free(cur);
            cur = nextnode;
        }
        else
        {
            newhead = cur;
            break;
        }
    }
    if (!cur)
        return NULL;
    struct ListNode* phead = newhead;
    while (cur)
    {
        while ((cur != NULL) && (cur->val != val))
        {
            newhead = cur;
            cur = cur->next;
        }
        if ((cur != NULL) && (cur->val == val))
        {
            nextnode = cur->next;
            free(newhead->next);
            newhead->next = nextnode;
            cur = nextnode;
        }
    }
    
    return phead;
}

struct ListNode* removeElements2(struct ListNode* head, int val)
{
    struct ListNode* cur = head;
    struct ListNode* phead = NULL;
    struct ListNode* newhead = NULL;
    struct ListNode* nextnode = NULL;
    while (cur)
    {
        //找不是val的节点
        if (cur->val != val)
        {
            if (newhead == NULL)
            {
                newhead = phead = cur;
            }
            else
            {
                newhead->next = cur;
                newhead = newhead->next;
            }
            cur = cur->next;
        }
        else
        {
            nextnode = cur->next;
            free(cur);
            cur = nextnode;
        }
    }
    if (newhead)
        newhead->next = NULL;
    return phead;
}

//带哨兵位头节点
struct ListNode* removeElements3(struct ListNode* head, int val)
{
    struct ListNode* cur = head;
    struct ListNode* phead = (struct ListNode*)malloc(sizeof(struct ListNode));;
    struct ListNode* ptail = phead;
    if (!phead)
    {
        perror("malloc");
        exit(-1);
    }
    phead->next = NULL;
    
    struct ListNode* nextnode = NULL;

    while (cur)
    {
        if (cur->val != val)
        {
            ptail->next = cur;
            ptail = ptail->next;
            cur = cur->next;
        }
        else
        {
            nextnode = cur->next;
            free(cur);
            cur = nextnode;
        }
    }

    ptail->next = NULL;

    nextnode = phead->next;
    free(phead);
    phead = nextnode;

    return phead;
}

//带哨兵位的头节点
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!head)
    {
        perror("malloc");
        exit(-1);
    }
    head->next = NULL;
    tail = head;

    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            tail = tail->next;

            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = tail->next;

            list2 = list2->next;
        }
    }

    if (list1)
        tail->next = list1;
    if (list2)
        tail->next = list2;

    struct ListNode* newhead = head->next;
    free(head);
    head = newhead;
    return head;
}

int main()
{
    struct ListNode* plist = NULL;
    struct ListNode* plist1 = NULL;
    struct ListNode* plist2 = NULL;
    SLTDataType arr[] = { 1,2,3 };
    SLTDataType arr1[] = { 1,2,4 };
    plist1 = CreateSLTNode(arr, (int)(sizeof(arr) / sizeof(arr[0])));
    //SLTPrint(plist1);
    ////plist = removeElements1(plist, 6);
    //plist1 = removeElements3(plist1, 6);
    //SLTPrint(plist1);
    plist2 = CreateSLTNode(arr1, (int)(sizeof(arr1) / sizeof(arr1[0])));
    plist = mergeTwoLists(plist1, plist2);
    SLTPrint(plist);
    return 0;
}
 