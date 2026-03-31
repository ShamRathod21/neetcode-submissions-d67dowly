/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> sp;
        ListNode* temp = head;
        while(temp != nullptr) {
            sp.push(temp);
            temp = temp->next;
        }
        temp = head;
        if(sp.size()%2 == 0) {
            while(!sp.empty() && sp.top() != temp->next) {
            ListNode* next = temp->next;
            temp->next = sp.top();
            sp.top()->next = next;
            sp.pop();
            temp = next;
        }
        temp->next = sp.top();
            sp.top()->next = nullptr;
        } else {
            while(!sp.empty() && sp.top() != temp) {
            ListNode* next = temp->next;
            temp->next = sp.top();
            sp.top()->next = next;
            sp.pop();
            temp = next;
        }
        temp->next = nullptr;
        }
    }
};
