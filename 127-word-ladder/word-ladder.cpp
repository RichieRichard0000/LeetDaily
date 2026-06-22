class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return 0;

        unordered_map<string,int> vis;

        queue<string> q;
        q.push(beginWord);
        vis[beginWord] = 1;

        int path = 1;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                string front = q.front();
                q.pop();

                if (front == endWord)
                    return path;

                for (int i = 0; i < front.size(); i++) {

                    char original = front[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        front[i] = ch;

                        if (!vis[front] && st.find(front) != st.end()) {
                            vis[front] = 1;
                            q.push(front);
                        }
                    }

                    front[i] = original;
                }
            }

            path++;
        }

        return 0;
    }
};