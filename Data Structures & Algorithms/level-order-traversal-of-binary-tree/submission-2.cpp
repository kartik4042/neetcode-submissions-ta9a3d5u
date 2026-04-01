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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root) return {};

        vector<vector<int>> result;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                if(curr)
                {
                    level.push_back(curr->val);
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            if(!level.empty())
                result.push_back(level);
        }    
        return result;
    }
};
