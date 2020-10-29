class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        ans = []
        
        for person in sorted(people, key=lambda x: (-x[0], x[1])):
            ans.insert(person[1], person)
        
        return ans