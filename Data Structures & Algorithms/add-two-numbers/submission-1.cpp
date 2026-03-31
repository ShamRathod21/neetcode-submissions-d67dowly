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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode(0);
        ListNode* tmp = result;
        while(l1 != NULL && l2 != NULL) {
            carry += l1->val+l2->val;
            tmp->next = new ListNode(carry%10);
            carry = carry/10;
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2 ->next;
        }
        while(l1 != NULL) {
            carry += l1->val;
            tmp->next = new ListNode(carry%10);
            carry = carry/10;
            tmp = tmp->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            carry += l2->val;
            tmp->next = new ListNode(carry%10);
            carry = carry/10;
            tmp = tmp->next;
            l2 = l2 ->next;
        }
        if(carry)
            tmp->next = new ListNode(carry);
        return result->next;
 
        
    }
};
