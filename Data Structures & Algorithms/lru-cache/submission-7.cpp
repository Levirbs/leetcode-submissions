class ListNode {
public:
    ListNode* prev;
    ListNode* next;
    int val;
    int key;

    ListNode (int k, int val) : prev(nullptr), next(nullptr), key(k), val(val) {} 
};

class LRUCache {
private:
    unordered_map<int, ListNode*> cache;
    ListNode* left;
    ListNode* right;
    int cap;

    void remove (ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert (ListNode* node) {
        right->prev->next = node;
        node->prev = right->prev;

        right->prev = node;
        node->next = right;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        cache.clear();
        left = new ListNode(-1, -1);
        right = new ListNode(-1, -1);

        left->next = right;
        right->prev = left;
    }

    ~LRUCache () {
        ListNode* curr = left;

        while (curr) {
            ListNode* aux = curr->next;

            delete curr;
            curr = aux;
        }
    }
    
    int get(int key) {
        if (cache.count(key)) {
            ListNode* node = cache[key];

            remove(node);
            insert(node);

            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            ListNode* node = cache[key];

            remove(node);
            insert(node);

            node->val = value;

        } else {
            ListNode* node = new ListNode(key, value);

            cache[key] = node;
            insert(node);
            
            if (cache.size() > cap) {
                ListNode* aux = left->next;

                remove(aux);
                cache.erase(aux->key);
                delete(aux);
            }
        }
    }
};
