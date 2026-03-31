class Node{
    
    public:
    int key;
    int val;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node(int key, int val) {
        this->key = key;
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    Node* head = new Node(-1,0);
    Node* tail = new Node(-1,0);
    
    unordered_map<int,Node*> umap;
    int cap;
    int k;
    LRUCache(int capacity) {
        cap = capacity;
        k = 0;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(umap.find(key) == umap.end())
            return -1;
        Node* node = umap[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        return node->val;
    }

    void put(int key, int value) {
        if(umap.find(key) == umap.end()) {
            Node* newNode = new Node(key,value);
            k++;
            newNode->next = head->next;
            newNode->prev = head;
            head->next->prev = newNode;
            head->next = newNode;
            if(k > cap) {
                Node* prev = tail->prev;
                tail->prev->prev->next = tail;
                tail->prev = tail->prev->prev;
                umap.erase(prev->key);
                k--;
            }
            umap[key] = newNode;
        } else {
            Node* node = umap[key];
            node->val = value;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
        }
    }
};
