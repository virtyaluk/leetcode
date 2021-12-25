class WB(namedtuple('WBDist', ['dist', 'worker', 'taken'])):
    def __lt__(self, other):
        return self.dist < other.dist

class Solution:
    def dist(self, a, b):
        return abs(a[0] - b[0]) + abs(a[1] - b[1])
    
    def assignBikes(self, workers: List[List[int]], bikes: List[List[int]]) -> int:
        m, n, q, seen = len(workers), len(bikes), [WB(0, 0, 0)], set()
        
        heapify(q)
        
        while q:
            curDist, worker, taken = heappop(q)
            
            if (worker, taken) in seen:
                continue
                
            seen.add((worker, taken))
            
            if worker == m:
                return curDist
            
            for bike in range(n):
                if (taken & (1 << bike)) == 0:
                    heappush(q, WB(
                        curDist + self.dist(workers[worker], bikes[bike]),
                        worker + 1,
                        taken | (1 << bike)
                    ))
        
        return 0