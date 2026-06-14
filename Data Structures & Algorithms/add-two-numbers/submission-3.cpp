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
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int acc = 0;
        while (acc || l1 || l2) {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;

            int sum = v1 + v2 + acc;

            acc = sum / 10;
            curr->next = new ListNode(sum % 10);

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            curr = curr->next; 
        }

        return dummy->next;
    }
};
