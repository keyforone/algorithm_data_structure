int maxDepth(TreeNode* root)
{
    int depth = 0;

    if(NULL == root) return depth;

    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty())
    {
	depth++;

	int level_length = q.size();
	for(int i = 0; i < level_length; i++)
	{
	    TreeNode* node = q.front();q.pop();

	    if(NULL != node->left) q.push(node->left);
	    if(NULL != node->right) q.push(node->right);
	}
    }

    return depth;
}
