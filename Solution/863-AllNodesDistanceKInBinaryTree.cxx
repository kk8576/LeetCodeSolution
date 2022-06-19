/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL)
            return vector<int>();
        
        vector<int> ans;
        dfs(root, target, k, ans);
        
        return ans;
    }
    
    // return the distance between root and target and plus 1
    int dfs(TreeNode *root, TreeNode *target, int k, vector<int> &ans)
    {
        if (root == target)
        {
            // the distance between root and target is 0
            AddSubTree(root, 0, k, ans);
            return 1;
        }
        else
        {
            // the distance between the left node and the target
            int distL = root->left != NULL ? dfs(root->left, target, k, ans) : -1;
            // the distance between the right node and the target
            int distR = root->right != NULL ? dfs(root->right, target, k, ans) : -1;
            
            // target is in the left sub tree
            if (distL != -1)
            {
                if (distL == k)
                {
                    ans.push_back(root->val);
                }
                
                if (root->right != NULL)
                    AddSubTree(root->right, distL + 1, k, ans);
                
                return distL + 1;
            }
            // target is in the right sub tree
            else if (distR != -1)
            {
                if (distR == k)
                {
                    ans.push_back(root->val);
                }
                
                if (root->left != NULL)
                {
                    AddSubTree(root->left, distR + 1, k, ans);
                }
                
                return distR + 1;
            }
        }
        
        return -1;
    }
    
    // Search the nodes in the sub tree (*root) with dist == k
    void AddSubTree(TreeNode *root, int dist, int k, vector<int> &ans)
    {
        if (dist == k)
        {
            ans.push_back(root->val);
        }
        else if (dist < k)
        {
            if (root->left != NULL)
               AddSubTree(root->left, dist + 1, k, ans);
            
            if (root->right != NULL)
                AddSubTree(root->right, dist + 1, k, ans);
        }
    }
};
