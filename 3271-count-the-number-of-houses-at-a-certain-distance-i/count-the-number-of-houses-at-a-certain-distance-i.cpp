class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>> adj(n + 1);

        for (int i = 1; i < n; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }

        if (x != y) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> ans(n);

        for (int src = 1; src <= n; src++) {

            vector<int> dist(n + 1, -1);
            queue<int> q;

            q.push(src);
            dist[src] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nbr : adj[node]) {
                    if (dist[nbr] == -1) {
                        dist[nbr] = dist[node] + 1;
                        q.push(nbr);
                    }
                }
            }

            for (int dest = src + 1; dest <= n; dest++) {
                ans[dist[dest] - 1] += 2; 
            }
        }

        return ans;
    }
};