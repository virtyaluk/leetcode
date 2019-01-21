class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        
        intervals.sort(key=lambda x: x[0])
        
        for i in range(1, len(intervals)):
            if intervals[i][0] <= intervals[i - 1][1]:
                intervals[i] = [min(intervals[i][0], intervals[i - 1][0]), max(intervals[i][1], intervals[i - 1][1])]
                intervals[i - 1] = None
        
        return [i for i in intervals if i]