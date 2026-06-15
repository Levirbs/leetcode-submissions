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
    void reverseGroup(ListNode* start, ListNode* limit) {
        ListNode* prev = limit;
        ListNode* curr = start;
        while (curr != limit) {
            ListNode* aux = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aux;
        }
    }

    ListNode* kthNode(ListNode* head, int k) {
        ListNode* curr = head;
        while (curr && k > 0) {
            curr = curr->next;
            k--;
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
            ListNode* groupNext = kth->next;

            reverseGroup(groupStart, groupNext);

            groupPrev->next = kth;
            groupPrev = groupStart;
        }

        return dummy.next;
    }
};
