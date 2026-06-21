/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root)return true;
       queue<TreeNode*>q; 
       q.push(root);
       while(q.front()!=nullptr){
        TreeNode* front=q.front();
        q.pop();
        q.push(front->left);
        q.push(front->right);
       }
       if(q.front()==nullptr){
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front!=nullptr)return false;

        }
        return true;
       }
       return true;
    }
};