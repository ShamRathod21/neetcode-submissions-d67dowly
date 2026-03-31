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
    int lengthOfList(ListNode* node) {
        int len = 0;
        while(node) {
            len++;
            node = node->next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        n = lengthOfList(head) - n;
        ListNode* node = head;
        if(n == 0)
            return head->next;
        while(i < n-1) {
            node = node->next;
            i++;
        }
        node->next = node->next != nullptr ? node->next->next : nullptr;
        return head; 
    }
};
