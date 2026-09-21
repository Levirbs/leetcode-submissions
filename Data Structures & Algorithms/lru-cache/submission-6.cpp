class Node {
public:
    Node* prev;
    Node* next;
    int val;
    int key;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    int cap;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert(Node* node) {
        right->prev->next = node;
        node->prev = right->prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        cache.clear();
        left = new Node(-1, -1);
        right = new Node(-1, -1);

        left->next = right;
        right->prev = left;
    }

    ~LRUCache() {
        Node* curr = left;
        while (curr) {
            Node* aux = curr->next;
            delete curr;
            curr = aux;
        }
    }
    
    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;

        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            node->val = value;

        } else {
            Node* novo = new Node(key, value);
            insert(novo);
            cache[key] = novo;

            if (cache.size() > cap) {
                Node* aux = left->next;
                remove(aux);
                cache.erase(aux->key);
                delete aux;
            }
        }
    }
};
