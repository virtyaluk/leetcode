class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        d, ans, m = {list1[i]: i for i in range(len(list1))}, [], sys.maxsize
        
        for i in range(len(list2)):
            if list2[i] in d:
                lis = i + d[list2[i]]

                if lis == m:
                    ans.append(list2[i])
                elif lis < m:
                    ans = [list2[i]]
                    m = lis
        
        return ans
            