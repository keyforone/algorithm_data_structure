int pathSum(TreeNode* root, int sum)
{
    if(NULL == root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int count = 0;
    while(!q.empty())
    {
	int level_length = q.size();
	for(int i = 0; i < level_length; i++)
	{
	    TreeNode* node = q.front();q.pop();

	    count += getPathSum(node, sum);

	    if(NULL != node->left) q.push(node->left);
	    if(NULL != node->right) q.push(node->right);
	}
    }

    return count;
}

int getPathSum(TreeNode* root, int sum)
{
    if(NULL == root) return 0;

    if(root->val == sum) { return 1 + getPathSum(root->left, sum-root->val) + getPathSum(root->right, sum-root->val); }

    return getPathSum(root->left, sum-root->val) + getPathSum(root->right, sum-root->val);
}
