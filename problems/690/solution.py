"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        graph, ans, q = defaultdict(list), 0, deque([id])
        
        for emp in employees:
            graph[emp.id] = emp
            
        while q:
            for _ in range(len(q)):
                emp = graph[q.popleft()]
                ans += emp.importance
                
                q.extend(emp.subordinates)
        
        return ans