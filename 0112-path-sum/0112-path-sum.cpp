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
class Solution{
private:
    bool dfs(TreeNode* root, int sum, int target) {
        if (!root)
            return false;
        sum += root->val;
        if (sum == target && root->left == nullptr && root->right == nullptr)
            return true;
        return dfs(root->right, sum, target) || dfs(root->left, sum, target);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root)
            return false;
        return dfs(root, 0, targetSum);
    }
};