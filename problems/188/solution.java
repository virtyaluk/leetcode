class Solution {
    Integer[][][] dp;

    public int maxProfit(int k, int[] prices) {
        if (k >= prices.length / 2) { // if k >= prices.length / 2 which means we can have more txn to perfom than the number of days so in this case problem is same as 122. Best Time to Buy and Sell Stock II
            int maxProfit = 0;
            for (int i = 1; i < prices.length; i++)
                if (prices[i] > prices[i - 1])
                    maxProfit += prices[i] - prices[i - 1];
            return maxProfit;
        }
        dp = new Integer[prices.length + 1][2][k + 1];
        return helper(prices, 0, 1, 0, k);
    }

    private int helper(int[] prices, int ind, int buyTime, int c, int k) {
        if (ind >= prices.length || c >= k)
            return 0;
        if (dp[ind][buyTime][c] != null)
            return dp[ind][buyTime][c];
        if (buyTime == 1)
            return dp[ind][buyTime][c] = Math.max(-prices[ind] + helper(prices, ind + 1, 0, c, k), helper(prices, ind + 1, buyTime, c, k));
        return dp[ind][buyTime][c] = Math.max(prices[ind] + helper(prices, ind + 1, 1, c + 1, k), helper(prices, ind + 1, buyTime, c, k));
    }
}