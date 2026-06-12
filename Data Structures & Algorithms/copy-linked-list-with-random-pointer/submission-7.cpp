/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while (curr) {
            Node* aux = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = aux;
            curr = aux;
        }

        curr = head;
        while (curr) {
            if(curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        curr = head;
        Node* res = head->next;
        while (curr) {
            Node* aux = curr->next;
            curr->next = aux->next;
            if(aux->next) aux->next = aux->next->next;
            curr = curr->next;
        }

        return res;
    }
};
