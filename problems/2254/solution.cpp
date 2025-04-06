class VideoSharingPlatform {
private:
    int vid = 0;
    priority_queue<int, vector<int>, greater<>> freeVids;
    unordered_map<int, string> videos;
    unordered_map<int, array<int, 3>> counters;
public:
    VideoSharingPlatform() {
        
    }
    
    int upload(string video) {
        int nextVid;

        if (not empty(freeVids)) {
            nextVid = freeVids.top();
            freeVids.pop();
        } else {
            nextVid = vid++;
        }

        videos[nextVid] = video;

        return nextVid;
    }
    
    void remove(int videoId) {
        if (not videos.count(videoId)) {
            return;
        }

        videos.erase(videoId);
        counters.erase(videoId);
        freeVids.push(videoId);
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if (not videos.count(videoId)) {
            return "-1";
        }

        counters[videoId][0]++;

        return videos[videoId].substr(startMinute, min(endMinute, (int) size(videos[videoId])) - startMinute + 1);
    }
    
    void like(int videoId) {
        if (not videos.count(videoId)) {
            return;
        }

        counters[videoId][1]++;
    }
    
    void dislike(int videoId) {
        if (not videos.count(videoId)) {
            return;
        }

        counters[videoId][2]++;
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if (not videos.count(videoId)) {
            return {-1};
        }

        return {
            counters[videoId][1],
            counters[videoId][2]
        };
    }
    
    int getViews(int videoId) {
        if (not videos.count(videoId)) {
            return - 1;
        }

        return counters[videoId][0];
    }
};

/**
 * Your VideoSharingPlatform object will be instantiated and called as such:
 * VideoSharingPlatform* obj = new VideoSharingPlatform();
 * int param_1 = obj->upload(video);
 * obj->remove(videoId);
 * string param_3 = obj->watch(videoId,startMinute,endMinute);
 * obj->like(videoId);
 * obj->dislike(videoId);
 * vector<int> param_6 = obj->getLikesAndDislikes(videoId);
 * int param_7 = obj->getViews(videoId);
 */