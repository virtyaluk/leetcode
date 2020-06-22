class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        h = [(freq, val) for val, freq in Counter(nums).items()]
        heapq.heapify(h)
        
        return [val for _, val in heapq.nlargest(k, h)]