class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        rows = len(M)
        ans_list = []
        
        for i in range(rows):
            columns = len(M[i])
            ans_list.append([])
            for j in range(columns):
                top = i - 1
                bottom = i + 1
                left = j - 1
                right = j + 1
                
                sum_num = M[i][j]
                total_num = 1
                
                if top >= 0:
                    total_num += 1
                    sum_num += M[top][j]
                
                if bottom < rows:
                    total_num += 1
                    sum_num += M[bottom][j]
                
                if left >= 0:
                    total_num += 1
                    sum_num += M[i][left]
                
                if right < columns:
                    total_num += 1
                    sum_num += M[i][right]
                
                if top >= 0 and left >= 0:
                    total_num += 1
                    sum_num += M[top][left]
                
                if top >= 0 and right < columns:
                    total_num += 1
                    sum_num += M[top][right]
                
                if bottom < rows and left >= 0:
                    total_num += 1
                    sum_num += M[bottom][left]
                
                if bottom < rows and right < columns:
                    total_num += 1
                    sum_num += M[bottom][right]
                
                ans_list[i].append(sum_num // total_num)
        return ans_list