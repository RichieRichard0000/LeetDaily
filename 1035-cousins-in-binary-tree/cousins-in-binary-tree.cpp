class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        while (!q.empty()) {
            int sz = q.size();
            TreeNode *px = nullptr, *py = nullptr;

            while (sz--) {
                auto [node, parent] = q.front();
                q.pop();

                if (node->val == x) px = parent;
                if (node->val == y) py = parent;

                if (node->left)
                    q.push({node->left, node});
                if (node->right)
                    q.push({node->right, node});
            }

            if (px && py) return px != py; // same depth, different parents
            if (px || py) return false;    // only one found at this level
        }

        return false;
    }
};