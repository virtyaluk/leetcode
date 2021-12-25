class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        sorted_set, counter, ranks_dict = sorted(set(arr)), 1, {}
        
        for num in sorted_set:
            ranks_dict[num] = counter
            counter += 1
        
        return [ranks_dict[num] for num in arr]