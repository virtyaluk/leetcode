/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        var dummy = new ListNode(0);
        var carry = 0;
        var p = l1;
        var q = l2;
        var curr = dummy;
        
        while (p != null || q != null) {
            var x = (p != null) ? p.val : 0;
            var y = (q != null) ? q.val : 0;
            var sum = x + y + carry;
            
            carry = sum / 10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
            
            if (p != null) {
                p = p.next;
            }
            
            if (q != null) {
                q = q.next;
            }
        }
        
        if (carry > 0) {
            curr.next = new ListNode(carry);
        }
        
        return dummy.next;
    }
}