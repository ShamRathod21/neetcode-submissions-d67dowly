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
//  1 2 3 4 5 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode* temp = nullptr;
        ListNode* prev = nullptr;
        while(head->next != nullptr) {
            temp = head;
            head = head->next;
            temp->next = prev;
            prev = temp;
        }
        head->next = temp;
        return head;
    }
};
