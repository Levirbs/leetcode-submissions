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
        Node* node = head;
        while (node) {
            Node* aux = node->next;
            node->next = new Node(node->val);
            node->next->next = aux;
            node = aux;
        }

        node = head;
        while (node) {
            if (node->random) node->next->random = node->random->next;
            node = node->next->next;
        }

        node = head;
        Node* res = head->next;
        while (node) {
            Node* aux = node->next;
            node->next = aux->next;
            if (aux->next) aux->next = aux->next->next;
            node = node->next;
        }
        return res;
    }
};
