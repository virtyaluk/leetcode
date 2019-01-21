class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function canJump($nums) {
        $li = count($nums) - 1;
        
        for ($i = count($nums) - 2; $i >= 0; $i--) {
            if ($i + $nums[$i] >= $li) {
                $li = $i;
            }
        }
        
        return $li == 0;
    }
}