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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* curr = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;                
            }
            curr = curr->next;
        }

        if (l1) {
            curr->next = l1;
        } else if (l2) {
            curr->next = l2;
        }

        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1){
            vector<ListNode*> merged;
            
            int n = lists.size();
            for (int i = 0; i < n; i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < n ? lists[i + 1] : nullptr;

                merged.push_back(merge(l1, l2));
            }

            swap(merged, lists);
        }

        return lists[0];
    }
};
