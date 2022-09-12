MOD = 10 ** 9 + 7

class Fancy:

    def __init__(self):
        self.nums = []
        self.add = [0]
        self.mul = [1]

    def append(self, val: int) -> None:
        self.nums.append(val)
        self.add.append(self.add[-1])
        self.mul.append(self.mul[-1])

    def addAll(self, inc: int) -> None:
        self.add[-1] += inc

    def multAll(self, m: int) -> None:
        self.add[-1] = self.add[-1] * m % MOD
        self.mul[-1] = self.mul[-1] * m % MOD

    def getIndex(self, idx: int) -> int:
        if idx >= len(self.nums):
            return -1
        
        mul = self.mul[-1] * pow(self.mul[idx], MOD - 2, MOD)
        inc = self.add[-1] - self.add[idx] * mul
        
        return (self.nums[idx] * mul + inc) % MOD


# Your Fancy object will be instantiated and called as such:
# obj = Fancy()
# obj.append(val)
# obj.addAll(inc)
# obj.multAll(m)
# param_4 = obj.getIndex(idx)