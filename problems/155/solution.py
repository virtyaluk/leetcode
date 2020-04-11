class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.l = list()
        self.min = 2**32
        

    def push(self, x: int) -> None:
        self.l.append((x, self.min))
        
        if x < self.min:
            self.min = x

    def pop(self) -> None:
        self.min = self.l.pop()[1]

    def top(self) -> int:
        return self.l[-1][0]

    def getMin(self) -> int:
        return self.min
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()