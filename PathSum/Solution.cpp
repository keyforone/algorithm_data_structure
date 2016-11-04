bool hasPathSum(TreeNode* root, int sum)
{
    if(NULL == root) return false;

    if(NULL == root->left && NULL == root->right && sum == root->val) return true;

    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}
