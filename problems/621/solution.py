class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        abc = [0] * 26
        
        for ch in tasks:
            abc[ord(ch) - ord('A')] += 1
        
        abc.sort()
        
        m = abc[25] - 1
        freq = m * n
        
        for i in range(24, -1, -1):
            if abc[i] == 0:
                break
            
            freq -= min(m, abc[i])
        
        return len(tasks) + max(0, freq)