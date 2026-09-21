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
            int n1 = 0;
            int n2 = 0;

            if (l1) {
                n1 = l1->val;
                l1 = l1->next;
            }

            if (l2) {
                n2 = l2->val;
                l2 = l2->next;
            }

            int sum = n1 + n2 + acc;
            acc = sum / 10;

            curr->next = new ListNode((sum % 10));
            curr = curr->next;
        }

        return dummy.next;
    }
};
