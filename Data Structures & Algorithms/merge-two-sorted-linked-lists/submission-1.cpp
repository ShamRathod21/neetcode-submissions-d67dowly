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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergeHead = new ListNode();
         ListNode* head = mergeHead;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                mergeHead->next = list1;
                list1 = list1->next;
            } else if(list1->val > list2->val) {
                mergeHead->next = list2;
                list2 = list2->next;
            }
            mergeHead = mergeHead->next;
        }
        while(list1 != nullptr) {
             mergeHead->next = list1;
                list1 = list1->next;
                mergeHead = mergeHead->next;
        }
        while(list2 != nullptr) {
            mergeHead->next = list2;
            list2 = list2->next;
            mergeHead = mergeHead->next;
        }
        return head->next;
    }
};
