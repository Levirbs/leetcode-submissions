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
        while (l1 || l2 || acc) {
            int v1 = 0;
            int v2 = 0;

            if (l1) {
                v1 = l1->val;
                l1 = l1->next;
            }

            if (l2) {
                v2 = l2->val;
                l2 = l2->next;
            }

            int sum = v1 + v2 + acc;

            ListNode* node = new ListNode(sum % 10);
            acc = sum / 10;

            curr->next = node;

            curr = curr->next;
        }

        return dummy.next;
    }
};
