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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy;
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            
            if (!kth) {
                break;
            }

            ListNode* groupNext = kth->next;
            ListNode* groupStart = groupPrev->next;

            reverseGroup(groupStart, groupNext);

            groupPrev->next = kth;
            groupPrev = groupStart;
        }

        return dummy.next;
    }

private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    void reverseGroup(ListNode* start, ListNode* endLimit) {
        ListNode* prev = endLimit;
        ListNode* curr = start;

        while (curr != endLimit) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
    }
};