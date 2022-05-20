from collections import deque
from itertools import combinations

class Solution:
    def minNumberOfSemesters(self, n: int, relations: List[List[int]], k: int) -> int:
        pre, occupy = [0] * n, [20] * (1 << (n))
        
        for dep in relations:
            pre[dep[1] - 1] += 1 << (dep[0] - 1)
            
        q = deque([[0, 0]])
        
        while q:
            [num, step] = q.popleft()
            next_list = []
            
            for i in range(n):
                if pre[i] & num != pre[i]:
                    continue;

                if (1 << i) & num:
                    continue;
                
                next_list.append(i)
            
            if len(next_list) <= k:
                for ele in next_list:
                    num += 1 << ele
                
                if num + 1 == 1 << n:
                    return step + 1
                
                if occupy[num] > step + 1:
                    q.append([num, step + 1])
                    occupy[num] = step + 1
            else:
                the_list = combinations(next_list, k)
                
                for seq in the_list:
                    temp = num
                    
                    for ele in list(seq):
                        temp += 1 << ele
                    
                    if occupy[temp] > step + 1:
                        q.append([temp, step + 1])
                        occupy[temp] = step + 1