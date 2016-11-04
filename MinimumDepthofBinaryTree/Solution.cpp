int minDepth(TreeNode* root)
{
    int depth = 0;

    if(NULL == root) return depth;

    queue<TreeNode*> q; q.push(root);

    while(!q.empty())
    {
	depth++;
	int level_nodes_counts = q.size();
	for(int i = 0; i < level_nodes_counts; i++)
	{
	    TreeNode* n = q.front(); q.pop();

	    if(NULL == n->left && NULL == n->right) return depth;

	    if(NULL != n->left) q.push(n->left);
	    if(NULL != n->right) q.push(n->right);
	}
    }

    return depth;
}
