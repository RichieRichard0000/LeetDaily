class Solution {
public:

    pair<int,int> help(string s)
    {
        int z=0,o=0;

        for(char c:s)
        {
            if(c=='0') z++;
            else o++;
        }

        return {z,o};
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        int sz=strs.size();

        vector<vector<vector<int>>> dp(
            sz+1,
            vector<vector<int>>(m+1, vector<int>(n+1,0))
        );

        for(int ind=sz-1;ind>=0;ind--)
        {
            auto cnt=help(strs[ind]);

            int z=cnt.first;
            int o=cnt.second;

            for(int zero=0;zero<=m;zero++)
            {
                for(int one=0;one<=n;one++)
                {
                    int skip=dp[ind+1][zero][one];

                    int take=0;

                    if(zero>=z && one>=o)
                    {
                        take=1+dp[ind+1][zero-z][one-o];
                    }

                    dp[ind][zero][one]=max(take,skip);
                }
            }
        }

        return dp[0][m][n];
    }
};