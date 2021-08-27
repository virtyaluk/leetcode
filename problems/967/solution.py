class Solution:
    def getNum(self, ar):
        num = 0
        
        for n in ar:
            num *= 10
            num += n
        
        return num
    
    def numsSameConsecDiff(self, N: int, K: int) -> List[int]:
        if N == 1:
            return [i for i in range(10)]
        
        ans, q, i = set(), deque([[i] for i in range(1, 10)]), 1
        
        while q:
            cur = q.pop()
            
            if len(cur) > N:
                continue
            
            if len(cur) == N:
                ans.add(self.getNum(cur))
                continue
            
            j = cur[-1]
            
            if j + K <= 9: q.append(cur + [j + K])
            if j - K >= 0: q.append(cur + [j - K])
            # while j + K <= 9:
            #     q.append(cur + [j + K])
            #     j += K
            
            # j = cur[-1]
            # while j - K >= 0:
            #     q.append(cur + [j - K])
            #     j -= K
        
        return list(ans)