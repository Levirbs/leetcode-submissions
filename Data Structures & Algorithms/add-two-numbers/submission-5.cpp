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
        ListNode dummy;
        ListNode* curr = &dummy;
        int acc = 0;

        while (l1 || l2 || acc > 0) {
            int a = l1 ? l1->val : 0; 
            int b = l2 ? l2->val : 0;

            int sum = a + b + acc;

            curr->next = new ListNode(sum % 10);

            acc = sum / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            curr = curr->next;
        }

        return dummy.next;
    }
};
