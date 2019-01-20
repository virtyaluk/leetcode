/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    const node = new ListNode(0);
    let tracker = node;
    
    while (l1 !== null && l2 !== null) {
        let val;
        
        if (l1.val <= l2.val) {
            val = l1.val;
            l1 = l1.next;
        } else {
            val = l2.val;
            l2 = l2.next;
        }
        
        tracker.next = new ListNode(val);
        tracker = tracker.next;
    }
    
    tracker.next = l1 !== null ? l1 : l2;
    
    return node.next;
};