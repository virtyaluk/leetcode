class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        max_time = -1
        
        for a, b, c, d in itertools.permutations(A):
            h, m = a * 10 + b, c * 10 + d
            
            if h < 24 and m < 60:
                max_time = max(max_time, h * 60 + m)
        
        if max_time == -1:
            return ''
        else:
            return '%02d:%02d' % (max_time // 60, max_time % 60)