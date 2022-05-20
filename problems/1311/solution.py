class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        q, videos, visited = deque([id]), defaultdict(int), {id}
        
        while q:
            if not level:
                break
            
            for _ in range(len(q)):
                fid = q.popleft()
                
                for aid in friends[fid]:
                    if aid in visited:
                        continue
                    
                    visited.add(aid)
                    q.append(aid)
            
            level -= 1
        
        while q:
            fid = q.popleft()
            
            for video in watchedVideos[fid]:
                videos[video] += 1

        videos = sorted(videos.items(), key=lambda x: (x[1], x[0]))
        
        return [i[0] for i in videos]