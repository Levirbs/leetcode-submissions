class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node (int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    Node* left;
    Node* right;
    int cap;
    unordered_map<int, Node*> cache;

    void insert (Node* node) {
        right->prev->next = node;
        node->prev = right->prev;
        node->next = right;
        right->prev = node;
    }

    void remove (Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(-1, 0);
        right = new Node(-1, 0);
        left->next = right;
        right->prev = left;
        cache.clear();
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
        if (!cache.count(key)) return -1;

        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insert(node);

        } else {
            Node* node = new Node(key, value);
            
            cache[key] = node;
            insert(node);

            if (cache.size() > cap) {
                Node* aux = left->next;
                remove(aux);
                cache.erase(aux->key);
                delete(aux);
            }
        }
    }
};
