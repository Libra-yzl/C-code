#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
#include <list>

struct ListNode
{
    ListNode* next;
    int _val;

    ListNode(const int& val)
        :_val(val)
        ,next(nullptr)
    {}
};

class Solution {
public:
    int detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return 0;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (fast == nullptr || fast->next == nullptr) return 0;
        ListNode* head2 = slow;
        head2 = head2->next;
        ListNode* cur = head2;
        ListNode* head1 = fast;
        head1->next = nullptr;

        head1 = head;
        // head2 = slow;

        int cnt1 = 0, cnt2 = 0;
        while (head1) {
            head1 = head1->next;
            ++cnt1;
        }
        head1 = head;
        while (head2) {
            head2 = head2->next;
            ++cnt2;
        }
        head2 = cur;
        if (cnt1 > cnt2) {
            int cnt = cnt1 - cnt2;
            while (cnt--) head1 = head1->next;
        }
        else {
            int cnt = cnt2 - cnt1;
            while (cnt--) head2 = head2->next;
        }
        while (head1 != head2) {
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1->_val;
    }
};


int main()
{
    Solution sol;
    ListNode* phead = new ListNode(0);
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    phead->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;
    
    /*ListNode* cur = phead;
    while (cur != nullptr) {
        cout << cur->_val << " ";
        cur = cur->next;
    }*/

    cout << sol.detectCycle(phead) << endl;
    //cout << node3->_val << endl;
    return 0;
}


//int main()
//{
//	//printf("hello world!"); 
//	while (1)
//	{
//		printf("hello\n");
//		Sleep(1000);
//	}
//	return 0;
//}
