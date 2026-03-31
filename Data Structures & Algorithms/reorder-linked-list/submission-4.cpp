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
        ListNode* tmp = head;
        stack<ListNode*> s;
        int l = 0;
        while(tmp != nullptr) {
            s.push(tmp);
            tmp = tmp->next;
            l++;
        }
        tmp = head;
        int i = 0; 
        while(i < l/2) {
            ListNode* t = tmp->next;
            ListNode* top = s.top();
            s.pop();
            tmp->next = top;
            top->next = t;
            tmp = t;
            i++;
        }
        tmp->next = nullptr;
    }
};
