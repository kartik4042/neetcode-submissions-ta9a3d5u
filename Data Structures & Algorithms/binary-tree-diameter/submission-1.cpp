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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int res = 0;
        //int res = root->val;

        dfs(root, res);
        return res;    
    }

    int dfs(TreeNode* root, int& res)
    {
        if(!root)
            return 0;

        int left = dfs(root->left, res);
        //int maxLeft = max(0, dfs(root->left, res));
        int right = dfs(root->right, res);
        //int maxRight = max(0, dfs(root->right, res));
        res = max(res, left + right);
        //res = max(res, root->val + maxLeft + maxRight);

        return 1 + max(left, right);
        //return root->val + max(leftMax, rightMax);
    }
};
