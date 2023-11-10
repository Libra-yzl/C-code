#include <iostream>
#include <map>

using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* random;

    Node(int value)
        :val(value)
        , next(nullptr)
        , random(nullptr)
    {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //if (head == nullptr) return nullptr;
        map<Node*, Node*> copy_map;
        Node* cur = head;
        Node* newhead, * newtail;
        newhead = newtail = nullptr;
        while (cur)
        {
            Node* newnode = new Node(cur->val);
            copy_map[cur] = newnode;
            if (newhead == nullptr)
            {
                newhead = newtail = newnode;
            }
            else
            {
                newtail->next = newnode;
                newtail = newtail->next;
            }
            cur = cur->next;
        }
        cur = head;
        Node* copycur = newhead;
        while (cur)
        {
            if (cur->random == nullptr)
            {
                copycur->random = nullptr;
            }
            else
            {
                copycur->random = copy_map[cur->random];
            }
            cur = cur->next;
            copycur = copycur->next;
        }
        return newhead;
    }
};

int main()
{
    Node* node1 = new Node(7);
    Node* node2 = new Node(3);
    Node* node3 = new Node(5);
    Node* node4 = new Node(2);
    Node* node5 = new Node(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = nullptr;

    Solution sol;
    Node* rethead = sol.copyRandomList(node1);
    Node* cur = rethead;
    while (cur)
    {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    cur = rethead;
    while (cur)
    {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
}