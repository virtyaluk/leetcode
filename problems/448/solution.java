class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        for (int i = 0; i < nums.length; i++) {
            int idx = Math.abs(nums[i]);
            
            nums[idx - 1] = Math.abs(nums[idx - 1]) * -1;
        }
        
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                ans.add(i + 1);
            }
        }
        
        return ans;
    }
}