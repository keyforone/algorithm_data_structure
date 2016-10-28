int sumOfLeftLeaves(TreeNode* root)
{
    if(NULL == root) return 0;
    if((NULL == root->left) && (NULL == root->right)) return 0;

    queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    int total = 0;
    while(!q.empty())
    {
	int level_length = q.size();
	for(int i = 0; i < level_length; i++)
	{
	    TreeNode* node = q.front();q.pop();

	    if(NULL == node) continue;

	    if((NULL == node->left) && (NULL == node->right)) 
	    {
		if((i%2) == 0) total += node->val;
		continue;
	    }

	    q.push(node->left);
	    q.push(node->right);
	}
    }

    return total;
}
