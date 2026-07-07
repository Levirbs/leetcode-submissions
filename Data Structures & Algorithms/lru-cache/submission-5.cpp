class Node {
public:
    Node* prev;
    Node* next;
    int key;
    int val;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    int cap;
    
    void insert(Node* node) {
        node->prev = right->prev;
        right->prev->next = node;
        node->next = right;
        right->prev = node;
    }

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);

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
        auto it = cache.find(key);

        if (it == cache.end()) return -1;

        remove(it->second);
        insert(it->second);

        return it->second->val;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) {
            remove(it->second);
            insert(it->second);

            it->second->val = value;
        } else {
            Node* newNode = new Node(key, value);
            insert(newNode);
            cache[key] = newNode;

            if (cache.size() > cap) {
                Node* aux = left->next;
                cache.erase(aux->key);
                remove(aux);
                delete aux;
            }
        }
    }
};
