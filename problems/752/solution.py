class Solution:
    def openLock(self, deadends: List[str], target: str) -> int:
        q, seen, ans = deque(['0000']), set(deadends), 0
        
        deadends.sort()
        
        while q:
            qlen = len(q)
            
            for _ in range(qlen):
                lock = q.popleft()
                
                if lock == target:
                    return ans
                
                if lock in seen:
                    continue
                
                seen.add(lock)
                
                for i in range(4):
                    slot = int(lock[i])
                    inc, dec = (slot + 10 - 1) % 10, (slot + 10 + 1) % 10
                    
                    q.append(lock[:i] + str(inc) + lock[i + 1:])
                    q.append(lock[:i] + str(dec) + lock[i + 1:])
            
            ans += 1
        
        return -1