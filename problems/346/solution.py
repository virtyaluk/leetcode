class MovingAverage:

    def __init__(self, size: int):
        """
        Initialize your data structure here.
        """
        self.size = size
        self.buf = []
        

    def next(self, val: int) -> float:
        if len(self.buf) >= self.size:
            self.buf.pop(0)
        
        self.buf.append(val)
        
        return sum(self.buf) / len(self.buf)


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)