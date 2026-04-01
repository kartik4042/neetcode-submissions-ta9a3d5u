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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int level = 0;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node)
                {
                    level = node->val;
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(level != 0)
                result.push_back(level);
        }    
        return result;
    }
};
