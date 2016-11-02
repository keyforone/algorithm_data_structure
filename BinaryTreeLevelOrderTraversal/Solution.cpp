vector<vector<int>> levelOrder(TreeNode* root) 
{
    vector<vector<int> > result;

    if(NULL == root) return result;

    queue<TreeNode*> q; q.push(root);

    while(!q.empty())
    {
	vector<int> level;
	int level_width = q.size();
	for(int i = 0; i < level_width; i++)
	{
	    TreeNode* n = q.front(); q.pop();
	    level.push_back(n->val);

	    if(NULL != n->left) q.push(n->left);
	    if(NULL != n->right) q.push(n->right);
	}
	result.push_back(level);
    }

    return result;
}
