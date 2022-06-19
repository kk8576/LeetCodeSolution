#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL)
            return vector<int>();
        
        queue<pair<TreeNode *, int>> q;
        vector<int> ans;
        bfs(root, ans, 0, q);
        
        return ans;
    }
    
    // breath with search
    void bfs(TreeNode *root, vector<int> &ans, int level, 
             queue<pair<TreeNode*, int>> &q)
    {
        if (ans.size() == level)
        {
            ans.push_back(root->val);
        }
        else if (ans.size() > level)
        {
            ans[level] = root->val;
        }
        
        if (root->left != NULL)
            q.push(pair<TreeNode*, int>(root->left, level + 1));
        
        if (root->right != NULL)
            q.push(pair<TreeNode*, int>(root->right, level + 1));
        
        if (!q.empty())
        {
            auto p = q.front();
            q.pop();
            bfs(p.first, ans, p.second, q);
        }
    }
};
