/**
 * @param {number[][]} intervals
 * @return {number}
 */
var minMeetingRooms = function(intervals) {
    const starts = intervals.map(intervals=>intervals[0]);
    const ends = intervals.map(intervals=>intervals[1]);
    sortNumbers(starts);
    sortNumbers(ends);
    let [i, j, counter, max] = [0,0,0,0]
    const size = starts.length;
    while((i < size) && (j < size)){
      while(starts[i] < ends[j]){
        max = Math.max(++counter, max);
        i++;
      }
      while(starts[i] >= ends[j]){
        counter--;
        j++;
      }
    }
    return max;
};

const sortNumbers = nums =>{
  return nums.sort((a, b)=>a - b)
}