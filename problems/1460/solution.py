class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        dif = self.difference(target, arr)
        
        return False if dif else True
        
    def difference(self, list1, list2):
        new_list = []
        for i in list1:
            if i not in list2:
                new_list.append(i)

        for j in list2:
            if j not in list1:
                new_list.append(j)
        return new_list