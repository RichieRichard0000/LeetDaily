class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                if (!curr->left && !curr->right)
                    return depth;

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            depth++;
        }

        return depth;
    }
};