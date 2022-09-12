import abc 
from abc import ABC, abstractmethod 
"""
This is the interface for the expression tree Node.
You should not remove it, and you can define some classes to implement it.
"""

class Node(ABC):
    @abstractmethod
    # define your fields here
    def evaluate(self) -> int:
        pass

class TreeNode:
    def __init__(self, val=0, op=None, left=None, right=None):
        self.val = val
        self.op = op
        self.left = left
        self.right = right
    
    def evaluate(self):
        if not self.op:
            return self.val
        
        lv, rv = self.left.evaluate(), self.right.evaluate()
        
        if self.op == '+':
            return lv + rv
        elif self.op == '-':
            return lv - rv
        elif self.op == '*':
            return lv * rv
        else:
            return lv // rv


"""    
This is the TreeBuilder class.
You can treat it as the driver code that takes the postinfix input
and returns the expression tree represnting it as a Node.
"""

class TreeBuilder(object):
    def buildTree(self, postfix: List[str]) -> 'Node':
        nodes = []
        
        for token in postfix:
            if not token.isnumeric():
                right, left = nodes.pop(), nodes.pop()
                
                nodes.append(TreeNode(0, token, left, right))
            else:
                nodes.append(TreeNode(int(token)))
        
        return nodes[-1]
        
        
		
"""
Your TreeBuilder object will be instantiated and called as such:
obj = TreeBuilder();
expTree = obj.buildTree(postfix);
ans = expTree.evaluate();
"""
        