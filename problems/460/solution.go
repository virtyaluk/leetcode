package main
type Node struct {
    key, val, freq int
    prev, next *Node
}

func NewNode(key, val int) *Node {
    return &Node{
        key, val, 1, nil, nil,
    }
}

type DoublyLinkedList struct {
    head, tail *Node
}

func NewDoublyLinkedList() *DoublyLinkedList {
    head, tail := NewNode(-1, -1), NewNode(-1, -1)
    
    head.next = tail
    tail.prev = head
    
    return &DoublyLinkedList{
        head, tail,
    }
}

func (this *DoublyLinkedList) empty() bool {
    return this.tail.prev == this.head
}

func (this *DoublyLinkedList) add(node *Node) {
    this.head.next.prev = node
    node.next = this.head.next
    node.prev = this.head
    this.head.next = node
}

func (this *DoublyLinkedList) remove(node *Node) {
    prev, next := node.prev, node.next
    
    prev.next = next
    next.prev = prev
}

func (this *DoublyLinkedList) pop() *Node {
    if this.empty() {
        return nil
    }
    
    node := this.tail.prev
    
    this.remove(node)
    
    return node
}

type LFUCache struct {
    cap, size, minFreq int
    nodes map[int]*Node
    freq map[int]*DoublyLinkedList
}

func Constructor(capacity int) LFUCache {
    return LFUCache{
        capacity, 0, 0, make(map[int]*Node), make(map[int]*DoublyLinkedList),
    }
}

func (this *LFUCache) update(node *Node) {
    freq := node.freq
    
    this.freq[freq].remove(node)
    
    if freq == this.minFreq && this.freq[freq].empty() {
        this.minFreq++
    }
    
    node.freq++
    
    if _, ok := this.freq[freq + 1]; !ok {
        this.freq[freq + 1] = NewDoublyLinkedList()
    }
    
    this.freq[freq + 1].add(node)
}

func (this *LFUCache) Get(key int) int {
    if node, ok := this.nodes[key]; ok {
        this.update(node)
        
        return node.val
    }
    
    return -1
}


func (this *LFUCache) Put(key int, value int)  {
    if this.cap == 0 {
        return
    }
    
    if node, ok := this.nodes[key]; ok {
        node.val = value
        this.update(node)
        
        return
    }
    
    if this.size == this.cap {
        toRemove := this.freq[this.minFreq].pop()
        delete(this.nodes, toRemove.key)
        this.size--
    }
    
    node := NewNode(key, value)
    this.nodes[key] = node
    
    if _, ok := this.freq[1]; !ok {
        this.freq[1] = NewDoublyLinkedList()
    }
    
    this.freq[1].add(node)
    this.size++
    this.minFreq = 1
}


/**
 * Your LFUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */