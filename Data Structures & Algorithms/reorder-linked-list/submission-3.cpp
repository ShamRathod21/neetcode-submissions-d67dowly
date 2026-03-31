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
/// 1 2 3
/// 6 5 4
class Solution {
public:
    int lengthOfLinkedList(const ListNode* node) {
        int len = 0;
        while(node != nullptr) {
            len++;
            node = node->next;
        }
        return len;
    }
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        int length = lengthOfLinkedList(head);
        int mid = length/2;
        ListNode* tmp = head;
        for(int i = 1; i <= mid; i++) {
            tmp = tmp->next;
        }
        ListNode* s2 = tmp -> next;
        tmp->next = nullptr;
        stack<ListNode*> s;
        while(s2 != nullptr) {
            s.push(s2);
            s2 = s2->next;
        }
        // 0 1 2 3
        // 6 5 4
        tmp = head;
        while(tmp != nullptr && !s.empty()) {
            s2 = tmp->next;
            tmp->next = s.top();
            s.pop();
            tmp->next->next = s2;
            tmp = s2;
        }
        return;

    }
};
