class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return [n for n in set(nums1) if n in set(nums2)]