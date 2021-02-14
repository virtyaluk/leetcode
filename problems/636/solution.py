class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        ans, st = [0] * n, []
        
        for log in logs:
            fid, func, timestamp = log.split(':')
            fid, timestamp = int(fid), int(timestamp)
            
            if func == 'start':
                st.append((fid, func, timestamp))
            else:
                spent = timestamp - st[-1][2] + 1
                st.pop()
                
                ans[fid] += spent
                
                if st:
                    ans[st[-1][0]] -= spent
        
        return ans