class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
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
        right->prev->next = node;
        node->prev = right->prev;
        node->next = right;
        right->prev = node;
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

    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;

        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.count(key)){
            
            Node* node = cache[key];
            remove(node);
            insert(node);
            node->val = value;

        } else {
            Node* newNode = new Node(key, value);
            insert(newNode);
            cache[key] = newNode;

            if (cache.size() > cap) {
                Node* aux = left->next;
                remove(aux);
                cache.erase(aux->key);
                delete(aux);
            }
        }
        
    }
};
