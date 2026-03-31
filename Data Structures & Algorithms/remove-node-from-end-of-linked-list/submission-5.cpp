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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* prev = head;
        
        int len = 0;
        while(temp != nullptr) {
            temp = temp->next;
            len++;
        }
        temp = head;
        n = len - n ;
        if(n == 0) {
            head = head->next;
            return head;
        }
        int i = 0;
        while(i < n) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        prev->next = temp->next;
        // temp->next = nullptr;
        return head;
    }
};
