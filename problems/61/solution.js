/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
function rotateRight(head, k) {
    let before = { next: head };
    let prev = before;
    let len = 0;
    
    // 1. get total length of list
    for (; prev.next; prev = prev.next, len++);
    
    // 2. connect original tail to head
    // eg. 1 -> 2 -> 3 -> null
    // =>  [1] -> 2 -> 3 -> [1]
    prev.next = head;
    
    // find new head
    for (prev = before, k = len - k % len; k--; prev = prev.next);
    
    // cut the loop
    let newHead = prev.next;
    prev.next = null;
    return newHead;
}