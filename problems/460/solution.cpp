class Node {
public:
    int key, val, freq = 1;
    Node *prev = nullptr, *next = nullptr;
    
    Node(int k = -1, int v = -1): key(k), val(v) {}
    Node(int k, int v, Node *p, Node *n): key(k), val(v), next(n), prev(p) {}
};

class DoublyLinkedList {
private:
    Node *head = nullptr, *tail = nullptr;
    
public:
    DoublyLinkedList() {
        head = new Node();
        tail = new Node();
        
        head->next = tail;
        tail->prev = head;
    }
    
    void remove(Node *node) {
        Node *prev = node->prev, *next = node->next;
        next->prev = prev;
        prev->next = next;
    }
    
    void add(Node *node) {
        head->next->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
    }
    
    Node* pop() {
        if (empty()) {
            return nullptr;
        }
        
        Node *node = tail->prev;
        
        remove(node);
        
        return node;
    }
    
    bool empty() {
        return tail->prev == head;
    }
};

class LFUCache {
private:
    int cap, minFreq = 0, size = 0;
    Node *head = nullptr, *tail = nullptr;
    unordered_map<int, Node*> nodes;
    unordered_map<int, DoublyLinkedList> freq;
    
    void update(Node *node) {
        int nodeFreq = node->freq;
        
        freq[nodeFreq].remove(node);
        
        if (minFreq == nodeFreq and freq[nodeFreq].empty()) {
            minFreq++;
        }
        
        node->freq++;
        freq[nodeFreq + 1].add(node);
    }
    
public:
    LFUCache(int capacity): cap(capacity) {
        head = new Node();
        tail = new Node();
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (not nodes.count(key)) {
            return -1;
        }
        
        update(nodes[key]);
        
        return nodes[key]->val;
    }
    
    void put(int key, int value) {
        if (not cap) {
            return;
        }
        
        if (not nodes.count(key)) {
            if (size == cap) {
                Node *toRemove = freq[minFreq].pop();
                nodes.erase(toRemove->key);
                size--;
            }
            
            Node *node = new Node(key, value);

            nodes[key] = node;
            freq[1].add(node);
            size++;
            minFreq = 1;
            
            return;
        }
        
        update(nodes[key]);
        nodes[key]->val = value;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */