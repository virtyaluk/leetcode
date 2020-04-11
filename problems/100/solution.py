# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        pq, qq = deque([p]), deque([q])
        
        while pq:
            pqlen, qqlen = len(pq), len(qq)
            
            if pqlen != qqlen:
                return False
            
            for _ in range(pqlen):
                pnode, qnode = pq.popleft(), qq.popleft()
                pval, qval = pnode.val if pnode else -1, qnode.val if qnode else -1
                
                if pval != qval:
                    return False
        
                if pnode:
                    pq.append(pnode.left)
                    pq.append(pnode.right)
                
                if qnode:
                    qq.append(qnode.left)
                    qq.append(qnode.right)
        
        return True