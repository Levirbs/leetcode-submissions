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
        unordered_map<Node*, Node*> nodes;

        Node* curr = head;
        while (curr) {
            Node* aux = new Node(curr->val);
            nodes[curr] = aux;
            curr = curr->next;
        }

        curr = head;
        while (curr) {
            Node* clone = nodes[curr];
            clone->next = nodes[curr->next];
            if (curr->random) clone->random = nodes[curr->random];
            curr = curr->next;
        }

        return nodes[head];
    }
};
