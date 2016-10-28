TreeNode* invertTree(TreeNode* root)
{
    if(NULL == root) return NULL;

    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty())
    {
	int level_length = q.size();
	for(int i = 0; i < level_length; i++)
	{
	    TreeNode* node = q.front();q.pop();

	    if((NULL == node->left ) && (NULL == node->right)) continue;

	    if(NULL != node->left) q.push(node->left);
	    if(NULL != node->right) q.push(node->right);

	    TreeNode* t =  node->left;
	    node->left = node->right;
	    node->right = t;
	}
    }

    return root;
}
