class Solution:
    def maxSumSubmatrix(self, matrix: List[List[int]], k: int) -> int:
        def getMaxSum(arr):
            res = float('-inf')
            runningSum = 0
            sortedPreSum = [0]

            for num in arr:
                runningSum+=num
                targetSum = runningSum - k
                idx = bisect_left(sortedPreSum,targetSum)

                if idx<len(sortedPreSum):
                    res = max(res,runningSum-sortedPreSum[idx])

                if res == k:
                    break

                bisect.insort(sortedPreSum,runningSum)    

            return res       

        m,n = len(matrix),len(matrix[0])
        rowPreSum = []
        for r in range(m):
            currRow = []
            for c in range(n):
                if c!=0:
                    currRow.append(currRow[-1]+matrix[r][c])
                else:
                    currRow.append(matrix[r][c])
            rowPreSum.append(currRow)

        res = float('-inf')

        for c2 in range(n):
            for c1 in range(1+c2):
                currArr = []
                for i in range(m):
                    rowSum = rowPreSum[i][c2] - (rowPreSum[i][c1-1] if c1>0 else 0)
                    currArr.append(rowSum)   

                res = max(res,getMaxSum(currArr))
                if res == k:
                    return k

        return res
        