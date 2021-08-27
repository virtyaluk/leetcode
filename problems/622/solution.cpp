class Node {
public:
    int val;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int _val) {
        val = _val;
    }
};

class MyCircularQueue {
private:
    int cap = 0, size = 0;
    Node *head = nullptr, *tail = nullptr;
public:
    MyCircularQueue(int k) {
        cap = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        
        Node* newHead = new Node(value);
        
        if (isEmpty()) {
            head = newHead;
            tail = newHead;
        } else {
            tail->next = newHead;
            tail = newHead;
        }
        
        size++;
        
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        
        head = head->next;
        
        size--;
        
        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            return -1;
        }
        
        return head->val;
    }
    
    int Rear() {
        if (isEmpty()) {
            return -1;
        }
        
        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */