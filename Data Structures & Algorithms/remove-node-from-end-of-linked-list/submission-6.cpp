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

        int len = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            temp = temp->next;
            len++;
        }
        n = len - n;
        if(n == 0) {
            head = head->next;
            return head;
        }
        ListNode* prev = head;
        ListNode* next = head;
        int i = 0;
        while(next != nullptr && i < n) {
            prev = next;
            next = next->next;
            i++;
        }
        prev->next = next->next;
        next->next = nullptr;
        free(next);
        return head;
    }
};
