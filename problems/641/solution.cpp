class Node {
public:
    int val;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int _val) {
        val = _val;
    }
};

class MyCircularDeque {
private:
    int size = 0, cap = 0;
    Node *head = nullptr, *tail = nullptr;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        cap = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        
        Node* node = new Node(value);
        node->prev = head;
        
        if (!head) {
            head = node;
            tail = head;
        } else {
            head->next = node;
            head = node;
        }
        
        size++;
        
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        
        Node* node = new Node(value);
        node->next = tail;
        
        if (!tail) {
            tail = node;
            head = node;
        } else {
            tail->prev = node;
            tail = node;
        }
        
        size++;
        
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        
        Node* prev = head->prev;
        
        if (prev) {
            prev->next = nullptr;
        }

        head->prev = nullptr;
        head = prev;
        
        if (!head) {
            tail = nullptr;
        }
        
        size--;
        
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        
        Node* next = tail->next;

        if (next) {
            next->prev = nullptr;
        }

        tail->next = nullptr;
        tail = next;
        
        if (!tail) {
            head = nullptr;
        }
        
        size--;
        
       return true; 
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        
        return head->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        
        return tail->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cap == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */