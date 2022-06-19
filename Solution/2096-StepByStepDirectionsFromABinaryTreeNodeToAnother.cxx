#include <string>
#include <stack>
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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        //string pathL, pathR;
        
        stack<char> pathR;
        queue<char> pathL;
        
        dfs(root, startValue, destValue, pathL, pathR);
        
        string ans;
        while(!pathL.empty())
        {
            ans += pathL.front();
            pathL.pop();
        }
        
        while (!pathR.empty())
        {
            ans += pathR.top();
            pathR.pop();
        }
        
        return ans;
    }
    
    int dfs(TreeNode *root, int startValue, int destValue, queue<char> &pathL, stack<char> &pathR)
    {
        bool isStart = false;
        if (root->val == startValue)
        {
            isStart = true;
        }
        
        bool isDest = false;
        if (root->val == destValue)
        {
            isDest = true;
        }   
        
        int L = root->left != NULL ? dfs(root->left, startValue, destValue, pathL, pathR) : -1;
        int R = root->right != NULL ? dfs(root->right, startValue, destValue, pathL, pathR) : -1;
        
        if (L == -1 && R == -1 && !isStart && !isDest)
            return -1;
        
        if (R == 1)
        {
            pathR.push('R');
        }
        else if (R == 0)
        {
            pathL.push('U');
        }
        
        if (L == 1)
        {
            pathR.push('L');// = "L" + pathR;
        }
        else if (L == 0)
        {
            pathL.push('U');// = pathL + "U";
        }
        
        // found both start and dest
        if ((isStart || isDest) && (L != -1 || R != -1))
            return -1;
        else if (L != -1 && R != -1)
            return -1;
        else if (isStart)
            return 0;
        else if (isDest)
            return 1;
        else if (L != -1)
            return L;
        else if (R != -1)
            return R;
        
        return -1;
    }
};
