/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    if (!head) {
        return;
    }
    
    var slow = head, fast = head;
    
    while (fast && fast.next) {
        slow = slow.next;
        fast = fast.next.next;
    }
    
    var prev = null, cur = slow;
    
    while (cur) {
        var tmp = cur.next;
        cur.next = prev;
        prev = cur;
        cur = tmp;
    }
    
    var l1 = head, l2 = prev;
    
    while (l2.next) {
        var l1n = l1.next, l2n = l2.next;
        l1.next = l2;
        l2.next = l1n;
        l1 = l1n;
        l2 = l2n;
    }
};