class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        g = defaultdict(list)

        for i in allowed:
            g[(i[0], i[1])].append(i[2])

        @lru_cache(None)
        def function(bot, i, nxt):
            if len(bot) == 1:
                return True 

            if len(nxt) == len(bot) - 1:
                return function(nxt,0,"")

            for c in g[(bot[i], bot[i + 1])]:
                if function(bot, i + 1, nxt + c):
                    return True 

            return False 

        return function(bottom, 0, "")