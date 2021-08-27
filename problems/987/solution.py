# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
    
        print('*' * 20)
        
        q, table, ans = deque([(root, 0, 0)]), defaultdict(list), []
        
        while q:
            for _ in range(len(q)):
                node, x, y = q.popleft()
                
                print(node.val, x, y)
                
                table[x].append((abs(y), node.val))
                
                if node.left: q.append((node.left, x - 1, y - 1))
                if node.right: q.append((node.right, x + 1, y - 1))
        
        print(table)
        
        def s(v):
            return v[0]
        
        for key in sorted(table.keys()):
            ans.append(list(map(lambda v: v[1], sorted(table[key]))))
            # ans.append(table[key].sort(key=s))
        
        return ans