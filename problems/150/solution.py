from operator import truediv, sub, mul, add

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        ops = {'+': add, '-': sub, '*': mul, '/': truediv}
        
        for token in tokens:
            if token in ops:
                b, a = stack.pop(), stack.pop()
                
                stack.append(int(ops[token](a, b)))
            else:
                stack.append(int(token))
        
        return stack[-1]