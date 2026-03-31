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
    bool hasCycle(ListNode* head) {
        ListNode* first, *second;
        first = head;
        second = head->next;
        while(first != nullptr && second != nullptr) {
           if(first == second && first != nullptr)
            return true;
            second = second->next != nullptr ? second->next->next : nullptr;
            first = first->next;
        }
        return false;
    }
};
