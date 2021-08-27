class MyLinkedList {
private:
    deque<int> dq;
public:
    MyLinkedList() {}
    
    int get(int index) {
        if (index < 0 or index >= size(dq)) {
            return -1;
        }
        
        return dq.at(index);
    }
    
    void addAtHead(int val) {
        dq.push_front(val);
    }
    
    void addAtTail(int val) {
        dq.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if (index >= 0 and index <= size(dq)) {
            dq.insert(begin(dq) + index, val);
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= 0 and index < size(dq)) {
            dq.erase(begin(dq) + index);
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */