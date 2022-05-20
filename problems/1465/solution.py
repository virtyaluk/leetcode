class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        M = 1000000007
        # horizontalCuts.append(h)
        # verticalCuts.append(w)
        horizontalCuts = [0] + horizontalCuts + [h]
        verticalCuts = [0] + verticalCuts + [w]
        
        horizontalCuts = sorted(horizontalCuts)
        verticalCuts = sorted(verticalCuts)
        
        hc, hi, vc, vi = [], 0, [], 0
        
        while hi < len(horizontalCuts):
            hc.append(horizontalCuts[hi] - horizontalCuts[hi - 1])
            hi += 1
        
        while vi < len(verticalCuts):
            vc.append(verticalCuts[vi] - verticalCuts[vi - 1])
            vi += 1
        
        hm, vm = max(hc), max(vc)
        ans = hm * vm
        
        return ans % M