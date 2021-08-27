class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        people = [0] * N
        
        for a, b in trust:
            people[a - 1] -= 1
            people[b - 1] += 1
            
        for i in range(len(people)):
            if people[i] == N - 1:
                return i + 1
        
        return -1