/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
var getDecimalValue = function(head) {
    let b = '';
    
    for (let n = head; n != null; b += n.val, n = n.next);
    
    return parseInt(b, 2);
};