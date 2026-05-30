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
        int sum = 0;
        int acc = 0;
        
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        ListNode* res = new ListNode(0);
        ListNode* node = res;
        while (curr1 || curr2 || acc) {
            int v1 = (curr1) ? curr1->val : 0;
            int v2 = (curr2) ? curr2->val : 0;

            int aux = v1 + v2 + acc;
            node->next = new ListNode(aux % 10);

            acc = (aux / 10);

            if (curr1) curr1 = curr1->next;
            if (curr2) curr2 = curr2->next;
            node = node->next;
        }

        return res->next;
    }
};
