class Node {
public:
    int value, key;
    Node *next = nullptr, *prev = nullptr;
    
    Node(int val, int k = -1): value{val}, key{k} {}
};

class LRUCache {
private:
    Node *head = new Node(-1), *tail = new Node(-1);
    unordered_map<int, Node*> um;
    int cap;
    
    void remove(Node *node) {
        Node *prev = node->prev, *next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    void append(Node *node) {
        Node *next = head->next;
        
        next->prev = node;
        node->next = next;
        head->next = node;
        node->prev = head;
    }
    
    void removeLast() {
        Node *toRemove = tail->prev, *prev = toRemove->prev;
        prev->next = tail;
        tail->prev = prev;
        toRemove->next = nullptr;
        toRemove->prev = nullptr;
        um.erase(toRemove->key);
    }
    
    void promoteToHead(Node *node) {
        remove(node);
        append(node);
    }
public:
    LRUCache(int capacity): cap{capacity} {
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (not um.count(key)) {
            return -1;
        }
        
        Node *node = um[key];
        
        promoteToHead(node);
        
        return node->value;
    }
    
    void put(int key, int value) {
        if (um.count(key)) {
            um[key]->value = value;
            
            promoteToHead(um[key]);
            
            return;
        }
        
        if (size(um) == cap) {
            removeLast();
        }
        
        Node *node = new Node(value, key);
        um[key] = node;
        append(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */