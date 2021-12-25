class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        groups = dict()
        ans = list()
        
        for i, size in enumerate(groupSizes):
            if size in groups:
                if len(groups[size]) != size:
                    groups[size].append(i)
                else:
                    ans.append(groups[size])
                    groups[size] = [i]
            else:
                groups[size] = [i]
        
        for k in groups.keys():
            ans.append(groups[k])
        
        return ans