package main
type MyLinkedList struct {
    val int
    next *MyLinkedList
}


/** Initialize your data structure here. */
func Constructor() MyLinkedList {
    return MyLinkedList{
        val: -1,
        next: nil,
    }
}


/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
func (this *MyLinkedList) Get(index int) int {
    node, count := this, 0
    
    for node != nil {
        if count == index {
            return node.val
        }
        node = node.next
        count++
    }
    return -1
}


/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
func (this *MyLinkedList) AddAtHead(val int)  {
    if this.val == -1 {
        this.val = val
        return
    }

    node := &MyLinkedList{
        val: this.val,
        next: this.next,
    }
    this.val, this.next = val, node
}


/** Append a node of value val to the last element of the linked list. */
func (this *MyLinkedList) AddAtTail(val int)  {
    node := this
    for node.next != nil {
        node = node.next
    }
    node.next = &MyLinkedList{val: val}
}


/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
func (this *MyLinkedList) AddAtIndex(index int, val int)  {
    if index == 0 {
        node := &MyLinkedList{
            val: this.val,
            next: this.next,
        }
        this.val, this.next = val, node
        return
    } 
    
    count, node, prev := 0, this, this
    for node != nil {
        if count == index {
            prev.next = &MyLinkedList{
                val: val,
                next: node,
            }
            return
        }
        count++
        prev, node = node, node.next
    }
    if count == index {
        prev.next = &MyLinkedList{
            val: val,
            next: nil,
        }
    }
}


/** Delete the index-th node in the linked list, if the index is valid. */
func (this *MyLinkedList) DeleteAtIndex(index int)  {
    if index == 0 {
        if this.next != nil {
            this.val, this.next = this.next.val, this.next.next
        } else {
            this.val, this.next = -1, nil
        }
        return
    }
    
    count, node, prev := 0, this, this
    for node != nil {
         if count == index {
            prev.next = node.next
            return
        }
        count++
        prev, node = node, node.next
    }
}