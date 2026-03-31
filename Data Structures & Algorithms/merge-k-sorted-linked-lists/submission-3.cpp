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
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr) 
            return l1;
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2-> val) {
                tmp->next = l1;
                l1 = l1->next;
                tmp = tmp->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
                tmp = tmp->next;
            }
        }
        if(l1 != nullptr) {
            tmp->next = l1;
        }
        if(l2 != nullptr) {
            tmp->next = l2;
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 1)
            return lists[0];
        if(lists.size() == 0)
            return nullptr;
        ListNode* l1 = lists[0];
        for(int i = 1; i < lists.size(); i++) {
            l1 = mergeTwoList(l1,lists[i]);
        }
        return l1;
    }
};
