class RandomizedCollection:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.l = []
        self.m = defaultdict(set)

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        ans = val not in self.m
        self.l.append(val)
        self.m[val].add(len(self.l) - 1)
        
        return ans

    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if val not in self.m:
            return False

        valIdx = self.m[val].pop()
        
        if not self.m[val]:
            self.m.pop(val)
        
        if valIdx != len(self.l) - 1:
            self.m[self.l[-1]].remove(len(self.l) - 1)
            self.m[self.l[-1]].add(valIdx)
        
        self.l[valIdx], self.l[-1] = self.l[-1], self.l[valIdx]
        self.l.pop()
        
        return True

    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return random.choice(self.l)


# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()