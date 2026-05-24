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
        // split in half -> reverse second half -> merge
        // split in half
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
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

        ListNode* second = prev;
        ListNode* first = head;

        // merge
        while (second) {
            ListNode* aux1 = first->next;
            ListNode* aux2 = second->next;

            first->next = second;
            second->next = aux1;

            first = aux1;
            second = aux2;
        }
    }
};
