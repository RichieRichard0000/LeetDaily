class Solution {
public:
    vector<vector<int>> dp;

    int f(int curr, int n, int prev) {

        if (curr == n)
            return 0;

        if (curr > n)
            return 1e9;

        if (dp[curr][prev] != -1)
            return dp[curr][prev];

        int paste = 1e9;
        if (prev > 0 && curr + prev <= n) {
            paste = 1 + f(curr + prev, n, prev);
        }

        int copy = 1e9;
        if (curr != prev) {          // don't copy if clipboard already has curr
            copy = 1 + f(curr, n, curr);
        }

        return dp[curr][prev] = min(copy, paste);
    }

    int minSteps(int n) {

        if (n == 1)
            return 0;

        dp.assign(n + 1, vector<int>(n + 1, -1));

        return f(1, n, 0);
    }
};