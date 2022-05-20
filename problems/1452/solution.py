class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        ans = []
        
        for i in range(len(favoriteCompanies)):
            s1, is_sub = set(favoriteCompanies[i]), False
            
            for j in range(len(favoriteCompanies)):
                if i == j:
                    continue
                
                if s1.issubset(set(favoriteCompanies[j])):
                    is_sub = True
            
            if not is_sub:
                ans.append(i)
        
        return ans