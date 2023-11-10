#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node
{
    int val;
    Node* next;
    Node* random;
    Node(int value)
        :val(value)
        ,next(nullptr)
        ,random(nullptr)
    {}
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        map<Node*, Node*> copy_map;
        Node* cur = head;
        Node* newhead, *newtail;
        newhead = newtail = nullptr;
        while (cur)
        {
            Node* newnode = new Node(cur->val);
            copy_map[cur] = newnode; 
            if(newhead == nullptr)
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