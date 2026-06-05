class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;


    Node (int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        node->prev = right->prev;
        right->prev->next = node;
        right->prev = node;
        node->next = right;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    ~LRUCache() {
        Node* curr = left;
        while (curr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }  
    
    int get(int key) {
        if (!cache.count(key)) return -1;
        
        Node* node = cache[key];

        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insert(node);

        } else {
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insert(newNode);

            if (cache.size() > cap) {
                Node* aux = left->next;
                cache.erase(aux->key);
                remove(aux);
                delete(aux);
            }
        }
    }
};
