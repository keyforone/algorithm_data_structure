vector<vector<int>> levelOrderBottom(TreeNode* root) 
{
    vector<vector<int> > result;
    if(NULL == root) return result;

    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
	vector<int> v;
	int level_length = q.size();

	for(int i = 0; i < level_length; i++)
	{
	    TreeNode* node = q.front();q.pop();
	    v.push_back(node->val);

	    if(NULL != node->left) q.push(node->left);
	    if(NULL != node->right) q.push(node->right);
	}

	result.insert(result.begin(), v);
    }

    return result;
}
