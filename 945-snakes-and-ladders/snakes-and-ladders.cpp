class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        reverse(board.begin(), board.end());

        for(int i = 1; i < n; i += 2)
            reverse(board[i].begin(), board[i].end());

        unordered_map<int,int> mp;
        int cnt = 1;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mp[cnt++] = board[i][j];

        queue<int> q;
        vector<bool> vis(n * n + 1, false);

        q.push(1);
        vis[1] = true;

        int moves = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                int curr = q.front();
                q.pop();

                if(curr == n * n)
                    return moves;

                for(int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;

                    if(next > n * n)
                        break;

                    if(mp[next] != -1)
                        next = mp[next];

                    if(!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};