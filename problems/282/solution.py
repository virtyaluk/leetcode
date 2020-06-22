class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        if not num:
            return []
        
        ans = []
        
        def helper(idx, prevOp, curOp, val, ops):
            if idx == len(num):
                if val == target and curOp == 0:
                    ans.append(''.join(ops[1:]))
                
                return

            curOp = curOp * 10 + int(num[idx])
            curOpStr = str(curOp)

            if curOp > 0:
                helper(idx + 1, prevOp, curOp, val, ops)

            # +
            ops.append('+')
            ops.append(curOpStr)
            helper(idx + 1, curOp, 0, val + curOp, ops)
            ops.pop()
            ops.pop()
            
            if ops:
                # -
                ops.append('-')
                ops.append(curOpStr)
                helper(idx + 1, -curOp, 0, val - curOp, ops)
                ops.pop()
                ops.pop()
                
                # *
                ops.append('*')
                ops.append(curOpStr)
                helper(idx + 1, curOp * prevOp, 0, val - prevOp + (curOp * prevOp), ops)
                ops.pop()
                ops.pop()
        
        helper(0, 0, 0, 0, [])
        
        return ans