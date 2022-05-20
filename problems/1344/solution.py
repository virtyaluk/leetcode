class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        hour %= 12
        ma = 360/60*minutes
        ha = 360/12*hour + 360/12*minutes/60
        a = max(ma, ha) - min(ma, ha)
        
        if a > 180.0:
            return 360.0 - a
        
        return a