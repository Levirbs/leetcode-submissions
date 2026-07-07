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
    void reorderList(ListNode* head) {
        if (!head) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast) {
            slow = slow->next;
            fast = fast->next;

            if (!fast) break;

            fast = fast->next;
        }

        // reverse second half

        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        slow->next = nullptr;
        
        while (curr) {
            ListNode* aux = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aux;
        }

        // merge

        ListNode* l1 = head;
        ListNode* l2 = prev;
        while (l2) {
            ListNode* aux1 = l1->next;
            ListNode* aux2 = l2->next;

            l1->next = l2;
            l2->next = aux1;

            l1 = aux1;
            l2 = aux2;
        }
        
    }
};
