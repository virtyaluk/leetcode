class MyHashSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.bucket = [None] * 1000000
        

    def add(self, key: int) -> None:
        self.bucket[key] = key
        
    def remove(self, key: int) -> None:
        self.bucket[key] = None

    def contains(self, key: int) -> bool:
        """
        Returns true if this set contains the specified element
        """
        return self.bucket[key] != None
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)