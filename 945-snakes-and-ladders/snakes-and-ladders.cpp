class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        reverse(board.begin(), board.end());

        for(int i = 1; i < n; i++){
            if(i % 2 == 1)
                reverse(board[i].begin(), board[i].end());
        }

        unordered_map<int,int> ump;
        int cnt = 1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ump[cnt++] = board[i][j];
            }
        }

        vector<int> reach(n*n + 1, 1e9);
        queue<int> q;

        q.push(1);
        reach[1] = 0;

        while(!q.empty()){
            int num = q.front();
            q.pop();

            for(int i = 1; i <= 6; i++){
                int next = num + i;

                if(next > n*n) break;

                if(ump[next] != -1)
                    next = ump[next];

                if(reach[next] > reach[num] + 1){
                    reach[next] = reach[num] + 1;
                    q.push(next);
                }
            }
        }

        if(reach[n*n] == 1e9) return -1;
        return reach[n*n];
    }
};