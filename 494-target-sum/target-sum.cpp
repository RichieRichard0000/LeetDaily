class Solution {
public:
    int f(int i, int sum, int target, vector<int>& nums,
          vector<vector<int>>& dp, int offset) {

        if (i == nums.size())
            return sum == target;

        if (dp[i][sum + offset] != -1)
            return dp[i][sum + offset];

        int add = f(i + 1, sum + nums[i], target, nums, dp, offset);
        int sub = f(i + 1, sum - nums[i], target, nums, dp, offset);

        return dp[i][sum + offset] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = 0;
        for (int x : nums)
            total += x;

        if (abs(target) > total)
            return 0;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(2 * total + 1, -1));

        return f(0, 0, target, nums, dp, total);
    }
};