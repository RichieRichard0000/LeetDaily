class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = true;

                int nodes = 0;
                int degreeSum = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    nodes++;
                    degreeSum += adj[node].size();

                    for (int nei : adj[node]) {
                        if (!vis[nei]) {
                            vis[nei] = true;
                            q.push(nei);
                        }
                    }
                }

                int edgeCount = degreeSum / 2;

                if (edgeCount == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};