class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        max_len = max(len(version1.split('.')), len(version2.split('.')))
        v1, v2 = [0] * max_len, [0] * max_len
        
        for i, v in enumerate(version1.split('.')):
            v1[i] = int(v)
        
        for i, v in enumerate(version2.split('.')):
            v2[i] = int(v)
        
        for i in range(len(v1)):
            if v1[i] > v2[i]:
                return 1
            elif v1[i] < v2[i]:
                return -1
            else:
                continue
        
        return 0