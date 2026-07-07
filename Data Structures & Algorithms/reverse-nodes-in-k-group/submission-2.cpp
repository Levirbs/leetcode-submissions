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
private:
    void reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;
        while (curr) {
            ListNode* aux = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aux;
        }
        // prev is the new head;
    }

    ListNode* kthNode(ListNode* node, int k) {
        ListNode* curr = node;
        while (curr && k > 0) {
            k--;
            curr = curr->next;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        
        ListNode* groupPrev = &dummy;
        while (true) { 
            ListNode* kth = kthNode(groupPrev, k);
            
            if (!kth) break;

            ListNode* groupStart = groupPrev->next;
            ListNode* aux = kth->next;
            kth->next = nullptr;
            reverse(groupStart);

            groupPrev->next = kth;

            groupStart->next = aux;

            groupPrev = groupStart;
            
        }
        return dummy.next;
    }
};
