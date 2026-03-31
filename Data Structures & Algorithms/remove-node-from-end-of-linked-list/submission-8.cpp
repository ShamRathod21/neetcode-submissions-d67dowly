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
    int length(ListNode* tmp) {
        int len = 0;
        while(tmp) {
            len++;
            tmp = tmp->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        n = length(head) - n;
        if(n == 0)
            return head->next;
        ListNode* s1 = head;
        for(int i = 1; i < n; i++){
            s1 = s1->next;
        }
        ListNode* tmp = s1->next;
        s1->next = tmp->next;
        tmp->next = nullptr;
        free(tmp);
        return head;

    }
};
