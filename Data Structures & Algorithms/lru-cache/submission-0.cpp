class Node {
    public:
    int key; 
    int val;
    Node *prev;
    Node* next;

    Node(int key,int v) : key(key),val(v), prev(nullptr),next(nullptr){}
};

class LRUCache {
private: 
    int cap;
    int len = 0;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        right->prev = left;
        left->next = right;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            // update the most recent
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* node = new Node(key,value);
        cache[key] = node;
        insert(node);
        if(cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
